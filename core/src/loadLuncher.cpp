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

void loadLauncher::initLaunch(const std::unordered_map<std::string, std::string> &allGraphic, 
                const std::unordered_map<std::string, std::string> &allGames,
                const std::shared_ptr<displayModule::IDisplayModule> &ActualGraph)
{
    this->_allGraphic = allGraphic;
    this->_allGames = allGames;
    this->_ActualGraph = ActualGraph;
};

displayModule::e_event loadLauncher::start()
{
    
};