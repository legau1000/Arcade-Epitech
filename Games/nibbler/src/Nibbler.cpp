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
    this->pos_apple.push_back(23);
    this->pos_apple.push_back(35);
    this->pos_apple.push_back(103);
    this->pos_apple.push_back(115);

    this->nbApples = 4;

    this->nibbler.insert(std::make_pair(187, "P"));
    this->nibbler.insert(std::make_pair(188, "*"));
    this->nibbler.insert(std::make_pair(189, "*"));
    this->nibbler.insert(std::make_pair(190, "*"));
}

gameModule::Nibbler::~Nibbler()
{
}

displayModule::e_event gameModule::Nibbler::game()
{
    displayModule::IDisplayModule *yolo = new displayModule::Caca();
    std::fstream file("../assets/1d/map1.txt");
    std::unordered_map <int, std::string>::iterator itr;
    int i = 0;

    if (!file.is_open())
        exit(84);
    getline(file, this->map, '\0');
    file.close();

    // DISPLAY
    yolo->createText(this->map, "Oui");
    
    while (1) {
        yolo->drawAsset("Oui", 0, 0);
        for (i = 0; this->pos_apple[i]; i++) {
            yolo->createText("x", "apple" + i);
            yolo->drawText("apple" + i, this->pos_apple[i] % 20, this->pos_apple[i] / 20);
        }
        i = 0;
        for (itr = this->nibbler.begin(); itr != this->nibbler.end(); itr++) {
            yolo->createText(itr->second, "nibbler" + i);
            yolo->drawText("nibbler" + i, itr->first % 20, itr->first / 20);
            i++;
        }
        yolo->refreshWindow();
        this->catchNibblerEvent(yolo->catchEvent());
        if (this->ev_nibbler == displayModule::e_event::ESCAPE)
            break;
    }
    yolo->refreshWindow();
    return (displayModule::e_event::ESCAPE);
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
    // if (this->map[newPos] == ' ') {

    // } else if (this->map[newPos] == 'x') {
        
    // }
}

displayModule::e_event gameModule::Nibbler::catchNibblerEvent(displayModule::e_event event)
{
    this->ev_nibbler = event;
    if (this->ev_nibbler == displayModule::e_event::ESCAPE)
        return (displayModule::e_event::ESCAPE);
}