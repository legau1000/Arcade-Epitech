/*
** EPITECH PROJECT, 2019
** pool
** File description:
** Ncurses
*/

#ifndef NCURSES_HPP_
#define NCURSES_HPP_

#include <ncurses.h>
#include <fstream>
#include <bits/stdc++.h>
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
            bool createAsset(const std::string &path, const std::string &assetName);
            bool drawAsset(const std::string &assetName, int x, int y);
            bool drawText(const std::string &textName, int x, int y);
            void refreshWindow();

            // Create Text
            bool createText(const std::string &text, const std::string &assetName);

            // Events
            e_event catchEvent();

            // Sounds
            void start_sound();
            void stop_sound();

        protected:
        private:
            std::unordered_map<std::string, std::string> sprites;
            e_event catchLetterEvents(int h);
            e_event catchSpecialEvents(int h);
            e_event catchArrow(int h);
            e_event catchSysButton(int h);
            std::string cutEndFile(const std::string &name);

    };
}

#endif /* !NCURSES_HPP_ */
