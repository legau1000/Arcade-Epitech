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
	return displayModule::e_event::NOTHING;
}

void Pacman::fillMap()
{
	std::ifstream fileName("Games/pacman/assets/2d/map.txt", std::ios::in);

	std::string content;
	while (getline(fileName, content))
	{
		this->_map.append(content);
		this->_map.append("\n");
	}
}

void Pacman::createMap(std::shared_ptr<displayModule::IDisplayModule> asset)
{
	int i = 0;
	int x = 10;
	int y = 10;
	this->fillMap();

	while (this->_map[i] != '\0')
	{
		if (this->_map[i] == '#')
		{
			asset->createAsset("Games/pacman/assets", "wall.png");
			asset->drawAsset("wall", x, y);
			x += 1;
		}
		else if (this->_map[i] == ' ')
		{
			asset->createAsset("Games/pacman/assets", "little.png");
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

void Pacman::initCharacter(std::shared_ptr<displayModule::IDisplayModule> asset, int x, int y)
{
	asset->createAsset("Games/pacman/assets", "miss.png");
	asset->drawAsset("miss", x, y);
}

void Pacman::moveCharacter(std::shared_ptr<displayModule::IDisplayModule> asset, int x, int y)
{
	if (asset->catchEvent() == displayModule::ARROW_LEFT)
	{
		asset->drawAsset("miss", x + 1, y);
		printf("oui");
	}
}

bool Pacman::initGame(std::shared_ptr<displayModule::IDisplayModule> asset)
{
	this->createMap(asset);
	this->initCharacter(asset, 19, 19);
	this->moveCharacter(asset, 19, 19);
	asset->start_sound();
	asset->refreshWindow();
	return true;
}

bool Pacman::setLib(std::shared_ptr<displayModule::IDisplayModule> asset)
{
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