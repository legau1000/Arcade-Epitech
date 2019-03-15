/*
** EPITECH PROJECT, 2018
** Core Arcade
** File description:
** core.hpp
*/

#include <dlfcn.h>
#include "core.hpp"

Core::Core()
{
    this->ActualGraph = nullptr;
    this->hundleGraph = nullptr;
    this->launchGraph = nullptr;
    // this->ActualGame = nullptr;
    // this->hundleGame = nullptr;
    // this->launchGame = nullptr;
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

int Core::start(int ac, char **av)
{
    if (ac != 2 || av[1] == (char *)"-h" || av[1] == (char *)"--help") {
        return (writeUsage());
    }
    load_graph(av[1]);
    if (this->launchGraph == nullptr) {
        return (84);
    }
    // ActualGraph->test();
    this->ActualGraph = this->launchGraph();
    while (1);
    // this->catchAllGame();
    // this->catchAllGame();
    return (0);
}

void Core::closeLibGraphic()
{
    dlclose(this->hundleGraph);
    this->hundleGraph = nullptr;
    this->launchGraph = nullptr;
}

void Core::load_graph(char *path)
{
    void *handle = dlopen(path, RTLD_NOW);

    if (!handle) {
        std::cout << dlerror() << std::endl;
        return;
    }
    if (this->launchGraph != nullptr)
        closeLibGraphic();
    this->hundleGraph = handle;
    this->launchGraph = reinterpret_cast<displayModule::IDisplayModule* (*)()>(dlsym(this->hundleGraph, "allocator"));
    if (this->launchGraph == nullptr)
        closeLibGraphic();
}