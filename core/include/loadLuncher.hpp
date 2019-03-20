/*
** EPITECH PROJECT, 2018
** Core Arcade
** File description:
** LoadGraph.hpp
*/

#ifndef LOADLAUNCHER_HPP__
#define LOADLAUNCHER_HPP__

#include <map>
#include <memory>
#include <vector>
#include "mapGraphGame.hpp"
#include "IDisplayModule.hpp"

class loadLauncher
{
    public:
        loadLauncher();
        ~loadLauncher();
        void initLaunch(std::vector<mapGraphGame>,
                        std::vector<mapGraphGame>,
                        std::shared_ptr<displayModule::IDisplayModule>);
        displayModule::e_event start();
        void loadAssets();

    protected:

    private:
        // Map for stock all game and sprite
        std::vector<mapGraphGame> *_allGraphic;
        // std::vector<mapGraphGame> _allGames;

        // Actual Graphic Lib
        std::shared_ptr<displayModule::IDisplayModule> _ActualGraph;
};

#endif