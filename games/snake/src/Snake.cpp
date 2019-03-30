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

	bool Snake::exitEvent()
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

	void Snake::setFoodPosition()
	{
		this->x_eat = std::rand() % 17;
		this->y_eat = std::rand() % 17;
		while (this->_map[this->y_eat][this->x_eat] == '#') {
			this->x_eat = std::rand() % 17;
			this->y_eat = std::rand() % 17;
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
			this->setFoodPosition();
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

	void Snake::playGame()
	{
		this->_graph->clearScreen();
		this->evt = this->_graph->catchEvent();
		this->printGame();
		this->moveSnake(evt);
	}

	void Snake::controlEventMenu()
	{
		if (this->evt == displayModule::e_event::KEY_Z) {

		} else if (this->evt == displayModule::e_event::KEY_S) {
		
		} else if (this->evt == displayModule::e_event::ENTER) {

		}
	}

	void Snake::printSprite(int index)
	{
		std::string name = this->_allSnakeSprite[index].GetName();
		int x = this->_allSnakeSprite[index].GetX();
		int y = this->_allSnakeSprite[index].GetY();

		if (this->_allSnakeSprite[index].GetText())
			this->_graph->drawText(name, x, y);
		else
			this->_graph->drawAsset(name, x, y);
	}

	void Snake::printMenu()
	{
		this->printSprite(5);
		this->printSprite(6);
		this->printSprite(7);
		this->_graph->refreshWindow();
	}

	void Snake::Menu()
	{
		this->_graph->clearScreen();
		this->evt = this->_graph->catchEvent();
		this->controlEventMenu();
		this->printMenu();
	}

	displayModule::e_event Snake::game()
	{
		this->stockMap("./games/snake/map/mapEasy.txt");
		while (!this->exitEvent()) {
			std::this_thread::sleep_for(std::chrono::milliseconds(200));
			(this->*position)();
		}
		return (this->evt);
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
		this->initSprite("body", "O", 1);
		this->initSprite("aubergine", "M", 2);
		this->initSprite("wall", "+", 3);
		this->initSprite("empty", " ", 4);
		this->initSprite("Play", "Play", 5); // To Do 2D
		this->_allSnakeSprite[5].SetXY(20, 20);
		this->initSprite("Snake", "Snake", 6); // To Do 2D
		this->initSprite("arrowSnake", "=>", 7);
		this->_allSnakeSprite[7].SetXY(5, 21);
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
		if (setLib(asset) == false)
			return (false);
		this->_move = RIGHT;
		this->x_eat = 9;
		this->_score = 0;
		this->y_eat = 6;
		this->_arrowMenuPos = 0;
		this->_snake.push_back(stockPrint("./games/snake/assets", "head", 1, 1));
		this->evt = displayModule::e_event::NOTHING;
		this->position = &Snake::Menu;
		return (true);
	}

	bool Snake::setLib(const std::shared_ptr<displayModule::IDisplayModule> &asset)
	{
		if (asset == nullptr)
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
        std::shared_ptr<IGameModule> allocator()
        {
            return std::make_shared<Snake>();
        }
    }
}; // namespace gameModule