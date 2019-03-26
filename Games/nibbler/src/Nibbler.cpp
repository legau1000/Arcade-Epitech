/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Nibbler
*/

#include <fstream>
#include "Caca.hpp"
#include "Nibbler.hpp"

#define RAND_MAX 18

gameModule::Nibbler::Nibbler()
{
    this->nbApples = 0;

    this->nibbler.push_back(std::make_pair(7, 9));
    this->nibbler.push_back(std::make_pair(8, 9));
    this->nibbler.push_back(std::make_pair(9, 9));
    this->nibbler.push_back(std::make_pair(10, 9));
}

gameModule::Nibbler::~Nibbler()
{
}

void gameModule::Nibbler::drawElements(displayModule::IDisplayModule *yolo)
{
    int i = 0;

    yolo->drawAsset("Map", 0, 0);

    yolo->createText("x", "Apple");
    yolo->drawText("Apple", this->pos_apple.first, this->pos_apple.second);
    for (i = 0; i != this->nibbler.size; i++) {
        if (i == 0)
            yolo->createText("P", "nibbler" + i);
        else
            yolo->createText("*", "nibbler" + i);
        yolo->drawText("nibbler" + i, this->nibbler[i].first, this->nibbler[i].second);
    }
    yolo->refreshWindow();
}

void gameModule::Nibbler::addApple()
{
    int x = 0;
    int y = 0;

    while (map[y][x] != ' ') {
        x = std::rand();
        y = std::rand();
    }
    this->pos_apple = std::make_pair(x, y);
}

displayModule::e_event gameModule::Nibbler::game()
{
    displayModule::IDisplayModule *yolo = new displayModule::Caca();
    std::fstream file("../assets/1d/map1.txt");
    int i = 0;

    if (!file.is_open())
        exit(84);
    while (getline(file, this->map[i], '\n')) {
        yolo->createText(this->map[i], "Map" + i);
        i++;
    }
    file.close();

    while (!this->isQuit) {
        if (this->nbApples == 0)
            this->addApple();
        this->drawElements(yolo);
        this->catchNibblerEvent(yolo->catchEvent());
        if ((this->ev_nibbler == displayModule::e_event::ERROR) ||
        (this->ev_nibbler == displayModule::e_event::ESCAPE) ||
        ((this->ev_nibbler >= displayModule::e_event::ARROW_UP) && (this->ev_nibbler <= displayModule::e_event::ARROW_LEFT)))
            return (this->ev_nibbler);
    }
    return (this->ev_nibbler);
}

bool gameModule::Nibbler::initGame(std::shared_ptr<displayModule::IDisplayModule> asset)
{

}

bool gameModule::Nibbler::setLib(std::shared_ptr<displayModule::IDisplayModule> asset)
{

}

void gameModule::Nibbler::move_nibbler(int x, int y)
{
    bool isApple = false;
    auto tmp = this->nibbler[0];
    auto newTmp = std::make_pair(x, y);
    int i = 0;
    
    for (i = 0; i < this->nibbler.size; i++) {
        if (this->nibbler[i].first == x && this->nibbler[i].second == y)
            exit(84);
    }
    if (x == this->pos_apple.first && y == this->pos_apple.second) {
        this->nbApples = 0;
        this->score++;
        while (i < nibbler.size()) {
            tmp = this->nibbler[i];
            this->nibbler[i] = newTmp;
            newTmp = tmp;
            i++;
        }
        this->nibbler.push_back(tmp);
    } else if (this->map[y][x] == '#') {
        exit(84);
    } else if (this->map[y][x] == ' ') {
        while (i < nibbler.size()) {
            this->nibbler[i] = newTmp;
            newTmp = tmp;
            i++;
            tmp = this->nibbler[i];
        }
    }
}

displayModule::e_event gameModule::Nibbler::catchNibblerEvent(displayModule::e_event event)
{
    this->ev_nibbler = event;

    if (this->ev_nibbler == displayModule::e_event::KEY_Z)
        this->move_nibbler(this->nibbler[0].first, this->nibbler[0].second - 1);
    else if (this->ev_nibbler == displayModule::e_event::KEY_Q)
        this->move_nibbler(this->nibbler[0].first - 1, this->nibbler[0].second);
    else if (this->ev_nibbler == displayModule::e_event::KEY_D)
        this->move_nibbler(this->nibbler[0].first + 1, this->nibbler[0].second);
    else if (this->ev_nibbler == displayModule::e_event::KEY_S)
        this->move_nibbler(this->nibbler[0].first, this->nibbler[0].second + 1);
    return (this->ev_nibbler);
}