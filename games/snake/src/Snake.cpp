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

	displayModule::e_event Snake::Menu()
	{
		printf("BITE\n");
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
		int x = 0;
		int y = 0;
		int index = 0;

		while (index < this->_snake.size()) {
			x = this->_snake[index].GetX();
			y = this->_snake[index].GetY() + 10;
			if (this->_snake[index].GetText())
				this->_graph->drawText(this->_snake[index].GetName(), x, y);
			else
				this->_graph->drawAsset(this->_snake[index].GetName(), x, y);
			index++;
		}
	}

	void Snake::printFood()
	{
		if (this->_allSnakeSprite[2].GetText())
			this->_graph->drawText("aubergine", x_eat, 10 + y_eat);
		else
			this->_graph->drawAsset("aubergine", x_eat, 10 + y_eat);
	}

	void Snake::snakeMove(int x, int y)
	{
		int index = this->_snake.size() - 1;
		int stockX = x;
		int stockY = y;

		while (index > 0) {
			x = this->_snake[index - 1].GetX();
			y = this->_snake[index - 1].GetY();
			this->_snake[index].SetXY(x, y);
			index--;
		}
		x = stockX + this->_snake[0].GetX();
		y = stockY + this->_snake[0].GetY();
		this->_snake[0].SetXY(x, y);
	}

	bool Snake::detectMe()
	{
		int index = this->_snake.size() - 1;

		while (index != 0) {
			if (this->_snake[0].GetX() == this->_snake[index].GetX() &&
				this->_snake[0].GetY() == this->_snake[index].GetY())
				return (true);
			index--;
		}
		return (false);
	}

	void Snake::detectObj()
	{
		if (this->_map[this->_snake[0].GetY()][this->_snake[0].GetX()] == '#') {
			printf("GAME OVER\n");
		}
	}

	void Snake::addCore(int x, int y)
	{
		this->_snake.push_back(stockPrint("./games/snake/assets", "body", x, y));
		this->_snake[this->_snake.size() - 1].SetXY(x, y);
	}

	void Snake::detectSnake()
	{
		int x = 0;
		int y = 0;
		int stockX = this->_snake[this->_snake.size()-1].GetX();
		int stockY = this->_snake[this->_snake.size()-1].GetX();

		switch (this->_move) {
			case TOP: y = -1; break;
			case BOT: y = 1; break;
			case RIGHT: x = 1; break;
			case LEFT: x = -1; break;
			default: break;
		}
		snakeMove(x, y);
		if (this->_map[this->_snake[0].GetY()][this->_snake[0].GetX()] != ' ') {
			this->detectObj();
		}
		// Core Folow
		if (this->_snake[0].GetY() == this->y_eat && 
			this->_snake[0].GetX() == this->x_eat) {
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

	void Snake::printGame()
	{
		this->detectSnake();
		this->printMap();
		this->printFood();
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

	displayModule::e_event Snake::game()
	{
		displayModule::e_event evt = displayModule::e_event::NOTHING;

		this->stockMap("./games/snake/map/mapEasy.txt");
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
		this->_graph->createSound("./games/snake/assets/Snake.ogg", "SnakeSound");
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
	}

	void Snake::initSprite(std::string file, std::string text, int index)
	{
		std::string path = "./games/snake/assets";

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
		this->x_eat = 9;
		this->_score = 0;
		this->y_eat = 6;
		this->_snake.push_back(stockPrint("./games/snake/assets", "head", 1, 1));
		return (true);
	}

	bool Snake::setLib(const std::shared_ptr<displayModule::IDisplayModule> &asset)
	{
        printf(" EST \n");
		if (asset == nullptr)
			return (false);
        printf(" PD \n");
		if (this->_graph != nullptr)
			this->_graph = nullptr;
		this->_graph = asset;
		this->_graph->clearScreen();
        printf(" !	\n");
		this->initAssets();
		// this->_graph->initSound();
		// this->_graph->startSound("Snake");
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