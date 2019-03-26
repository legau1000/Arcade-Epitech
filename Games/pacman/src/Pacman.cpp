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
		this->_lib->clearScreen();
		this->drawMap();
		this->_lib->drawAsset("miss", this->x, this->y);
		this->ghost();
		this->ghostMoove(ext);
		this->_lib->createText("Score : " + std::to_string(this->score), "score");
		this->_lib->drawText("score", 5, 25);
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

void Pacman::createMap()
{
	std::ifstream fileName("Games/pacman/assets/2d/map.txt", std::ios::in);

	std::string content;
	while (getline(fileName, content))
	{
		this->_map.append(content);
		this->_map.append("\n");
	}
	this->_lib->createAsset("Games/pacman/assets", "wall");
	this->_lib->createAsset("Games/pacman/assets", "little");
	this->_lib->createAsset("Games/pacman/assets", "blackWall");
	this->_lib->createAsset("Games/pacman/assets", "mushroom");
	this->_lib->createAsset("Games/pacman/assets", "pink");
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
		if (this->_map[i] == '\n')
		{
			this->yMap += 1;
			y += 1;
			x = 0;
		}
		i++;
	}
}

void Pacman::drawScore()
{
}

void Pacman::createCharacter()
{
	this->_lib->createAsset("Games/pacman/assets", "miss");
}

bool Pacman::initGame(const std::shared_ptr<displayModule::IDisplayModule> &asset)
{
	this->setLib(asset);
	this->_lib->clearScreen();
	this->createMap();
	this->createCharacter();
	return true;
}

bool Pacman::setLib(const std::shared_ptr<displayModule::IDisplayModule> &asset)
{
	this->_lib = asset;
	return true;
}

void Pacman::movePacmanZ(int x, int y)
{
	this->score += 1;
	this->_map[((this->yMap + 1) * (this->y + 1)) - (this->yMap - this->x + 1)] = 'i';
}

void Pacman::movePacmanQ(int x, int y)
{
	this->score += 1;
	this->_map[((this->yMap + 1) * (this->y)) + this->x] = 'i';
}

void Pacman::movePacmanD(int x, int y)
{
	this->score += 1;
	this->_map[((this->yMap + 1) * (this->y)) + this->x] = 'i';
}

void Pacman::movePacmanS(int x, int y)
{
	this->score += 1;
	this->_map[((this->yMap + 1) * (this->y + 1)) - (this->yMap - this->x + 1)] = 'i';
}

displayModule::e_event Pacman::catchPacmanEvent(displayModule::e_event ext)
{
	if (ext == displayModule::e_event::KEY_Z && this->_map[((this->yMap + 1) * (this->y)) - (this->yMap + 1 - this->x)] != '#')
		this->movePacmanZ(this->x, this->y -= 1);
	else if (ext == displayModule::e_event::KEY_Q && this->_map[((this->yMap + 1) * (this->y)) + this->x - 1] != '#')
		this->movePacmanQ(this->x -= 1, this->y);
	else if (ext == displayModule::e_event::KEY_D && this->_map[((this->yMap + 1) * (this->y)) + this->x + 1] != '#')
		this->movePacmanD(this->x += 1, this->y);
	else if (ext == displayModule::e_event::KEY_S && this->_map[((this->yMap + 1) * (this->y + 1)) + this->x] != '#')
		this->movePacmanS(this->x, this->y += 1);
	return (ext);
}

void Pacman::ghostMoove(displayModule::e_event ext)
{
	if (this->_map[((this->yMap + 1) * (this->yGhost)) - (this->yMap + 1 - this->xGhost)] != '#')
		this->yGhost -= 1;
	if (this->_map[((this->yMap + 1) * (this->yGhost)) + this->xGhost - 1] != '#')
		this->xGhost -= 1;
	if (this->_map[((this->yMap + 1) * (this->y)) + this->xGhost + 1] != '#')
		this->xGhost += 1;
	if (this->_map[((this->yMap + 1) * (this->yGhost + 1)) + this->xGhost] != '#')
		this->yGhost += 1;
}

void Pacman::ghost()
{
	this->_lib->drawAsset("pink", this->yGhost, this->xGhost);
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