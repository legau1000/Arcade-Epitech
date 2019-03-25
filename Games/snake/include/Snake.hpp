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
	class Snake : public IGameModule
	{
		public:
			Snake();
			~Snake();

			displayModule::e_event game();
			bool initGame(const std::shared_ptr<displayModule::IDisplayModule> &asset);
			bool setLib(const std::shared_ptr<displayModule::IDisplayModule> &asset);

		protected:
		private:
			std::shared_ptr<displayModule::IDisplayModule> _graph;

	};
} // namespace gameModule

#endif /* !PACMAN_HPP_ */
