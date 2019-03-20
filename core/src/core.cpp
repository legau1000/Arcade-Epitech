/*
** EPITECH PROJECT, 2018
** Core Arcade
** File description:
** core.cpp
*/

#include "loadLuncher.hpp"
#include "core.hpp"

Core::Core()
{
    this->_ActualGame = nullptr;
}

Core::~Core()
{
    std::cout << "Good Bye and see you later my friend!" << std::endl;
}

int Core::writeUsage()
{
    std::cout << DRAW_USAGE << std::endl;
    return (0);
}

void Core::executeEvent(displayModule::e_event ext)
{
    if (ext == displayModule::ENTER) {
        this->_ActualGame = nullptr;
    }
}

void Core::startGame()
{
    displayModule::e_event ext = displayModule::NOTHING;

    this->_ActualGraph->createText(this->_allGraphic[0].GetName(), "VERIF");
    this->_ActualGraph->drawText("VERIF", 10, 10);
    this->_ActualGraph->refreshWindow();
    while (ext != displayModule::ESCAPE) {
        if (this->_ActualGame == nullptr) {
            // ext = launcher.start();
        } else {
            // ext = this->_ActualGame.game();
        }
        ext = this->_ActualGraph->catchEvent();
        if (ext != displayModule::NOTHING)
            this->executeEvent(ext);
    }
}

int Core::start(int ac, char **av)
{
    if (ac != 2 || av[1] == (char *)"-h" || av[1] == (char *)"--help")
        return (writeUsage());
    this->_ActualGraph = _graph.loadNewLib(av[1]);
    if (this->_ActualGraph == nullptr)
        return (84);
    this->catchAllLib("./lib/");
    this->catchAllLib("./Games/");
    this->startGame();
    return (0);
}

std::string Core::cutEndFile(const std::string &name)
{
    std::size_t pos = name.find(".");

    if (pos == std::string::npos)
        return (name);
    return (name.substr(0, pos));
}

void Core::catchAllLib(const std::string &directory)
{ 
    DIR * rep = opendir(directory.data());
    struct dirent *file = nullptr;
    std::string name;
 
    if (rep) {
        file = readdir(rep);
        while (file) {
            name = file->d_name;
            if (name.find(".so\0") != std::string::npos) {
                if (directory == "./Games/")
                    this->_allGames.push_back(mapGraphGame(cutEndFile(name), (directory + name)));
                else
                    this->_allGraphic.push_back(mapGraphGame(cutEndFile(name), (directory + name)));
            }
            file = readdir(rep);
        }
        closedir(rep);
    }
}