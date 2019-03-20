/*
** EPITECH PROJECT, 2018
** Core Arcade
** File description:
** LoadGraph.cpp
*/

#include "loadLuncher.hpp"

loadLauncher::loadLauncher()
{}

loadLauncher::~loadLauncher()
{}

void loadLauncher::initLaunch(const std::unordered_map<std::string, std::string> allGraphic, 
                const std::unordered_map<std::string, std::string> allGames,
                const std::shared_ptr<displayModule::IDisplayModule> ActualGraph)
{
    this->_allGraphic = allGraphic;
    this->_allGames = allGames;
    this->_ActualGraph = ActualGraph;
};

void loadLauncher::loadAssets()
{
    // this->_ActualGraph->createAsset("core/assets", "core.png");
}

displayModule::e_event loadLauncher::start()
{
    this->loadAssets();
    // this->_ActualGraph->drawAsset("core", 10, 10);
    // this->_ActualGraph->refreshWindow();
    while (1);
};