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
#include "IDisplayModule.hpp"
#include "IGameModule.hpp"
#include "stockPrint.hpp"

namespace gameModule
{
	enum e_move
	{
		ERROR = -1,
		RIGHT,
		LEFT,
		TOP,
		BOT
	};

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

			void initSound();
			void startSound(const std::string &key);

			void initAssets();

			bool exitEvent(displayModule::e_event evt);

			void printGame();
			void printMap();

			bool stockMap(const std::string &path);
			std::vector<std::string> _map;

			void initSprite(std::string file, std::string text, int index);

			// Vector sprite launcher
			std::vector<stockPrint> _allSnakeSprite;

			void moveSnake(displayModule::e_event ev);
			e_move _move;
			std::vector<stockPrint> _snake;
			void printPlayer();
			void detectSnake();
			void snakeMove(int x, int y);
			void detectObj();

	};
} // namespace gameModule

#endif /* !PACMAN_HPP_ */
