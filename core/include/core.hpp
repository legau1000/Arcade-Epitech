/*
** EPITECH PROJECT, 2018
** Core Arcade
** File description:
** core.hpp
*/

#ifndef CORE_HPP__
#define CORE_HPP__

#include <string>
#include <iostream>
#include <map>
#include <memory>
#include "IDisplayModule.hpp"

class Core
{
    public:
        Core(int ac, char **av);
        ~Core();

        int start();

    protected:

    private:
        std::map<std::string, std::string> *Games;
        std::map<std::string, std::string> *Graphic;
        std::unique_ptr<displayModule::IDisplayModule> ActualGraph;
        // std::unique_ptr<gameModule::IGameModule> ActualGame;

};

#endif
