/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Nibbler
*/

#include <fstream>
//#include "Caca.hpp"
#include "Nibbler.hpp"


namespace gameModule
{

Nibbler::Nibbler()
{
}

Nibbler::~Nibbler()
{
}

bool Nibbler::exitEvent(displayModule::e_event evt)
{
	if (evt == displayModule::e_event::KEY_L)
		return (true);
	if (evt >= 1 && evt <= 4)
		return (true);
	if (evt == displayModule::e_event::ESCAPE)
		return (true);
	return (false);
}

void Nibbler::printMap()
{
	unsigned int index = 0;
	int line = 0;

	while (index < this->_map.size())
	{
		while (this->_map[index][line])
		{
			if (this->_map[index][line] == '#')
			{
				if (this->_allNibblerSprite[3].GetText())
					this->_graph->drawText("wall", line, index);
				else
					this->_graph->drawAsset("wall", line, index);
			} else {
				if (this->_allNibblerSprite[3].GetText())
					this->_graph->drawText("empty", line, index);
				else
					this->_graph->drawAsset("empty", line, index);
			}
			line++;
		}
		line = 0;
		index++;
	}
}

void Nibbler::printPlayer()
{
    int i = 0;

    while (i < this->_Nibbler.size()) {
        if (i == 0) {
            if (this->_Nibbler[i].GetText())
                this->_graph->drawText("head", this->_Nibbler[i].GetX, this->_Nibbler[i].GetY);
            else
                this->_graph->drawAsset("head", this->_Nibbler[i].GetX, this->_Nibbler[i].GetY);
        } else {
            if (this->_Nibbler[i].GetText())
                this->_graph->drawText("body", this->_Nibbler[i].GetX, this->_Nibbler[i].GetY);
            else
                this->_graph->drawAsset("body", this->_Nibbler[i].GetX, this->_Nibbler[i].GetY);
        }
        i++;
    }
}

void Nibbler::printGame()
{
	this->printMap();
	// this->printFood();
	this->printPlayer();
	// this->printOther();
	this->_graph->refreshWindow();
}

bool Nibbler::stockMap(const std::string &path)
{
	std::fstream file(path, std::fstream::in);
	std::string content;

	if (!file.is_open())
		return (false);
	while (getline(file, content))
	{
		this->_map.push_back(content);
	}
	file.close();
	return (true);
}

void Nibbler::moveNibbler(displayModule::e_event evt)
{
	switch (evt)
	{
	case displayModule::e_event::KEY_Z:
		this->_move = TOP;
	case displayModule::e_event::KEY_S:
		this->_move = BOT;
	case displayModule::e_event::KEY_Q:
		this->_move = LEFT;
	case displayModule::e_event::KEY_D:
		this->_move = RIGHT;
	default:
		break;
	}
}

displayModule::e_event Nibbler::game()
{
	displayModule::e_event evt = displayModule::e_event::NOTHING;
	time_t t1 = time(0);
	time_t t2 = time(0);

	this->stockMap("./Games/Nibbler/map/mapEasy.txt");
	while (!this->exitEvent(evt))
	{
		if (t2 - t1 >= 0.25)
		{
			this->printGame();
			t1 = time(0);
		}
		t2 = time(0);
		evt = this->_graph->catchEvent();
		this->moveNibbler(evt);
	}
	return (evt);
}

void Nibbler::initSound()
{
	this->_graph->createSound("./Games/Nibbler/assets/Nibbler.ogg", "NibblerSound");
}

void Nibbler::startSound(const std::string &key)
{
	this->_graph->startSound(key);
}

void Nibbler::initAssets()
{
	this->initSprite("head", "0", 0);
	this->initSprite("body", "O", 0);
	this->initSprite("aubergine", "M", 0);
	this->initSprite("wall", "+", 0);
	this->initSprite("empty", " ", 0);
	this->_Nibbler.push_back(stockPrint("./Games/Nibbler/assets", "head", 1, 1));
}

void Nibbler::initSprite(std::string file, std::string text, int index)
{
	std::string path = "./Games/Nibbler/assets";

	this->_allNibblerSprite.push_back(stockPrint(path, file, 0, 0));
	if (this->_graph->createAsset(path, file) == false)
	{
		this->_graph->createText(text, file);
		this->_allNibblerSprite[index].SetText(true);
	}
}

bool Nibbler::initGame(const std::shared_ptr<displayModule::IDisplayModule> &asset)
{
	if (!this->setLib(asset))
		return (false);
	this->_move = RIGHT;
	this->_graph->clearScreen();
	this->initAssets();
	// this->_graph->startSound("Nibbler");
	return (true);
}

bool Nibbler::setLib(const std::shared_ptr<displayModule::IDisplayModule> &asset)
{
	if (!asset)
		return (false);
	this->_graph = asset;
	return (true);
}

extern "C"
{
	Nibbler *allocator()
	{
		return new Nibbler();
	}

	void deleter(Nibbler *ptr)
	{
		delete ptr;
	}
}
}; // namespace gameModule


// #define RAND_MAX 18

// gameModule::Nibbler::Nibbler()
// {
//     this->nbApples = 0;

//     this->nibbler.push_back(std::make_pair(7, 9));
//     this->nibbler.push_back(std::make_pair(8, 9));
//     this->nibbler.push_back(std::make_pair(9, 9));
//     this->nibbler.push_back(std::make_pair(18, 9));
// }

// gameModule::Nibbler::~Nibbler()
// {
// }

// bool gameModule::Nibbler::initGame(std::shared_ptr<displayModule::IDisplayModule> asset)
// {
//     if (!this->setLib(asset))
//         return (false);
//     this->_graph->clearScreen();
//     this->initAssets();
//     //this->_graph->startSound("Nibbler");
//     return (true);
// }

// bool gameModule::Nibbler::initAssets()
// {
//     this->_graph->createAsset("./Games/nibbler/assets", "head");
//     this->_graph->createAsset("./Games/nibbler/assets", "body");
//     this->_graph->createAsset("./Games/nibbler/assets", "egg");
//     this->_graph->createAsset("./Games/nibbler/assets", "wall");
//     this->_graph->createAsset("./Games/nibbler/assets", "empty");
// }

// bool gameModule::Nibbler::setLib(const std::shared_ptr<displayModule::IDisplayModule> &asset)
// {
//     if (!asset)
//         return (false);
//     this->_graph = asset;
//     return (true);
// }

// void gameModule::Nibbler::drawElements()
// {
//     int i = 0;

//     this->drawMap();

//     // this->_graph->createText("x", "Apple");
//     // this->_graph->drawText("Apple", this->pos_apple.first, this->pos_apple.second);
//     // for (i = 0; i != this->nibbler.size; i++) {
//     //     if (i == 0)
//     //         this->_graph->createText("P", "nibbler" + i);
//     //     else
//     //         this->_graph->createText("*", "nibbler" + i);
//     //     this->_graph->drawText("nibbler" + i, this->nibbler[i].first, this->nibbler[i].second);
//     // }
//     this->_graph->refreshWindow();
// }

// void gameModule::Nibbler::drawMap()
// {
// 	unsigned int index = 0;
// 	int line = 0;

// 	while (index < this->map.size())
// 	{
// 		while (this->map[index][line])
// 		{
// 			if (this->map[index][line] == '#')
// 			{
// 				if (this->_allNibblerSprite[3].GetText())
// 					this->_graph->drawText("wall", line, 18 + index);
// 				else
// 					this->_graph->drawAsset("wall", line, 18 + index);
// 			}
// 			else
// 			{
// 				if (this->_allNibblerSprite[3].GetText())
// 					this->_graph->drawText("empty", line, 18 + index);
// 				else
// 					this->_graph->drawAsset("empty", line, 18 + index);
// 			}
// 			line++;
// 		}
// 		line = 0;
// 		index++;
// 	}
// }

// void gameModule::Nibbler::addApple()
// {
//     int x = 0;
//     int y = 0;

//     while (map[y][x] != ' ') {
//         x = std::rand();
//         y = std::rand();
//     }
//     this->pos_apple = std::make_pair(x, y);
// }

// displayModule::e_event gameModule::Nibbler::game()
// {
//     std::fstream file("../assets/1d/map1.txt");
//     int i = 0;

//     if (!file.is_open())
//         exit(84);
//     while (getline(file, this->map[i], '\n')) {
//         this->_graph->createText(this->map[i], "Map" + i);
//         i++;
//     }
//     file.close();

//     while (!this->isQuit) {
//         if (this->nbApples == 0)
//             this->addApple();
//         this->drawElements();
//         if ((this->ev_nibbler == displayModule::e_event::ERROR) ||
//         (this->ev_nibbler == displayModule::e_event::ESCAPE) ||
//         ((this->ev_nibbler >= displayModule::e_event::ARROW_UP) && (this->ev_nibbler <= displayModule::e_event::ARROW_LEFT)))
//             return (this->ev_nibbler);
//         this->catchNibblerEvent(this->_graph->catchEvent());
//     }
//     return (this->ev_nibbler);
// }

// void gameModule::Nibbler::move_nibbler(int x, int y)
// {
//     bool isApple = false;
//     auto tmp = this->nibbler[0];
//     auto newTmp = std::make_pair(x, y);
//     int i = 0;
    
//     for (i = 0; i < this->nibbler.size; i++) {
//         if (this->nibbler[i].first == x && this->nibbler[i].second == y)
//             exit(84);
//     }
//     if (x == this->pos_apple.first && y == this->pos_apple.second) {
//         this->nbApples = 0;
//         this->score++;
//         while (i < nibbler.size()) {
//             tmp = this->nibbler[i];
//             this->nibbler[i] = newTmp;
//             newTmp = tmp;
//             i++;
//         }
//         this->nibbler.push_back(tmp);
//     } else if (this->map[y][x] == '#') {
//         exit(84);
//     } else if (this->map[y][x] == ' ') {
//         while (i < nibbler.size()) {
//             this->nibbler[i] = newTmp;
//             newTmp = tmp;
//             i++;
//             tmp = this->nibbler[i];
//         }
//     }
// }

// displayModule::e_event gameModule::Nibbler::catchNibblerEvent(displayModule::e_event event)
// {
//     this->ev_nibbler = event;

//     if (this->ev_nibbler == displayModule::e_event::KEY_Z)
//         this->move_nibbler(this->nibbler[0].first, this->nibbler[0].second - 1);
//     else if (this->ev_nibbler == displayModule::e_event::KEY_Q)
//         this->move_nibbler(this->nibbler[0].first - 1, this->nibbler[0].second);
//     else if (this->ev_nibbler == displayModule::e_event::KEY_D)
//         this->move_nibbler(this->nibbler[0].first + 1, this->nibbler[0].second);
//     else if (this->ev_nibbler == displayModule::e_event::KEY_S)
//         this->move_nibbler(this->nibbler[0].first, this->nibbler[0].second + 1);
//     return (this->ev_nibbler);
// }