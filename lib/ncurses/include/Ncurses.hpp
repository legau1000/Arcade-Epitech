/*
** EPITECH PROJECT, 2019
** pool
** File description:
** Ncurses
*/

#ifndef NCURSES_HPP_
#define NCURSES_HPP_

#include <ncurses.h>
#include <curses.h>
#include <string.h>
#include <string>
#include "IDisplayModule.hpp"

class Ncurses : virtual public IDisplayModule
{
    public:
        Ncurses();
        ~Ncurses();

        e_type getType();

        // Sprites
        void *createAsset(std::string &path);
        void drawAsset(void *sprite);
        void drawWindow();
        void destroyAsset(void *sprite);

        // Events
        void catchEvent();

        // Sounds
        void start_sound();
        void stop_sound();

        // void addModule(const std::string &);
        // void deleteModule(const std::string &);
        // void displayWallpaper();

    protected:
    private:
};

#endif /* !NCURSES_HPP_ */
