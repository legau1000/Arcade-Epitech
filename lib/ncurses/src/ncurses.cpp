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

    void *Ncurses::createAsset(const std::string &path) // To Do
    {
        // char 
        // char *str = path.substr();
    }

    void Ncurses::drawAsset(void *sprite, int x, int y)
    {
        mvprintw(y, x, (char*)sprite);
    }

    void Ncurses::destroyAsset(void *sprite)
    {}

    void Ncurses::drawWindow()
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
        int stock = h - 92;

        return ((e_event) stock);
    }

    e_event Ncurses::catchSysButton(int h)
    {
        int stock = h - 92;

        return ((e_event) stock);
    }

    e_event Ncurses::catchSpecialEvents(int h) //To Do
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