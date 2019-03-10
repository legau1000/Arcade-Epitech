/*
** EPITECH PROJECT, 2019
** pool
** File description:
** Ncurses
*/

#include <ncurses.h>
#include <curses.h>
#include <string.h>
#include <string>
#include "Ncurses.hpp"

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

e_type Ncurses::getType()
{
    return (ONE);
}

void *Ncurses::createAsset(std::string &path)
{
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

e_event Ncurses::catchEvent()
{}

void Ncurses::start_sound() 
{}

void Ncurses::stop_sound()
{}