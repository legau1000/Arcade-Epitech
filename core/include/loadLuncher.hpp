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
#include <unordered_map>
#include "IDisplayModule.hpp"

class loadLauncher
{
    public:
        loadLauncher() {};
        ~loadLauncher() {};
        void initLaunch(const std::unordered_map<std::string, std::string>&,
                        const std::unordered_map<std::string, std::string>&,
                        const std::shared_ptr<displayModule::IDisplayModule>&);
        displayModule::e_event start();

    protected:

    private:
        // Map for stock all game and sprite
        std::unordered_map<std::string, std::string> _allGraphic;
        std::unordered_map<std::string, std::string> _allGames;

        // Actual Graphic Lib
        std::shared_ptr<displayModule::IDisplayModule> _ActualGraph;
};

#endif