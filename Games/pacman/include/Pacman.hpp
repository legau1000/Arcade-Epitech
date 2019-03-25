/*
** EPITECH PROJECT, 2019
** pacman
** File description:
** Pacman
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

#include <iostream>
#include <memory>
#include "IDisplayModule.hpp"
#include "IGameModule.hpp"

namespace gameModule
{
class Pacman : public IGameModule
{
public:
	Pacman();
	~Pacman();

	displayModule::e_event game();
	bool initGame(const std::shared_ptr<displayModule::IDisplayModule> &asset);
	bool setLib(const std::shared_ptr<displayModule::IDisplayModule> &asset);

protected:
private:
	void fillMap(const std::shared_ptr<displayModule::IDisplayModule> &asset);
	void createMap(const std::shared_ptr<displayModule::IDisplayModule> &asset);
	void drawMap(const std::shared_ptr<displayModule::IDisplayModule> &asset);
	void createCharacter(const std::shared_ptr<displayModule::IDisplayModule> &asset, int x, int y);
	void drawCharacter(const std::shared_ptr<displayModule::IDisplayModule> &asset, int x, int y);
	void moveCharacter(const std::shared_ptr<displayModule::IDisplayModule> &asset, int x, int y);

	std::shared_ptr<displayModule::IDisplayModule> _lib;
	std::string _map;
};
} // namespace gameModule

#endif /* !PACMAN_HPP_ */
