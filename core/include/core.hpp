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
#include <bits/stdc++.h>
#include "IDisplayModule.hpp"
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
        void openLibGraphic(char *path);
        void closeLibGraphic();
        int writeUsage();
        void catchAllGraph();
        void Core::catchAllGame();
        std::string cutEndFile(const std::string &name);

        // Map for stock all game and sprite
        std::unordered_map<std::string, std::string> Graphic;
        std::unordered_map<std::string, std::string> Games;

        // Stop the actual graphic Lib
        void *hundleGraph;
        displayModule::IDisplayModule *(*launchGraph)();
        displayModule::IDisplayModule *ActualGraph;

        // Stop the actual Game Lib
        // void *hundleGame;
        // std::unique_ptr<gameModule::IGameModule> ActualGame;

        // A voir pk unique PTR marche pas
        // std::unique_ptr<displayModule::IDisplayModule> ActualGraph;
        // std::unique_ptr<gameModule::IGameModule> ActualGame;

};

#endif
