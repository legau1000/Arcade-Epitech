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
			void Menu();
			void ChooseMap();
			void playGame();
			void gameOver();

			// Functions
			void printSprite(int index);
			void controlEventMenu();
			void printMenu();
			void addCore(int x, int y);
			void printPlayer();
			void printFood();
			void detectSnake();
			void snakeMove(int x, int y);
			void detectObj();
			bool detectMe();

			void initSound();
			void startSound(const std::string &key);

			void initAssets();

			bool exitEvent();

			void printGame();
			void printMap();

			bool stockMap(const std::string &path);

			void setFoodPosition();

			void initSprite(std::string file, std::string text, int index);
			void moveSnake(displayModule::e_event ev);
			void moveMenuArrow();

			void controlEventChooseMap();

			void initMap();

			void printChooseMap();

			void moveMapArrow();

			void printGameOver();
	
			void controlEventGameOver();

			// Variables

			int x_eat;
			int y_eat;
			int _score;
			e_move _move;
			displayModule::e_event evt;
			std::vector<std::string> _map;
			std::vector<std::string> _allmap;
			std::vector<stockPrint> _allSnakeSprite;
			std::vector<stockPrint> _snake;
			std::vector<stockPrint> _spriteMap;
			std::shared_ptr<displayModule::IDisplayModule> _graph;
			int _arrowMenuPos;
			int _arrowMapPos;

			void (Snake::*position)();

	};
} // namespace gameModule

#endif /* !PACMAN_HPP_ */
