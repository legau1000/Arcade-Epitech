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
	auto ext = this->_lib->catchEvent();

	while (ext != displayModule::e_event::ESCAPE)
	{
		this->_lib->clearScreen();
		this->drawMap();
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
}

void Pacman::drawMap()
{
	int i = 0;
	int x = 0;
	int y = 0;

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
		if (this->_map[i] == '\n')
		{
			y += 1;
			x = 0;
		}
		i++;
	}
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

void Pacman::move_nibbler(int x, int y)
{
	//if (this->_map[x] == ' ')
	//this->_lib->drawAsset("miss", x, y);
}

displayModule::e_event Pacman::catchPacmanEvent(displayModule::e_event ext)
{
	if (ext == displayModule::e_event::KEY_Z)
		this->move_nibbler(this->x, this->y -= 1);
	else if (ext == displayModule::e_event::KEY_Q)
		this->move_nibbler(this->x -= 1, this->y);
	else if (ext == displayModule::e_event::KEY_D)
		this->move_nibbler(this->x += 1, this->y);
	else if (ext == displayModule::e_event::KEY_S)
		this->move_nibbler(this->x, this->y += 1);
	return (ext);
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