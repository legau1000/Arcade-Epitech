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
	bool initGame(std::shared_ptr<displayModule::IDisplayModule> asset);
	bool setLib(std::shared_ptr<displayModule::IDisplayModule> asset);

  protected:
  private:
};
} // namespace gameModule

#endif /* !PACMAN_HPP_ */
