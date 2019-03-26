/*
** EPITECH PROJECT, 2019
** pacman
** File description:
** Pacman
*/

#include <iostream>
#include <memory>
#include <fstream>

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

		while (index < this->_map.size()) {
			while (this->_map[index][line]) {
				if (this->_map[index][line] == '#')
					this->_graph->drawAsset("wall", line, 10 + index);
				else
					this->_graph->drawAsset("empty", line, 10 + index);
				line++;
			}
			line = 0;
			index++;
		}
	}

	void Snake::printGame()
	{
		this->printMap();
		// this->printFood();
		// this->printPlayer();
		// this->printOther();
		this->_graph->refreshWindow();
	}

	bool Snake::stockMap(const std::string &path)
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

	displayModule::e_event Snake::game()
	{
		displayModule::e_event evt = displayModule::e_event::NOTHING;

		this->stockMap("./Games/snake/map/mapEasy.txt");
		while (!this->exitEvent(evt)) {
			this->printMap();
			evt = this->_graph->catchEvent();
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
		this->_graph->createAsset("./Games/snake/assets", "head");
		this->_graph->createAsset("./Games/snake/assets", "body");
		this->_graph->createAsset("./Games/snake/assets", "aubergine");
		this->_graph->createAsset("./Games/snake/assets", "wall");
		this->_graph->createAsset("./Games/snake/assets", "empty");
	}

	bool Snake::initGame(const std::shared_ptr<displayModule::IDisplayModule> &asset)
	{
		if (!this->setLib(asset))
			return (false);
		// this->_graph->clearScreen();
		this->initAssets();
		this->_graph->startSound("Snake");
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