/*
** EPITECH PROJECT, 2019
** pacman
** File description:
** Pacman
*/

#include <iostream>
#include <memory>
#include <fstream>

#include "Snake.hpp"

namespace gameModule
{

	Snake::Snake()
	{
	}

	Snake::~Snake()
	{
	}

	displayModule::e_event Snake::game()
	{
		return (this->_graph->catchEvent());
	}

	bool Snake::initGame(const std::shared_ptr<displayModule::IDisplayModule> &asset)
	{
		this->_graph = asset;
		this->_graph->startSound("");
		// this->_graph->refreshWindow();
		this->_graph->clearScreen();
		return (true);
	}

	bool Snake::setLib(const std::shared_ptr<displayModule::IDisplayModule> &asset)
	{
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