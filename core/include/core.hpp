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
#include "stockPrint.hpp"
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
        void closeAllLib();
        void changeGraphic();
        std::string cutEndFile(const std::string &name);
        bool executeEvent(displayModule::e_event ext);

        // Launcher Core
        void initLauncher();
        void initSprite(std::string path, std::string file, std::string text, int index);
        displayModule::e_event printLauncher();

        // Change Actual Graphic Lib
        bool changeGraphic(displayModule::e_event ext);
        bool setNewGraphLib(size_t index);

        bool changeGame(displayModule::e_event ext);

        void initLib(std::string av);

        // Map for stock all game and sprite
        std::vector<mapGraphGame> _allGraphic;
        std::vector<mapGraphGame> _allGames;

        // CARE!!!!!!! 2 class !!! une suffit!!!!! template!

        // Struct for load Graphic Lib
        LoadGraph<displayModule::IDisplayModule> _graph;

        // Struct for load Games Lib
        loadGame<gameModule::IGameModule> _games;

        // Actual Graphic Lib
        std::shared_ptr<displayModule::IDisplayModule> _ActualGraph;

        // Actual Game Lib
        std::shared_ptr<gameModule::IGameModule> _ActualGame;

        // Vector sprite launcher
        std::vector<stockPrint> _allLauncherSprite;

};

#endif
