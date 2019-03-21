/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Nibbler
*/

#include <fstream>
#include "Caca.hpp"
#include "Nibbler.hpp"

gameModule::Nibbler::Nibbler()
{
    this->pos_apple.push_back(25);
    this->pos_apple.push_back(35);
    this->pos_apple.push_back(103);
    this->pos_apple.push_back(115);

    this->nbApples = 4;

    this->nibbler.push_back(187);
    this->nibbler.push_back(188);
    this->nibbler.push_back(189);
    this->nibbler.push_back(190);

    this->pos = 187;
}

gameModule::Nibbler::~Nibbler()
{
}

displayModule::e_event gameModule::Nibbler::game()
{
    displayModule::IDisplayModule *yolo = new displayModule::Caca();
    std::fstream file("../assets/1d/map1.txt");
    int i = 0;

    if (!file.is_open())
        exit(84);
    getline(file, this->map, '\0');
    file.close();

    // DISPLAY
    yolo->createText(this->map, "Oui");
    
    while (!this->isQuit && this->nbApples != 0) {
        yolo->drawAsset("Oui", 0, 0);
        for (i = 0; this->pos_apple[i]; i++) {
            yolo->createText("x", "apple" + i);
            yolo->drawText("apple" + i, this->pos_apple[i] % 20, this->pos_apple[i] / 20);
        }
        for (i = 0; this->nibbler[i]; i++) {
            if (i == 0)
                yolo->createText("P", "nibbler" + i); // T'EN ETAIS LA CONNARD
            else
                yolo->createText("*", "nibbler" + i);
            yolo->drawText("nibbler" + i, this->nibbler[i] % 20, this->nibbler[i] / 20);
        }
        yolo->refreshWindow();
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

void gameModule::Nibbler::count_apple(void)
{

}

void gameModule::Nibbler::move_nibbler(int newPos)
{
    auto x = this->nibbler.end();
    auto isApple = std::find(this->pos_apple.begin(), this->pos_apple.end(), newPos);
    int tmp = this->nibbler[0];
    int newTmp = newPos;
    int i = 0;
    
    if (isApple != this->pos_apple.end()) {
        this->pos_apple.erase(isApple);
        this->nbApples--;
        this->score++;
        while (i < nibbler.size()) {
            tmp = this->nibbler[i];
            this->nibbler[i] = newTmp;
            newTmp = tmp;
            i++;
        }
        this->nibbler.push_back(tmp);
        this->pos = this->nibbler[0];
    } else if (this->map[newPos] == ' ') {
        while (i < nibbler.size()) {
            this->nibbler[i] = newTmp;
            newTmp = tmp;
            i++;
            tmp = this->nibbler[i];
        }
        this->pos = this->nibbler[0];
    } else {
        exit(84);
    }
}

displayModule::e_event gameModule::Nibbler::catchNibblerEvent(displayModule::e_event event)
{
    this->ev_nibbler = event;

    if (this->ev_nibbler == displayModule::e_event::KEY_Z)
        this->move_nibbler(this->pos - 20);
    else if (this->ev_nibbler == displayModule::e_event::KEY_Q)
        this->move_nibbler(this->pos - 1);
    else if (this->ev_nibbler == displayModule::e_event::KEY_D)
        this->move_nibbler(this->pos + 1);
    else if (this->ev_nibbler == displayModule::e_event::KEY_S)
        this->move_nibbler(this->pos + 20);
    return (this->ev_nibbler);
}