/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Map
*/

#include <iostream>
#include <memory>
#include <fstream>

#include "MapPacman.hpp"

MapPacman::MapPacman(const std::string &file)
{
	std::ifstream fileName(file, std::ios::in);

	if (fileName)
	{
		std::string content;
		while (getline(fileName, content))
		{
			std::cout << content << std::endl;
		}
	}
}

MapPacman::~MapPacman()
{
}
