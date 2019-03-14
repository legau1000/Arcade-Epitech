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
        std::fstream file(path + "/1d/" + assetKey, std::fstream::in);
        std::string content;
        std::string filename = this->cutEndFile(assetKey);

        if (file.is_open())
            getline(file, content, '\0');
        else
            return (false);
        file.close();
        sprites.insert(make_pair(filename, content));
        return (true);
    }

    bool Ncurses::createText(const std::string &text, const std::string &assetKey)
    {
        sprites.insert(make_pair(assetKey, text));
        return (true);
    }

    bool Ncurses::drawText(const std::string &textName, int x, int y)
    {
        this->drawAsset(textName, x, y);
    }

    bool Ncurses::drawAsset(const std::string &assetKey, int x, int y)
    {
        std::string asset = sprites[assetKey];

        if (!asset[0])
            return (false);
        mvprintw(y, x, asset.data());
        return (true);
    }

    void Ncurses::refreshWindow()
    {
        refresh();
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
            case KEY_ENTER : return (e_event::ENTER);
            case 27 : return (e_event::ESCAPE);
            default:break;
        }
        return (NOTHING);
    }

    e_event Ncurses::catchSpecialEvents(int h)
    {
        e_event arrow = catchArrow(h);

        if (arrow == NOTHING)
            return (arrow);
        else
            return (catchSysButton(h));
    }

    e_event Ncurses::catchEvent()
    {
        int h = getch();

        if (h == ERR)
            return (NOTHING);
        else if (h > 97 && h < 123)
            return (this->catchLetterEvents(h));
        else
            return (this->catchSpecialEvents(h));
    }

    void Ncurses::start_sound()
    {}

    void Ncurses::stop_sound()
    {}
}