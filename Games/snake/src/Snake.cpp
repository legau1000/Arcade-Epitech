/*
** EPITECH PROJECT, 2019
** pacman
** File description:
** Pacman
*/

#include <iostream>
#include <memory>
#include <fstream>
#include <time.h>
#include "Snake.hpp"

namespace gameModule
{

Snake::Snake()
{
}

Snake::~Snake()
{
}

bool Snake::exitEvent(displayModule::e_event evt)
{
	if (evt == displayModule::e_event::KEY_L) //Do it on core
		return (true);
	if (evt >= 1 && evt <= 4)
		return (true);
	if (evt == displayModule::e_event::ESCAPE)
		return (true);
	return (false);
}

void Snake::printMap()
{
	unsigned int index = 0;
	int line = 0;

	while (index < this->_map.size())
	{
		while (this->_map[index][line])
		{
			if (this->_map[index][line] == '#')
			{
				if (this->_allSnakeSprite[3].GetText())
					this->_graph->drawText("wall", line, 10 + index);
				else
					this->_graph->drawAsset("wall", line, 10 + index);
			}
			else
			{
				if (this->_allSnakeSprite[3].GetText())
					this->_graph->drawText("empty", line, 10 + index);
				else
					this->_graph->drawAsset("empty", line, 10 + index);
			}
			line++;
		}
		line = 0;
		index++;
	}
}

void Snake::printPlayer()
{
	if (this->_snake[0].GetText())
		this->_graph->drawText("head", 1, 10 + 1);
	else
		this->_graph->drawAsset("head", 1, 10 + 1);
}

void Snake::printGame()
{
	this->printMap();
	// this->printFood();
	this->printPlayer();
	// this->printOther();
	this->_graph->refreshWindow();
}

bool Snake::stockMap(const std::string &path)
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

void Snake::moveSnake(displayModule::e_event evt)
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

displayModule::e_event Snake::game()
{
	displayModule::e_event evt = displayModule::e_event::NOTHING;
	time_t t1 = time(0);
	time_t t2 = time(0);

	this->stockMap("./Games/snake/map/mapEasy.txt");
	while (!this->exitEvent(evt))
	{
		if (t2 - t1 >= 0.25)
		{
			this->printGame();
			t1 = time(0);
		}
		t2 = time(0);
		evt = this->_graph->catchEvent();
		this->moveSnake(evt);
	}
	return (evt);
}

void Snake::initSound()
{
	this->_graph->createSound("./Games/snake/assets/Snake.ogg", "SnakeSound");
}

void Snake::startSound(const std::string &key)
{
	this->_graph->startSound(key);
}

void Snake::initAssets()
{
	this->initSprite("head", "0", 0);
	this->initSprite("body", "O", 0);
	this->initSprite("aubergine", "M", 0);
	this->initSprite("wall", "+", 0);
	this->initSprite("empty", " ", 0);
	this->_snake.push_back(stockPrint("./Games/snake/assets", "head", 1, 1));
}

void Snake::initSprite(std::string file, std::string text, int index)
{
	std::string path = "./Games/snake/assets";

	this->_allSnakeSprite.push_back(stockPrint(path, file, 0, 0));
	if (this->_graph->createAsset(path, file) == false)
	{
		this->_graph->createText(text, file);
		this->_allSnakeSprite[index].SetText(true);
	}
}

bool Snake::initGame(const std::shared_ptr<displayModule::IDisplayModule> &asset)
{
	if (!this->setLib(asset))
		return (false);
	this->_move = RIGHT;
	this->_graph->clearScreen();
	this->initAssets();
	// this->_graph->startSound("Snake");
	return (true);
}

bool Snake::setLib(const std::shared_ptr<displayModule::IDisplayModule> &asset)
{
	if (!asset)
		return (false);
	this->_graph = asset;
	return (true);
}

extern "C"
{
	Snake *allocator()
	{
		return new Snake();
	}

	void deleter(Snake *ptr)
	{
		delete ptr;
	}
}
}; // namespace gameModule