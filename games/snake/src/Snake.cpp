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
#include <sys/types.h>
#include <dirent.h>
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
		if (evt == displayModule::e_event::KEY_L)
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
						this->_graph->drawText("wall", line, index);
					else
						this->_graph->drawAsset("wall", line, index);
				}
				else
				{
					if (this->_allSnakeSprite[3].GetText())
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

	void Snake::setFoodPosition()
	{
		this->x_eat = std::rand() % 40;
		this->y_eat = std::rand() % 30;
		while (this->_map[this->y_eat][this->x_eat] == '#') {
			this->x_eat = std::rand() % 40;
			this->y_eat = std::rand() % 30;
		}
	}

	void Snake::printPlayer()
	{
		int x = 0;
		int y = 0;
		int index = 0;

		while (index < this->_snake.size()) {
			x = this->_snake[index].GetX();
			y = this->_snake[index].GetY();
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
			this->_graph->drawText("aubergine", x_eat, y_eat);
		else
			this->_graph->drawAsset("aubergine", x_eat, y_eat);
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
			this->position = &Snake::gameOver;
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
		if (this->_snake[0].GetY() == this->y_eat && 
			this->_snake[0].GetX() == this->x_eat) {
			this->_score += 5;
			this->setFoodPosition();
			this->addCore(x, y);
		}
		if (this->detectMe()) {
			this->position = &Snake::gameOver;
		}
	}

	void Snake::printGame()
	{
		this->detectSnake();
		this->printMap();
		this->printFood();
		this->printPlayer();
		this->drawScore();
		this->_graph->refreshWindow();
	}

	bool Snake::stockMap(const std::string &path)
	{
		std::fstream file(path, std::fstream::in);
		std::string content;

		if (!file.is_open())
			return (false);
		this->_map.clear();
		while (getline(file, content)) {
			if (content.size() != 40) {
				file.close();
				return (false);
			}
			this->_map.push_back(content);
		}
		file.close();
		if (this->_map.size() != 30)
			return (false);
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
		if (this->_map.size() != 30 || this->_map[0].size() != 40)
			this->position = &Snake::Menu;
		this->evt = this->_graph->catchEvent();
		if (this->evt == displayModule::e_event::KEY_R) {
			this->_snake.clear();
			this->_move = RIGHT;
			this->x_eat = 9;
			this->y_eat = 6;
			this->_score = 0;
			this->_snake.push_back(stockPrint("./games/snake/assets", "head", 1, 1));
			this->position = &Snake::Menu;
			return;
		}
		this->printGame();
		this->moveSnake(evt);
	}

	void Snake::moveMenuArrow()
	{
		int y[] = {10, 18, 26};

		this->_allSnakeSprite[7].SetXY(3, y[this->_arrowMenuPos]);
	}

	void Snake::initMap()
	{
		DIR *rep = opendir("./games/snake/map/");
		struct dirent *file = nullptr;
		std::string name;
		int index = 1;

		this->_spriteMap.clear();
		this->_map.clear();
		this->_spriteMap.push_back(stockPrint("./games/snake/map/", "Return", 15, (13)));
		this->_graph->createText("Return", "Return");
		this->_spriteMap[0].SetText(true);
		if (rep) {
			file = readdir(rep);
			while (file) {
				name = file->d_name;
				if (name.find(".txt\0") != std::string::npos) {
					name = name.substr(0, name.find("."));
					this->_allmap.push_back(name);
					this->_spriteMap.push_back(stockPrint("./games/snake/map/", name, 15, (13 + (4 * index))));
					this->_graph->createText(name, name);
					this->_spriteMap[index].SetText(true);
					index++;
				}
				file = readdir(rep);
			}
			closedir(rep);
		}
	}

	void Snake::controlEventMenu()
	{
		if (this->evt == displayModule::e_event::KEY_Z) {
			this->_arrowMenuPos -= 1;
			if (this->_arrowMenuPos == -1)
				this->_arrowMenuPos = 2;
			this->moveMenuArrow();
		} else if (this->evt == displayModule::e_event::KEY_S) {
			this->_arrowMenuPos += 1;
			if (this->_arrowMenuPos == 3)
				this->_arrowMenuPos = 0;
			this->moveMenuArrow();
		} else if (this->evt == displayModule::e_event::ENTER) {
			switch (this->_arrowMenuPos)
			{
				case 0:	this->position = &Snake::ChooseMap; this->initMap(); break;
				case 1:	this->position = &Snake::HowToPlay; this->_allSnakeSprite[8].SetXY(0, 0); break;
				case 2:	this->position = &Snake::Score; this->stockScore(); break;
				default: break;
			}
		}
	}

	void Snake::stockScore()
	{
		std::ifstream file("./games/snake/src/.score.txt");
		std::string content;
		std::string totalContent;

		while (getline(file, content))
		{
			totalContent.append(content);
			totalContent.append("\n");
		}
		this->_graph->createText(totalContent, "scoreM");
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
		this->printSprite(8);
		this->printSprite(9);
		this->_graph->refreshWindow();
	}

	void Snake::moveMapArrow()
	{
		this->_allSnakeSprite[7].SetXY(3, (10 + (4 * this->_arrowMapPos)));
	}

	void Snake::controlEventChooseMap()
	{
		if (this->evt == displayModule::e_event::KEY_Z) {
			this->_arrowMapPos -= 1;
			if (this->_arrowMapPos < 0)
				this->_arrowMapPos = this->_spriteMap.size() - 1;
			this->moveMapArrow();
		} else if (this->evt == displayModule::e_event::KEY_S) {
			this->_arrowMapPos = (1 + this->_arrowMapPos) % (this->_spriteMap.size());
			this->moveMapArrow();
		} else if (this->evt == displayModule::e_event::ENTER) {
			if (this->_arrowMapPos == 0) {
				this->position = &Snake::Menu;
			} else {
				this->position = &Snake::playGame;
				if (!this->stockMap("./games/snake/map/" + this->_allmap[this->_arrowMapPos - 1] + ".txt")) {
					this->position = &Snake::Menu;
					return;
				}
				this->setFoodPosition();
			}
		}
	}

	void Snake::printChooseMap()
	{
		int index = 0;
		std::string name;
		int x = 0;
		int y = 0;

		this->printSprite(10);
		this->printSprite(7);
		while (index < this->_spriteMap.size()) {
			name = this->_spriteMap[index].GetName();
			x = this->_spriteMap[index].GetX();
			y = this->_spriteMap[index].GetY();
			this->_graph->drawText(name, x, y);
			index++;
		}
		this->_graph->refreshWindow();
	}

	void Snake::controlHowToPlay()
	{
		if (this->evt == displayModule::e_event::ENTER) {
			this->position = &Snake::Menu;
			this->_allSnakeSprite[8].SetXY(15, 18);
		}
		if (this->evt == displayModule::e_event::KEY_R) {
			this->position = &Snake::Menu;
			this->_allSnakeSprite[8].SetXY(15, 18);
		}
		if (this->evt == displayModule::e_event::KEY_L) {
			this->position = &Snake::Menu;
			this->_allSnakeSprite[8].SetXY(15, 18);
		}
	}

	void Snake::printHowToPlay()
	{
		this->printSprite(8);
		this->printSprite(15);
		this->printSprite(16);
		this->_graph->refreshWindow();
	}

	void Snake::controlEventGameOver()
	{
		if (this->evt == displayModule::e_event::ENTER) {
			this->position = &Snake::Menu;
			std::ofstream file("games/snake/src/.score.txt", std::ios_base::app);
			file << this->_score << std::endl;
		}
	}

	void Snake::printGameOver()
	{
		this->printSprite(11);
		this->printSprite(12);
		this->_graph->refreshWindow();
	}

	void Snake::drawScore()
	{
		int index = this->_score / 10 % 10;
		int centaine = this->_score / 100 % 10;

		this->_graph->drawText("score", 42, 1);
		if (this->_score >= 1000)
			this->_graph->drawText(std::to_string(this->_score / 1000), 50, 1);
		this->_graph->drawText(std::to_string(centaine), 51, 1);
		this->_graph->drawText(std::to_string(index), 52, 1);
		this->_graph->drawText(std::to_string(this->_score % 10), 53, 1);
	}

	void Snake::gameOver()
	{
		this->_graph->clearScreen();
		this->evt = this->_graph->catchEvent();
		this->controlEventGameOver();
		this->printGameOver();
	}

	void Snake::HowToPlay()
	{
		this->_graph->clearScreen();
		this->evt = this->_graph->catchEvent();
		this->controlHowToPlay();
		this->printHowToPlay();
	}

	void Snake::ChooseMap()
	{
		this->_graph->clearScreen();
		this->evt = this->_graph->catchEvent();
		this->controlEventChooseMap();
		this->printChooseMap();
	}

	void Snake::Menu()
	{
		this->_graph->clearScreen();
		this->evt = this->_graph->catchEvent();
		this->controlEventMenu();
		this->printMenu();
	}

	void Snake::printScore()
	{
		this->_graph->drawText("scoreM", 46, 7);
		this->_graph->refreshWindow();
	}

	void Snake::controlEventScore()
	{
		if (this->evt == displayModule::e_event::ENTER) {
			this->position = &Snake::Menu;
		}
	}

	void Snake::Score()
	{
		this->_graph->clearScreen();
		this->evt = this->_graph->catchEvent();
		this->controlEventScore();
		this->printScore();
	}

	displayModule::e_event Snake::game()
	{
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

	void Snake::createLetter()
	{
		char index = 'A';
		std::string data;

		data[1] = '\0';
		while (index <= 'Z') {
			data[0] = index;
			this->_graph->createText(data, data);
			index++;
		}
		this->_graph->createText("Score = ", "score");
		this->_graph->createText("0", "0");
		this->_graph->createText("1", "1");
		this->_graph->createText("2", "2");
		this->_graph->createText("3", "3");
		this->_graph->createText("4", "4");
		this->_graph->createText("5", "5");
		this->_graph->createText("6", "6");
		this->_graph->createText("7", "7");
		this->_graph->createText("8", "8");
		this->_graph->createText("9", "9");
	}

	void Snake::initAssets()
	{
		this->initSprite("head", "0", 0);
		this->initSprite("body", "O", 1);
		this->initSprite("aubergine", "M", 2);
		this->initSprite("wall", "+", 3);
		this->initSprite("empty", " ", 4);
		this->initSprite("Play", "Play", 5); // To Do 2D
		this->_allSnakeSprite[5].SetXY(15, 10);
		this->initSprite("Snake", "Snake", 6);
		this->initSprite("arrowSnake", "=>", 7);
		this->_allSnakeSprite[7].SetXY(3, 10);
		this->initSprite("howtoplaySnake", "How To Play", 8); // To Do 2D
		this->_allSnakeSprite[8].SetXY(15, 18);
		this->initSprite("Score", "Score", 9); // To Do 2D
		this->_allSnakeSprite[9].SetXY(15, 26);
		this->initSprite("ChooseMap", "ChooseYourMap", 10); // To Do 2D
		this->initSprite("gameOver", "gameOver", 11);
		this->initSprite("EnterName", "EnterName", 12);
		this->_allSnakeSprite[12].SetXY(4, 13);
		this->initSprite("arrowUp", "arrowUp", 13);
		this->initSprite("arrowDown", "arrowDown", 14);
		this->_allSnakeSprite.push_back(stockPrint("How1", "TXTHowReturn", 0, 0));
		this->_graph->createText("Press Enter return.", "TXTHowReturn");
		this->_allSnakeSprite[15].SetText(true);
		this->_allSnakeSprite[15].SetXY(20, 20);
		this->_allSnakeSprite.push_back(stockPrint("How2", "TXTHowInfo", 0, 0));
		this->_graph->createText("'Z' = UP  |  'S' = DOWN  |  'Q' = LEFT  |  'D' = RIGHT\nScore + 5 Per food.", "TXTHowInfo");
		this->_allSnakeSprite[16].SetText(true);
		this->_allSnakeSprite[16].SetXY(20, 20);
		this->createLetter();
	}

	void Snake::drawScoreInMenu()
	{
		this->_graph->createText("Score", "scoreMenu");
		this->_graph->drawText("scoreMenu", 45, 5);
		std::ifstream file("./games/pacman/src/.score.txt");
		std::string content;
		std::string totalContent;

		while (getline(file, content))
		{
			totalContent.append(content);
			totalContent.append("\n");
		}
		this->_graph->createText(totalContent, "scoreM");
		this->_graph->drawText("scoreM", 46, 7);
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
		this->x_eat = 0;
		this->y_eat = 0;
		this->_score = 0;
		this->_name = "AAA";
		this->_arrowMenuPos = 0;
		this->_arrowMapPos = 0;
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