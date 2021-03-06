/*
** EPITECH PROJECT, 2019
** pool
** File description:
** Ncurses
*/

#include "Ncurses.hpp"

namespace displayModule
{
    Ncurses::Ncurses()
    {
        clear();
        initscr();
        keypad(stdscr, TRUE);
        nodelay(stdscr, true);
        noecho();
        curs_set(0);
    }

    Ncurses::~Ncurses()
    {
        endwin();
    }
    
    std::string Ncurses::cutEndFile(const std::string &name)
    {
        std::size_t pos = name.find(".");

        if (pos == std::string::npos)
            return (name);
        return (name.substr(0, pos));
    }

    bool Ncurses::createAsset(const std::string &path, const std::string &assetKey)
    {
        std::fstream file(path + "/1d/" + assetKey + ".txt", std::fstream::in);
        std::string content;

        if (file.is_open())
            getline(file, content, '\0');
        else
            return (false);
        file.close();
        sprites.emplace(assetKey, content);
        return (true);
    }

    bool Ncurses::createText(const std::string &text, const std::string &assetKey)
    {
        if (this->sprites.find(assetKey) != this->sprites.end())
            this->sprites[assetKey] = text;
        else
            sprites.emplace(assetKey, text);
        return (true);
    }

    bool Ncurses::drawText(const std::string &textName, int x, int y)
    {
        this->drawAsset(textName, x, y);
    }

    bool Ncurses::drawAsset(const std::string &assetKey, int x, int y)
    {
        std::string asset = sprites[assetKey];
        size_t index = 0;
        char print[2];
        int stock_x = x;

        if (!asset[0]) {
            return (false);
        }
        print[1] = '\0';
        while (asset.data()[index]) {
            print[0] = asset.data()[index];
            mvprintw(y, x, print);
            x++;
            index++;
            if (asset.data()[index] == '\n') {
                y++;
                x = stock_x;
                index++;
            }
        }
        return (true);
    }

    void Ncurses::refreshWindow()
    {
        refresh();
    }
    
    void Ncurses::clearScreen()
    {
        clear();
    }

    e_event Ncurses::catchLetterEvents(int h)
    {
        int stock = h - 92;

        return ((e_event) stock);
    }

    e_event Ncurses::catchArrow(int h)
    {
        switch (h) {
            case KEY_RIGHT : return (e_event::ARROW_RIGHT);
            case KEY_LEFT : return (e_event::ARROW_LEFT);
            case KEY_UP : return (e_event::ARROW_UP);
            case KEY_DOWN : return (e_event::ARROW_DOWN);
            default:break;
        }
        return (NOTHING);
    }

    e_event Ncurses::catchSysButton(int h)
    {
        switch (h) {
            case 32 : return (e_event::SPACE);
            case 10 : return (e_event::ENTER);
            case 27 : return (e_event::ESCAPE);
            default:break;
        }
        return (NOTHING);
    }

    e_event Ncurses::catchSpecialEvents(int h)
    {
        e_event arrow = catchArrow(h);

        if (arrow != NOTHING)
            return (arrow);
        else
            return (catchSysButton(h));
    }

    e_event Ncurses::catchEvent()
    {
        int h = getch();

        if (h == ERR)
            return (NOTHING);
        else if (h > 96 && h < 123)
            return (this->catchLetterEvents(h));
        else
            return (this->catchSpecialEvents(h));
    }

    void Ncurses::createSound(const std::string &path, const std::string &soundKey)
    {}

    void Ncurses::startSound(const std::string &soundKey)
    {}

    void Ncurses::stopSound(const std::string &soundKey)
    {}

    extern "C"
    {
        std::shared_ptr<IDisplayModule> allocator()
        {
            return std::make_shared<Ncurses>();
        }
    }
}