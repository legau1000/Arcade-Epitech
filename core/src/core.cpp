/*
** EPITECH PROJECT, 2018
** Core Arcade
** File description:
** core.cpp
*/

#include "core.hpp"

Core::Core()
{
    //this->_ActualGame = nullptr;
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

bool Core::setNewGraphLib(size_t index)
{
    this->_allGraphic[index].SetUse(true);
    this->_ActualGraph = nullptr;
    this->_ActualGraph = _graph.loadNewLib(this->_allGraphic[index].GetPath());
    if (this->_ActualGraph == nullptr)
        return (true);
    if (this->_ActualGame == nullptr)
    {
        this->initLauncher();
    }
    else
    {
    }
    return (false);
}

bool Core::changeGraphic(displayModule::e_event ext)
{
    size_t index = 0;

    while (this->_allGraphic[index].GetUse() != true)
        index++;
    this->_allGraphic[index].SetUse(false);
    if (ext == displayModule::ARROW_LEFT)
    {
        if (index == 0)
        {
            index = this->_allGraphic.size() - 1;
        }
        else
            index = index - 1;
    }
    else
        index = (index + 1) % (this->_allGraphic.size());
    return (this->setNewGraphLib(index));
}

bool Core::changeGame(displayModule::e_event ext)
{
    if (this->_ActualGame == nullptr)
    {
    }
    else
    {
    }
    return (false);
}

bool Core::executeEvent(displayModule::e_event ext)
{
    if (ext == displayModule::ENTER)
    {
        this->_ActualGame = nullptr;
    }
    if (ext == displayModule::ARROW_LEFT ||
        ext == displayModule::ARROW_RIGHT)
    {
        return (this->changeGraphic(ext));
    }
    if (ext == displayModule::ARROW_UP ||
        ext == displayModule::ARROW_DOWN)
    {
        return (this->changeGame(ext));
    }
    if (ext == displayModule::KEY_A)
    {
        printf("TEST\n");
        this->_allGames[0].SetUse(true);
        this->_ActualGame = nullptr;
        this->_ActualGame = this->_games.loadNewLib(this->_allGames[0].GetPath());
        if (this->_ActualGame == nullptr)
            return (true);
        printf("%s\n", this->_allGames[0].GetPath().data());
        printf("TEST2\n");
        this->_ActualGame->initGame(this->_ActualGraph);
        printf("TEST3\n");
    }
    return (false);
}
displayModule::e_event Core::printLauncher()
{
    this->_ActualGraph->drawText("VERIF", 10, 10);
    this->_ActualGraph->refreshWindow();
    return (this->_ActualGraph->catchEvent());
}

void Core::initLauncher()
{
    this->_ActualGraph->createText("TEST T MORT!", "VERIF");
}

void Core::startGame()
{
    displayModule::e_event ext = displayModule::NOTHING;

    this->initLauncher();
    while (ext != displayModule::ESCAPE)
    {
        if (this->_ActualGame == nullptr)
        {
            ext = this->printLauncher();
        }
        else
        {
            ext = this->_ActualGame->game();
        }
        // ext = this->_ActualGraph->catchEvent();
        if (ext != displayModule::NOTHING)
        {
            if (this->executeEvent(ext) == true)
                return;
        }
    }
}

void Core::initLib(std::string av)
{
    size_t index = 0;

    if (av[0] != '.' || av[1] != '/')
        av = "./" + av;
    while (av != this->_allGraphic[index].GetPath() &&
           av != this->_allGraphic[index].GetPath())
    {
        index++;
    }
    this->_allGraphic[index].SetUse(true);
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
    this->initLib(av[1]);
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
    DIR *rep = opendir(directory.data());
    struct dirent *file = nullptr;
    std::string name;

    if (rep)
    {
        file = readdir(rep);
        while (file)
        {
            name = file->d_name;
            if (name.find(".so\0") != std::string::npos)
            {
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