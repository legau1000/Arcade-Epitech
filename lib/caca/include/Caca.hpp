/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Caca
*/

#ifndef CACA_HPP_
    #define CACA_HPP_

    #include <bits/stdc++.h>
    #include <fstream>
    #include <caca.h>
    #include "IDisplayModule.hpp"

namespace displayModule
{
    class Caca : public IDisplayModule {
        public:
            Caca();
            ~Caca();

            // Sprites
            bool createAsset(const std::string &path, const std::string &assetName);
            bool drawAsset(const std::string &assetName, int x, int y);
            bool drawText(const std::string &textName, int x, int y);
            void refreshWindow();

            // Text
            bool createText(const std::string &text, const std::string &assetName);

            // Set Position
            //void setAssetPosition(Asset &asset, int x, int y);

            // Events
            e_event catchEvent();

            // Sounds
            void start_sound();
            void stop_sound();
        protected:
        private:
            caca_canvas_t *cv;
            caca_display_t *dp;
            caca_event_t ev;
            std::unordered_map<std::string, std::string> sprites;
            e_event catchLetterEvents(int h);
            e_event catchSpecialEvents(int h);
            e_event catchArrow(int h);
            e_event catchSysButton(int h);
            std::string cutEndFile(const std::string &name);
    };
}

#endif /* !CACA_HPP_ */

