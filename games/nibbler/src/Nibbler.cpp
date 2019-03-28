/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Nibbler
*/

#include <iostream>
#include <memory>
#include <fstream>
#include <time.h>
#include <thread>
#include "Nibbler.hpp"

namespace gameModule
{
	Nibbler::Nibbler()
	{
	}

	Nibbler::~Nibbler()
	{
	}

	displayModule::e_event Nibbler::Menu()
	{
		printf("BITE\n");
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
		int x = 0;
		int y = 0;
		int index = 0;

		while (index < this->_nibbler.size()) {
			x = this->_nibbler[index].GetX();
			y = this->_nibbler[index].GetY();
			if (this->_nibbler[index].GetText())
				this->_graph->drawText(this->_nibbler[index].GetName(), x, y);
			else
				this->_graph->drawAsset(this->_nibbler[index].GetName(), x, y);
			index++;
		}
	}

	void Nibbler::printFood()
	{
		if (this->_allNibblerSprite[2].GetText())
			this->_graph->drawText("egg", this->x_food, this->y_food);
		else
			this->_graph->drawAsset("egg", this->x_food, this->y_food);
	}

	void Nibbler::nibblerMove(int x, int y)
	{
		int index = this->_nibbler.size() - 1;
		int stockX = x;
		int stockY = y;

		while (index > 0) {
			x = this->_nibbler[index - 1].GetX();
			y = this->_nibbler[index - 1].GetY();
			this->_nibbler[index].SetXY(x, y);
			index--;
		}
		x = stockX + this->_nibbler[0].GetX();
		y = stockY + this->_nibbler[0].GetY();
		this->_nibbler[0].SetXY(x, y);
	}

	bool Nibbler::detectMe()
	{
		int index = this->_nibbler.size() - 1;

		while (index != 0) {
			if (this->_nibbler[0].GetX() == this->_nibbler[index].GetX() &&
				this->_nibbler[0].GetY() == this->_nibbler[index].GetY())
				return (true);
			index--;
		}
		return (false);
	}

	void Nibbler::detectObj()
	{
		if (this->_map[this->_nibbler[0].GetY()][this->_nibbler[0].GetX()] == '#') {
			printf("GAME OVER\n");
		}
	}

	void Nibbler::addCore(int x, int y)
	{
		this->_nibbler.push_back(stockPrint("./games/nibbler/assets", "body", x, y));
		this->_nibbler[this->_nibbler.size() - 1].SetXY(x, y);
	}

	void Nibbler::detectNibbler()
	{
		int x = 0;
		int y = 0;
		int stockX = this->_nibbler[this->_nibbler.size()-1].GetX();
		int stockY = this->_nibbler[this->_nibbler.size()-1].GetX();

		switch (this->_move) {
			case TOP: y = -1; break;
			case BOT: y = 1; break;
			case RIGHT: x = 1; break;
			case LEFT: x = -1; break;
			default: break;
		}
		nibblerMove(x, y);
		if (this->_map[this->_nibbler[0].GetY()][this->_nibbler[0].GetX()] != ' ') {
			this->detectObj();
		}
		// Core Folow
		if (this->_nibbler[0].GetY() == this->y_food && 
			this->_nibbler[0].GetX() == this->x_food) {
			this->_score += 5;
			// Place New Apple
			// Be strongeur
			this->addCore(x, y);
		}
		if (this->detectMe()) {
			//Game Over Menu
			printf("GAME OVER\n");
		}
	}

	void Nibbler::printGame()
	{
		this->detectNibbler();
		this->printMap();
		this->printFood();
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
		while (getline(file, content)) {
			this->_map.push_back(content);
		}
		file.close();
		return (true);
	}

	void Nibbler::moveNibbler(displayModule::e_event evt)
	{
		switch (evt) {
			case displayModule::e_event::KEY_Z:
				if (this->_move != BOT)
					this->_move = TOP;
				break;
			case displayModule::e_event::KEY_S:
				if (this->_move != TOP)
					this->_move = BOT;
				break;
			case displayModule::e_event::KEY_Q:
				if (this->_move != RIGHT)
					this->_move = LEFT;
				break;
			case displayModule::e_event::KEY_D:
				if (this->_move != LEFT)
					this->_move = RIGHT;
				break;
			default:
				break;
		}
	}

	displayModule::e_event Nibbler::game()
	{
		displayModule::e_event evt = displayModule::e_event::NOTHING;

		this->stockMap("./games/nibbler/map/map1.txt");
		while (!this->exitEvent(evt)) {
			this->printGame();
			std::this_thread::sleep_for(std::chrono::milliseconds(200));
			evt = this->_graph->catchEvent();
			this->moveNibbler(evt);
		}
		return (evt);
	}

	void Nibbler::initSound()
	{
		this->_graph->createSound("./Games/nibbler/assets/Nibbler.ogg", "NibblerSound");
	}

	void Nibbler::startSound(const std::string &key)
	{
		this->_graph->startSound(key);
	}

	void Nibbler::initAssets()
	{
		this->initSprite("head", "P", 0);
		this->initSprite("body", "*", 0);
		this->initSprite("egg", "x", 0);
		this->initSprite("wall", "#", 0);
		this->initSprite("empty", " ", 0);
	}

	void Nibbler::initSprite(std::string file, std::string text, int index)
	{
		std::string path = "./Games/nibbler/assets";

		this->_allNibblerSprite.push_back(stockPrint(path, file, 0, 0));
		if (this->_graph->createAsset(path, file) == false) {
			this->_graph->createText(text, file);
			this->_allNibblerSprite[index].SetText(true);
		}
	}

	bool Nibbler::initGame(const std::shared_ptr<displayModule::IDisplayModule> &asset)
	{
		if (!this->setLib(asset))
			return (false);
		this->_move = LEFT;
		this->x_food = 3;
		this->y_food = 9;
		this->_score = 0;
		this->_nibbler.push_back(stockPrint("./games/nibbler/assets", "head", 7, 9));
		this->_nibbler.push_back(stockPrint("./games/nibbler/assets", "body", 8, 9));
		this->_nibbler.push_back(stockPrint("./games/nibbler/assets", "body", 9, 9));
		this->_nibbler.push_back(stockPrint("./games/nibbler/assets", "body", 10, 9));
		return (true);
	}

	bool Nibbler::setLib(const std::shared_ptr<displayModule::IDisplayModule> &asset)
	{
		if (!asset)
			return (false);
		this->_graph = asset;
		this->_graph->clearScreen();
		this->initAssets();
		// this->_graph->initSound();
		// this->_graph->startSound("Snake");
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