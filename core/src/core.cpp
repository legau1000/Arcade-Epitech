/*
** EPITECH PROJECT, 2018
** Core Arcade
** File description:
** core.cpp
*/

#include "core.hpp"

Core::Core()
{
    this->_place = 0;
}

Core::~Core()
{
    this->_ActualGraph = nullptr;
    this->_ActualGame = nullptr;
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
    // if (this->_ActualGame == nullptr)
    //     this->_ActualGraph = nullptr;
    // this->_ActualGraph = this->_graph.loadNewLib(this->_allGraphic[index].GetPath());
    // if (this->_ActualGraph == nullptr)
    //     return (true);
    if (this->_ActualGame == nullptr) {
        this->_ActualGraph = nullptr;
        this->_ActualGraph = this->_graph.loadNewLib(this->_allGraphic[index].GetPath());
        if (this->_ActualGraph == nullptr)
            return (true);
        this->_allLauncherSprite.clear();
        this->initLauncher();
    } else {
        printf("VICTOR\n");
        this->_ActualGraph = nullptr;
        // printf("%p\n", this->_ActualGraph);
        return (!this->_ActualGame->setLib(this->_graph.loadNewLib(this->_allGraphic[index].GetPath())));
    }
    return (false);
}

bool Core::changeGraphic(displayModule::e_event ext)
{
    size_t index = 0;

    printf("new\n");
    while (this->_allGraphic[index].GetUse() != true)
        index++;
    this->_allGraphic[index].SetUse(false);
    if (ext == displayModule::ARROW_LEFT) {
        if (index == 0) {
            index = this->_allGraphic.size() - 1;
        } else
            index = index - 1;
    } else
        index = (index + 1) % (this->_allGraphic.size());
    return (this->setNewGraphLib(index));
}

void Core::moveArrow(displayModule::e_event ext)
{
    if (ext == displayModule::ARROW_UP) {
        if (this->_place != 0)
            this->_place--;
    } else {
        if ((unsigned) this->_place < this->_allGames.size() - 1)
            this->_place++;
    }
    this->_arrow->SetXY(20, 10 + (this->_place * 5));
}

bool Core::changeGame(displayModule::e_event ext)
{
    if (this->_ActualGame == nullptr) {
        this->moveArrow(ext);
        return (false);
    } else {
        // Load New Game
    }
    return (false);
}

std::string Core::GetPathGraph()
{
    size_t index = 0;

    printf("new\n");
    while (this->_allGraphic[index].GetUse() != true)
        index++;
    return (this->_allGraphic[index].GetPath());
}

bool Core::enterEvent()
{
    if (this->_ActualGame == nullptr) {
        this->_allGames[this->_place].SetUse(true);
        this->_ActualGame = this->_games.loadNewLib(this->_allGames[this->_place].GetPath());
        if (this->_ActualGame == nullptr)
            return (true);
        this->_ActualGraph = nullptr;
        this->_ActualGame->initGame(this->_graph.loadNewLib(this->GetPathGraph()));
    } else {
    }
    return (false);
}

bool Core::executeEvent(displayModule::e_event ext)
{
    if (ext == displayModule::ENTER) {
        return (this->enterEvent());
    }
    if (ext == displayModule::ARROW_LEFT ||
        ext == displayModule::ARROW_RIGHT) {
        return (this->changeGraphic(ext));
    }
    if (ext == displayModule::ARROW_UP ||
        ext == displayModule::ARROW_DOWN) {
        return (this->changeGame(ext));
    }
    return (false);
}

displayModule::e_event Core::printLauncher()
{
    std::vector<stockPrint>::iterator index = this->_allLauncherSprite.begin();
    size_t it = 0;
    int x = 0;
    int y = 0;

    this->_ActualGraph->clearScreen();
    while (index != this->_allLauncherSprite.end()) {
        x = this->_allLauncherSprite[it].GetX();
        y = this->_allLauncherSprite[it].GetY();
        if (this->_allLauncherSprite[it].GetText())
            this->_ActualGraph->drawText(this->_allLauncherSprite[it].GetName(), x, y);
        else
            this->_ActualGraph->drawAsset(this->_allLauncherSprite[it].GetName(), x, y);
        index++;
        it++;
    }
    x = this->_arrow->GetX();
    y = this->_arrow->GetY();
    this->_ActualGraph->drawAsset(this->_arrow->GetName(), x, y);
    this->_ActualGraph->refreshWindow();
    return (this->_ActualGraph->catchEvent());
}

void Core::initLauncher()
{
    int idxGames = 0;
    int set_pos = 0;
    int idx_glob = 1;
    std::vector<mapGraphGame>::iterator index = this->_allGames.begin();

    this->initSprite("./core/assets", "core", "Arcade", 0);
    while (index != this->_allGames.end()) {
        this->initSprite("./core/assets", this->_allGames[idxGames].GetName(), this->_allGames[idxGames].GetName(), idx_glob);
        this->_allLauncherSprite[idx_glob].SetXY(23, 10 + set_pos);
        set_pos += 5;
        index++;
        idxGames++;
        idx_glob++;
    }
    this->initArrow("./core/assets", "arrow", "->");
    this->_arrow->SetXY(20, 10 + (this->_place * 5));
}

void Core::initArrow(std::string path, std::string file, std::string text)
{
    this->_arrow = std::make_unique<stockPrint>(stockPrint(path, this->cutEndFile(file), 0, 0));
    if (this->_ActualGraph->createAsset(path, file) == false) {
        this->_ActualGraph->createText(text, file);
        this->_arrow->SetText(true);
    }
}

void Core::initSprite(std::string path, std::string file, std::string text, int index)
{
    this->_allLauncherSprite.push_back(stockPrint(path, this->cutEndFile(file), 0, 0));
    if (this->_ActualGraph->createAsset(path, file) == false) {
        this->_ActualGraph->createText(text, file);
        this->_allLauncherSprite[index].SetText(true);
    }
}

void Core::startGame()
{
    displayModule::e_event ext = displayModule::NOTHING;

    this->initLauncher();
    while (ext != displayModule::ESCAPE) {
        if (this->_ActualGame == nullptr) {
            ext = this->printLauncher();
        } else {
            ext = this->_ActualGame->game();
        }
        if (ext != displayModule::NOTHING) {
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
           av != this->_allGraphic[index].GetPath()) {
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
    this->catchAllLib("./games/");
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

    if (rep) {
        file = readdir(rep);
        while (file) {
            name = file->d_name;
            if (name.find(".so\0") != std::string::npos) {
                if (directory == "./games/")
                    this->_allGames.push_back(mapGraphGame(cutEndFile(name), (directory + name)));
                else
                    this->_allGraphic.push_back(mapGraphGame(cutEndFile(name), (directory + name)));
            }
            file = readdir(rep);
        }
        closedir(rep);
    }
}