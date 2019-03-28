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
#include <vector>
#include <unordered_map>
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
	void fillMap();
	void createAll();
	void drawMap();
	void createCharacter();
	displayModule::e_event catchPacmanEvent(displayModule::e_event ext);
	void movePacmanS();
	void movePacmanZ();
	void movePacmanQ();
	void movePacmanD();
	void drawElements();
	void ghost();
	void ghostMoove();
	void moovePlayer();
	void drawAllAsset();
	void drawScore();

	int yMap;
	int x;
	int y;
	int xGhost;
	int yGhost;
	int score;
	int directionGhost;

	std::shared_ptr<displayModule::IDisplayModule> _lib;
	std::string _map;
	std::string direction;
};
} // namespace gameModule

#endif /* !PACMAN_HPP_ */
