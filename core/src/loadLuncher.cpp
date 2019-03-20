/*
** EPITECH PROJECT, 2018
** Core Arcade
** File description:
** LoadGraph.cpp
*/

#include "loadLuncher.hpp"

loadLauncher::loadLauncher()
{
    this->_ActualGraph = nullptr;
}

loadLauncher::~loadLauncher()
{}

void loadLauncher::initLaunch(std::vector<mapGraphGame> allGraphic, 
                std::vector<mapGraphGame> allGames,
                std::shared_ptr<displayModule::IDisplayModule> ActualGraph)
{
    this->_ActualGraph = ActualGraph;
    // this->_ActualGraph->createText(allGraphic[0].GetName(), "VERIF");
    // this->_allGraphic = allGraphic;
    // this->_allGames = allGames;
};

void loadLauncher::loadAssets()
{
    // this->_ActualGraph->createAsset("core/assets", "core.png");
}

displayModule::e_event loadLauncher::start()
{
    this->loadAssets();
    this->_ActualGraph->drawText("VERIF", 10, 10);
    this->_ActualGraph->refreshWindow();
    while (1);
};