/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** my
*/

#ifndef NIBBLER_HPP_
# define NIBBLER_HPP_

#include <iostream>
#include <memory>
#include <vector>
#include <unordered_map>
#include "IDisplayModule.hpp"

namespace gameModule
{
    class Nibbler
    {
        public:
            Nibbler();
            ~Nibbler();

            displayModule::e_event game();
            bool initGame(std::shared_ptr<displayModule::IDisplayModule> asset);
            bool setLib(std::shared_ptr<displayModule::IDisplayModule> asset);

            void drawElements(displayModule::IDisplayModule *);
            void count_apple(void);
            displayModule::e_event catchNibblerEvent(displayModule::e_event event);
            void move_nibbler(int newPos);
        protected:
        private:
            std::string map;
            std::vector<int> pos_apple;
            std::vector<int> nibbler;
            displayModule::e_event ev_nibbler;
            bool isQuit = false;
            int score;
            int pos;
            int nbApples;
    };
}

#endif //OOP_ARCADE_2018_NIBBLER_HPP