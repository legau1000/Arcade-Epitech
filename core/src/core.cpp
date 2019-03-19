/*
** EPITECH PROJECT, 2018
** Core Arcade
** File description:
** core.cpp
*/

#include "core.hpp"

Core::Core()
{}

Core::~Core()
{
    std::cout << "Good Bye and see you later my friend!" << std::endl;
}

int Core::writeUsage()
{
    std::cout << DRAW_USAGE << std::endl;
    return (0);
}

void Core::startMenu()
{
    this->_ActualGraph->createText("####\n#  #\n#  #\n####", "Snake");
    this->_ActualGraph->drawText("Snake", 10, 10);
    this->_ActualGraph->refreshWindow();
    while (1);
}

int Core::start(int ac, char **av)
{
    if (ac != 2 || av[1] == (char *)"-h" || av[1] == (char *)"--help")
        return (writeUsage());
    this->_ActualGraph = _graph.loadNewLib(av[1]);
    this->catchAllGraph();
    this->catchAllGame();
    this->startMenu();
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
                this->_Graphic.insert(make_pair(cutEndFile(file->d_name), ("./lib/" + name)));
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
                this->_Games.insert(make_pair(cutEndFile(file->d_name), ("./games/" + name)));
            file = readdir(rep);
        }
        closedir(rep);
    }
}