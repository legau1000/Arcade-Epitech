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

#include "Pacman.hpp"

namespace gameModule
{

Pacman::Pacman()
{
}

displayModule::e_event Pacman::game()
{
	displayModule::e_event ext = this->_lib->catchEvent();

	while (ext != displayModule::e_event::ESCAPE)
	{

		this->drawAllAsset();
		this->moovePlayer();
		this->ghostMoove();
		std::this_thread::sleep_for(std::chrono::milliseconds(300));
		this->catchPacmanEvent(ext);
		this->_lib->refreshWindow();

		ext = this->_lib->catchEvent();
		if ((ext == displayModule::e_event::ERROR) ||
			(ext == displayModule::e_event::ESCAPE) ||
			((ext >= displayModule::e_event::ARROW_UP) && (ext <= displayModule::e_event::ARROW_LEFT)))
			return (ext);
	}
	return ext;
}

void Pacman::drawAllAsset()
{
	this->_lib->clearScreen();
	this->drawMap();
	this->_lib->drawAsset("miss", this->x, this->y);
	this->ghost();
}

void Pacman::moovePlayer()
{
	if (this->direction == "z")
		this->movePacmanZ();
	if (this->direction == "q")
		this->movePacmanQ();
	if (this->direction == "d")
		this->movePacmanD();
	if (this->direction == "s")
		this->movePacmanS();
}

void Pacman::createAll()
{
	std::ifstream fileName("games/pacman/assets/2d/map.txt", std::ios::in);

	std::string content;
	while (getline(fileName, content))
	{
		this->_map.append(content);
		this->_map.append("\n");
	}
	this->_lib->createAsset("games/pacman/assets", "wall");
	this->_lib->createAsset("games/pacman/assets", "little");
	this->_lib->createAsset("games/pacman/assets", "blackWall");
	this->_lib->createAsset("games/pacman/assets", "mushroom");
	this->_lib->createAsset("games/pacman/assets", "pink");
	this->_lib->createAsset("games/pacman/assets", "gameOver");
	this->_lib->createText("Score = ", "score");
	this->_lib->createText("0", "0");
	this->_lib->createText("1", "1");
	this->_lib->createText("2", "2");
	this->_lib->createText("3", "3");
	this->_lib->createText("4", "4");
	this->_lib->createText("5", "5");
	this->_lib->createText("6", "6");
	this->_lib->createText("7", "7");
	this->_lib->createText("8", "8");
	this->_lib->createText("9", "9");
}

void Pacman::drawMap()
{
	int i = 0;
	int x = 0;
	int y = 0;
	this->yMap = 0;

	while (this->_map[i] != '\0')
	{
		if (this->_map[i] == '#')
		{
			this->_lib->drawAsset("wall", x, y);
			x += 1;
		}
		else if (this->_map[i] == ' ')
		{
			this->_lib->drawAsset("little", x, y);
			x += 1;
		}
		else if (this->_map[i] == 'i')
		{
			this->_lib->drawAsset("blackWall", x, y);
			x += 1;
		}
		else if (this->_map[i] == 'q')
		{
			this->_lib->drawAsset("mushroom", x, y);
			x += 1;
		}
		if (this->_map[i] == '\n')
		{
			this->yMap += 1;
			y += 1;
			x = 0;
		}
		i++;
	}
}

void Pacman::createCharacter()
{
	this->_lib->createAsset("games/pacman/assets", "miss");
}

bool Pacman::initGame(const std::shared_ptr<displayModule::IDisplayModule> &asset)
{
	this->x = 9;
	this->y = 9;
	this->xGhost = 1;
	this->yGhost = 9;
	score = 0;
	this->setLib(asset);
	return true;
}

bool Pacman::setLib(const std::shared_ptr<displayModule::IDisplayModule> &asset)
{
	this->_lib = asset;
	this->_lib->clearScreen();
	this->createAll();
	this->createCharacter();
	return true;
}

void Pacman::movePacmanZ()
{
	if (this->_map[((this->yMap + 1) * (this->y)) - (this->yMap + 1 - this->x)] != '#')
	{
		if (this->_map[((this->yMap + 1) * (this->y)) - (this->yMap + 1 - this->x)] == ' ')
			this->score += 1;
		if (this->_map[((this->yMap + 1) * (this->y)) - (this->yMap + 1 - this->x)] == 'q')
			this->score += 10;
		this->y -= 1;
		this->_map[((this->yMap + 1) * (this->y + 1)) - (this->yMap - this->x + 1)] = 'i';
	}
}

void Pacman::movePacmanQ()
{
	if (this->_map[((this->yMap + 1) * (this->y)) + this->x - 1] != '#')
	{
		if (this->_map[((this->yMap + 1) * (this->y)) + this->x - 1] == ' ')
			this->score += 1;
		this->x -= 1;
		this->_map[((this->yMap + 1) * (this->y)) + this->x] = 'i';
	}
}

void Pacman::movePacmanD()
{
	if (this->_map[((this->yMap + 1) * (this->y)) + this->x + 1] != '#')
	{
		if (this->_map[((this->yMap + 1) * (this->y)) + this->x + 1] == ' ')
			this->score += 1;
		if (this->_map[((this->yMap + 1) * (this->y)) + this->x + 1] == 'q')
			this->score += 10;
		this->x += 1;
		this->_map[((this->yMap + 1) * (this->y)) + this->x] = 'i';
	}
}

void Pacman::movePacmanS()
{
	if (this->_map[((this->yMap + 1) * (this->y + 1)) + this->x] != '#')
	{
		if (this->_map[((this->yMap + 1) * (this->y + 1)) + this->x] == ' ')
			this->score += 1;
		this->y += 1;
		this->_map[((this->yMap + 1) * (this->y + 1)) - (this->yMap - this->x + 1)] = 'i';
	}
}

void Pacman::drawScore()
{
	int index = score / 10;

	this->_lib->drawText("score", 5, 25);
	this->_lib->drawText(std::to_string(index), 10, 25);
	this->_lib->drawText(std::to_string(score % 10), 11, 25);
}

displayModule::e_event Pacman::catchPacmanEvent(displayModule::e_event ext)
{
	this->drawScore();
	if (ext == displayModule::e_event::KEY_Z)
		this->direction = "z";
	else if (ext == displayModule::e_event::KEY_Q)
		this->direction = "q";
	else if (ext == displayModule::e_event::KEY_D)
		this->direction = "d";
	else if (ext == displayModule::e_event::KEY_S)
		this->direction = "s";
	return (ext);
}

void Pacman::ghostMoove()
{
	if (this->xGhost < this->y || this->yGhost < this->x)
	{
		if (this->directionGhost == 1)
			this->yGhost -= 1;
		if (this->directionGhost == 2)
			this->xGhost -= 1;
		if (this->directionGhost == 3)
			this->xGhost += 1;
		if (this->directionGhost == 4)
			this->yGhost += 1;
	}
	if (this->yGhost == this->x && this->xGhost == this->y)
	{
		this->direction = 5;
		this->directionGhost = 5;
		this->_lib->clearScreen();
		this->_lib->drawAsset("gameOver", 1, 1);
	}
}

void Pacman::ghost()
{
	this->_lib->drawAsset("pink", this->yGhost, this->xGhost);
	if (this->_map[((this->yMap + 1) * (this->yGhost)) - (this->yMap + 1 - this->xGhost)] != '#')
		this->directionGhost = 1;
	if (this->_map[((this->yMap + 1) * (this->yGhost)) + this->xGhost - 1] != '#')
		this->directionGhost = 2;
	if (this->_map[((this->yMap + 1) * (this->yGhost)) + this->xGhost + 1] != '#')
		this->directionGhost = 3;
	if (this->_map[((this->yMap + 1) * (this->yGhost + 1)) + this->xGhost] != '#')
		this->directionGhost = 4;
}

Pacman::~Pacman()
{
}

extern "C"
{
	Pacman *allocator()
	{
		return new Pacman();
	}

	void deleter(Pacman *ptr)
	{
		delete ptr;
	}
}
}; // namespace gameModule