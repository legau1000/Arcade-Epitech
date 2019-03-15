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
        this->dp = caca_create_display(NULL);
        if(!dp)
            return;
        // this->cv = caca_get_canvas(this->dp);
        caca_set_display_title(this->dp, "Hello!");
        // caca_set_color_ansi(this->cv, CACA_BLACK, CACA_WHITE);
        // caca_put_str(this->cv, 0, 0, "This is a message");
        caca_refresh_display(this->dp);
    }

    Caca::~Caca()
    {
        caca_free_display(this->dp);
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

        if (!asset[0])
            return (false);
        // mvprintw(y, x, asset.data());
        this->cv = caca_get_canvas(this->dp);
        caca_set_color_ansi(this->cv, CACA_BLACK, CACA_WHITE);
        caca_put_str(this->cv, 0, 0, asset.data());
        return (true);
    }

    void Caca::refreshWindow()
    {
        caca_refresh_display(this->dp);
    }

    e_event Caca::catchLetterEvents(int h)
    {
        int stock = h - 92;

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
            // PAS DE SPACE
            // case 32 : return (e_event::SPACE);
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
        //caca_get_event(dp, CACA_EVENT_KEY_PRESS, &ev, -1) == 1
        int h = caca_get_event_key_ch(&this->ev);

        if (h == CACA_KEY_UNKNOWN)
            return (NOTHING);
        else if (h >= CACA_KEY_CTRL_A && h <= CACA_KEY_CTRL_G 
        || h >= CACA_KEY_CTRL_J && h <= CACA_KEY_CTRL_L
        || h >= CACA_KEY_CTRL_N && h <= CACA_KEY_CTRL_R
        || h >= CACA_KEY_CTRL_T && h <= CACA_KEY_CTRL_Z)
            return (this->catchLetterEvents(h));
        else
            return (this->catchSpecialEvents(h));
    }

    void Caca::start_sound()
    {}

    void Caca::stop_sound()
    {}
}