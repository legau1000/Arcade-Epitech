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
#include <vector>
#include "IDisplayModule.hpp"
#include "IGameModule.hpp"
#include "loadGraphic.hpp"
#include "loadGame.hpp"
#include "mapGraphGame.hpp"
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
        void catchAllLib(const std::string &directory);
        void startGame();
        void executeEvent(displayModule::e_event ext);
        void closeAllLib();
        std::string cutEndFile(const std::string &name);

        // Map for stock all game and sprite
        std::vector<mapGraphGame> _allGraphic;
        std::vector<mapGraphGame> _allGames;

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
