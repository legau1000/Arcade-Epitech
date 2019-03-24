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
#include "IGameModule.hpp"

namespace gameModule
{
    class Nibbler : virtual IGameModule
    {
        public:
            Nibbler();
            ~Nibbler();

            displayModule::e_event game();
            bool initGame(std::shared_ptr<displayModule::IDisplayModule> asset);
            bool setLib(std::shared_ptr<displayModule::IDisplayModule> asset);

            void drawElements(displayModule::IDisplayModule *);
            displayModule::e_event catchNibblerEvent(displayModule::e_event event);
            void move_nibbler(int x, int y);
            void addApple(void);
        protected:
        private:
            std::vector<std::string> map;
            std::vector<std::pair<int, int>> nibbler;
            displayModule::e_event ev_nibbler;
            std::pair<int, int> pos_apple;
            bool isQuit = false;
            int score;
            int nbApples;
    };
}

#endif //OOP_ARCADE_2018_NIBBLER_HPP