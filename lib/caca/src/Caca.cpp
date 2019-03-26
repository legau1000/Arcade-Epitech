/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Caca
*/

#include "Caca.hpp"

namespace displayModule
{
    Caca::Caca()
    {
        this->cv = caca_create_canvas(1920, 1080);
        this->dp = caca_create_display(this->cv);
        if(!dp)
            return;
        caca_set_display_title(this->dp, "Hello!");
        caca_refresh_display(this->dp);
    }

    Caca::~Caca()
    {
        caca_free_display(this->dp);
        caca_free_canvas(this->cv);
    }
    
    std::string Caca::cutEndFile(const std::string &name)
    {
        std::size_t pos = name.find(".");

        if (pos == std::string::npos)
            return (name);
        return (name.substr(0, pos));
    }

    bool Caca::createAsset(const std::string &path, const std::string &assetKey)
    {
        std::fstream file(path + "/1d/" + assetKey + ".txt", std::fstream::in);
        std::string content;

        if (file.is_open())
            getline(file, content, '\0');
        else
            return (false);
        file.close();
        sprites.insert(make_pair(assetKey, content));
        return (true);
    }

    bool Caca::createText(const std::string &text, const std::string &assetKey)
    {
        sprites.insert(make_pair(assetKey, text));
        return (true);
    }

    bool Caca::drawText(const std::string &textName, int x, int y)
    {
        this->drawAsset(textName, x, y);
    }

    bool Caca::drawAsset(const std::string &assetKey, int x, int y)
    {
        std::string asset = sprites[assetKey];
        size_t index = 0;
        char print[2];
        int stock_x = x;

        if (!asset[0])
            return (false);
        print[1] = '\0';
        while (asset.data()[index]) {
            print[0] = asset.data()[index];
            this->cv = caca_get_canvas(this->dp);
            caca_set_color_ansi(this->cv, CACA_WHITE, CACA_BLACK);
            caca_put_str(this->cv, x, y, print);
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

    void Caca::refreshWindow()
    {
        caca_refresh_display(this->dp);
    }

    void Caca::clearScreen()
    {
        caca_clear_canvas(this->cv);
    }

    e_event Caca::catchLetterEvents(int h)
    {
        int stock = h;
        
        if (h >= 65 && h <= 90) {
            stock = stock - 60;
        } else if (h >= 97 && h <= 122) {
            stock = stock - 92;
        }
        else
            return (e_event::NOTHING);
        return ((e_event) stock);
    }

    e_event Caca::catchArrow(int h)
    {
        switch (h) {
            case CACA_KEY_RIGHT : return (e_event::ARROW_RIGHT);
            case CACA_KEY_LEFT : return (e_event::ARROW_LEFT);
            case CACA_KEY_UP : return (e_event::ARROW_UP);
            case CACA_KEY_DOWN : return (e_event::ARROW_DOWN);
            default:break;
        }
        return (NOTHING);
    }

    e_event Caca::catchSysButton(int h)
    {
        switch (h) {
            case 32 : return (e_event::SPACE);
            case CACA_KEY_RETURN : return (e_event::ENTER);
            case CACA_KEY_ESCAPE : return (e_event::ESCAPE);
            default:break;
        }
        return (NOTHING);
    }

    e_event Caca::catchSpecialEvents(int h)
    {
        e_event arrow = catchArrow(h);

        if (arrow != NOTHING)
            return (arrow);
        else
            return (catchSysButton(h));
    }

    e_event Caca::catchEvent()
    {
        int isKeyPressed = caca_get_event(dp, CACA_EVENT_KEY_PRESS, &this->ev, -1);
        int h;
        
        if (isKeyPressed != 1)
            return (NOTHING);        
        h = caca_get_event_key_ch(&this->ev);
        if (h == CACA_KEY_UNKNOWN)
            return (NOTHING);
        else if ((h >= 65 && h <= 90) || (h >= 97 && h <= 122))
            return (this->catchLetterEvents(h));
        else
            return (this->catchSpecialEvents(h));
    }

    void Caca::createSound(const std::string &path, const std::string &soundKey)
    {}

    void Caca::startSound(const std::string &soundKey)
    {}

    void Caca::stopSound(const std::string &soundKey)
    {}

    extern "C"
    {
        Caca *allocator()
        {
            return new Caca();
        }

        void deleter(Caca *ptr)
        {
            delete  ptr;
        }
    }
}