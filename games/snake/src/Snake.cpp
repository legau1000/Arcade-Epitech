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
#include <thread>
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
		int x = this->_snake[0].GetX();
		int y = this->_snake[0].GetY() + 10;

		if (this->_snake[0].GetText())
			this->_graph->drawText("head", x, y);
		else
			this->_graph->drawAsset("head", x, y);
	}

	void Snake::snakeMove(int x, int y)
	{
		x = x + this->_snake[0].GetX();
		y = y + this->_snake[0].GetY();
		this->_snake[0].SetXY(x, y);
	}

	void Snake::detectObj()
	{
		if (this->_map[this->_snake[0].GetY()][this->_snake[0].GetX()] == '#') {
			printf("GAME OVER\n");
		} //else if (this->detectMe()) {
		//
		//}
	}

	void Snake::detectSnake()
	{
		switch (this->_move) {
			case TOP: snakeMove(0, -1); break;
			case BOT: snakeMove(0, 1); break;
			case RIGHT: snakeMove(1, 0); break;
			case LEFT: snakeMove(-1, 0); break;
			default: break;
		}
		if (this->_map[this->_snake[0].GetY()][this->_snake[0].GetX()] != ' ') {
			this->detectObj();
		}
	}

	void Snake::printGame()
	{
		this->detectSnake();
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
		while (getline(file, content)) {
			this->_map.push_back(content);
		}
		file.close();
		return (true);
	}

	void Snake::moveSnake(displayModule::e_event evt)
	{
		switch (evt) {
			case displayModule::e_event::KEY_Z:
				this->_move = TOP;
				break;
			case displayModule::e_event::KEY_S:
				this->_move = BOT;
				break;
			case displayModule::e_event::KEY_Q:
				this->_move = LEFT;
				break;
			case displayModule::e_event::KEY_D:
				this->_move = RIGHT;
				break;
			default:
				break;
		}
	}

	displayModule::e_event Snake::game()
	{
		displayModule::e_event evt = displayModule::e_event::NOTHING;

		this->stockMap("./Games/snake/map/mapEasy.txt");
		while (!this->exitEvent(evt)) {
			this->printGame();
			std::this_thread::sleep_for(std::chrono::milliseconds(200));
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
		if (this->_graph->createAsset(path, file) == false) {
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
		// this->_graph->initSound();
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