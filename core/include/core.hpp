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
#include "IGameModule.hpp"
#include "loadGraphic.hpp"
#include "loadGame.hpp"
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
        void startGame();
        std::string cutEndFile(const std::string &name);

        // Map for stock all game and sprite
        std::unordered_map<std::string, std::string> _allGraphic;
        std::unordered_map<std::string, std::string> _allGames;

        // Struct for load Graphic Lib
        LoadGraph<displayModule::IDisplayModule> _graph;

        // Struct for load Games Lib
        LoadGraph<gameModule::IGameModule> _games;

        // Actual Graphic Lib
        std::shared_ptr<displayModule::IDisplayModule> _ActualGraph;

        // Actual Game Lib
        std::unique_ptr<gameModule::IGameModule> _ActualGame;
 
};

#endif
