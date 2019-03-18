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
#include <unordered_map>
#include "IDisplayModule.hpp"
#include "loadGraphic.hpp"
#include "def.hpp"

class Core
{
    public:
        Core();
        ~Core();

        int start(int ac, char **av);
        int load_graph(char *lib);

    protected:

    private:
        int writeUsage();
        void catchAllGraph();
        void catchAllGame();
        void startMenu();
        std::string cutEndFile(const std::string &name);

        LoadGraph<displayModule::IDisplayModule> _graph;
        // Map for stock all game and sprite
        std::unordered_map<std::string, std::string> _Graphic;
        std::unordered_map<std::string, std::string> _Games;

        // Actual Graphic Lib
        std::shared_ptr<displayModule::IDisplayModule> _ActualGraph;

        // Stop the actual Game Lib
        // void *hundleGame;
        // std::unique_ptr<gameModule::IGameModule> ActualGame;

 
};

#endif
