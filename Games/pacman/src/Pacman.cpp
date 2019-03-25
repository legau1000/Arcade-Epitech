/*
** EPITECH PROJECT, 2019
** pacman
** File description:
** Pacman
*/

#include <iostream>
#include <memory>
#include <fstream>

#include "Pacman.hpp"

namespace gameModule
{

Pacman::Pacman()
{
}

displayModule::e_event Pacman::game()
{
	int x = 19;
	int y = 19;
	while (this->_lib->catchEvent() != displayModule::e_event::ESCAPE)
	{
		this->_lib->clearScreen();
		this->drawMap(this->_lib);
		this->drawCharacter(this->_lib, x, y);
		if (this->_lib->catchEvent() == displayModule::e_event::ARROW_RIGHT)
			this->moveCharacter(this->_lib, x, y);
		this->_lib->refreshWindow();
	}
	if (this->_lib->catchEvent() != displayModule::e_event::ESCAPE)
		return displayModule::e_event::ESCAPE;
	return displayModule::e_event::NOTHING;
}

void Pacman::createMap(const std::shared_ptr<displayModule::IDisplayModule> &asset)
{
	std::ifstream fileName("Games/pacman/assets/2d/map.txt", std::ios::in);

	std::string content;
	while (getline(fileName, content))
	{
		this->_map.append(content);
		this->_map.append("\n");
	}
	asset->createAsset("Games/pacman/assets", "wall.png");
	asset->createAsset("Games/pacman/assets", "little.png");
}

void Pacman::drawMap(const std::shared_ptr<displayModule::IDisplayModule> &asset)
{
	int i = 0;
	int x = 10;
	int y = 10;

	while (this->_map[i] != '\0')
	{
		if (this->_map[i] == '#')
		{
			asset->drawAsset("wall", x, y);

			x += 1;
		}
		else if (this->_map[i] == ' ')
		{
			asset->drawAsset("little", x, y);
			x += 1;
		}
		if (this->_map[i] == '\n')
		{
			y += 1;
			x = 10;
		}
		i++;
	}
}

void Pacman::createCharacter(const std::shared_ptr<displayModule::IDisplayModule> &asset, int x, int y)
{
	asset->createAsset("Games/pacman/assets", "miss.png");
}

void Pacman::drawCharacter(const std::shared_ptr<displayModule::IDisplayModule> &asset, int x, int y)
{
	asset->drawAsset("miss", x, y);
}

void Pacman::moveCharacter(const std::shared_ptr<displayModule::IDisplayModule> &asset, int x, int y)
{
	asset->drawAsset("miss", x + 1, y);
	this->_lib->refreshWindow();
}

bool Pacman::initGame(const std::shared_ptr<displayModule::IDisplayModule> &asset)
{
	this->setLib(asset);
	this->_lib->clearScreen();
	this->createMap(this->_lib);
	this->createCharacter(this->_lib, 19, 19);
	return true;
}

bool Pacman::setLib(const std::shared_ptr<displayModule::IDisplayModule> &asset)
{
	this->_lib = asset;
	return true;
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