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

bool Pacman::initGame(std::shared_ptr<displayModule::IDisplayModule> asset)
{
	try
	{
		std::ifstream fileName("../pacman/assets/2d/.map.txt", std::ios::in);

		std::string content;
		while (getline(fileName, content))
		{
			std::cout << content << std::endl;
		}
		return true;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
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