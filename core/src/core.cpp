/*
** EPITECH PROJECT, 2018
** Core Arcade
** File description:
** core.hpp
*/

#include <dlfcn.h>
#include <dirent.h>
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
    if (load_graph(av[1]) == 84)
        return (84);
    this->catchAllGraph();
    this->catchAllGame();
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
    struct dirent *file;
    std::string name;
 
    if (rep) {
        file = readdir(rep);
        while (file) {
            name = file->d_name;
            if (name.find(".so\0") != std::string::npos) {
                this->Graphic.insert(make_pair(cutEndFile(file->d_name), ("./lib/" + name)));
                printf("%s\n", file->d_name);
            }
            file = readdir(rep);
        }
        closedir(rep);
    }
}

void Core::catchAllGame()
{
    DIR * rep = opendir("./games/");
    struct dirent *file;
    std::string name;
 
    if (rep) {
        file = readdir(rep);
        while (file) {
            name = file->d_name;
            if (name.find(".so\0") != std::string::npos) {
                this->Games.insert(make_pair(cutEndFile(file->d_name), ("./lib/" + name)));
                printf("%s\n", file->d_name);
            }
            file = readdir(rep);
        }
        closedir(rep);
    }
}

void Core::closeLibGraphic()
{
    dlclose(this->hundleGraph);
    this->hundleGraph = nullptr;
    this->launchGraph = nullptr;
}

void Core::openLibGraphic(char *path)
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

int Core::load_graph(char *path)
{
    openLibGraphic(path);
    if (this->launchGraph == nullptr) {
        return (84);
    }
    this->ActualGraph = this->launchGraph();
    return (0);
}