/*
** EPITECH PROJECT, 2019
** pool
** File description:
** Ncurses
*/

#ifndef NCURSES_HPP_
#define NCURSES_HPP_

#include <ncurses.h>
#include "IDisplayModule.hpp"
#include "def.hpp"

namespace displayModule
{
    class Ncurses : public IDisplayModule
    {
        public:
            Ncurses();
            ~Ncurses();

            // Sprites
            void *createAsset(const std::string &path);
            void drawAsset(void *sprite, int x = 0, int y = 0);
            void drawWindow();
            void destroyAsset(void *sprite);

            // Events
            e_event catchEvent();

            // Sounds
            void start_sound();
            void stop_sound();

        protected:
        private:
            e_event catchLetterEvents(int h);
            e_event catchSpecialEvents(int h);
            e_event catchArrow(int h);
            e_event catchSysButton(int h);

    };
}

#endif /* !NCURSES_HPP_ */
