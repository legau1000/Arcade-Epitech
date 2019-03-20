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

void Core::startGame()
{
    loadLauncher launcher;
    displayModule::e_event ext = displayModule::NOTHING;

    launcher.initLaunch(this->_allGraphic, this->_allGames, this->_ActualGraph);
    while (ext != displayModule::ESCAPE) {
        if (this->_ActualGame == nullptr) {
            ext = launcher.start();
        } else {
            // this->_ActualGame.game();
        }
    }
}

int Core::start(int ac, char **av)
{
    if (ac != 2 || av[1] == (char *)"-h" || av[1] == (char *)"--help")
        return (writeUsage());
    this->_ActualGraph = _graph.loadNewLib(av[1]);
    if (this->_ActualGraph == nullptr)
        return (84);
    this->catchAllGraph();
    this->catchAllGame();
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

void Core::catchAllGraph()
{
    DIR * rep = opendir("./lib/");
    struct dirent *file = nullptr;
    std::string name;

    if (rep) {
        file = readdir(rep);
        while (file) {
            name = file->d_name;
            if (name.find(".so\0") != std::string::npos)
                this->_allGraphic.insert(make_pair(cutEndFile(file->d_name), ("./lib/" + name)));
            file = readdir(rep);
        }
        closedir(rep);
    }
}

void Core::catchAllGame()
{
    DIR * rep = opendir("./games/");
    struct dirent *file = nullptr;
    std::string name;
 
    if (rep) {
        file = readdir(rep);
        while (file) {
            name = file->d_name;
            if (name.find(".so\0") != std::string::npos)
                this->_allGames.insert(make_pair(cutEndFile(file->d_name), ("./games/" + name)));
            file = readdir(rep);
        }
        closedir(rep);
    }
}