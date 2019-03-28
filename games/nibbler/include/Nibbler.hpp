/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** my
*/

#ifndef NIBBLER_HPP_
# define NIBBLER_HPP_

#include <iostream>
#include <memory>
#include <vector>
#include <unordered_map>
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

	class Nibbler : public IGameModule
	{
		public:
			Nibbler();
			~Nibbler();

			displayModule::e_event game();
			bool initGame(const std::shared_ptr<displayModule::IDisplayModule> &asset);
			bool setLib(const std::shared_ptr<displayModule::IDisplayModule> &asset);

		protected:
		private:
			void initAssets();
			void initSound();
			void initSprite(std::string file, std::string text, int index);

			bool stockMap(const std::string &path);

			void startSound(const std::string &key);

			bool exitEvent(displayModule::e_event evt);
			void moveNibbler(displayModule::e_event ev);
			void nibblerMove(int x, int y);
			void addCore(int x, int y);
			void setFoodPosition(void);

			void printGame();
			void printMap();
			void printPlayer();
			void printFood();

			void detectNibbler();
			void detectObj();
			bool detectMe();

			displayModule::e_event Menu();

			std::shared_ptr<displayModule::IDisplayModule> _graph;
			std::vector<std::string> _map;
			std::vector<stockPrint> _allNibblerSprite;
			e_move _move;
			std::vector<stockPrint> _nibbler;
			int x_food;
			int y_food;
			int _score;
	};
}

#endif //OOP_ARCADE_2018_NIBBLER_HPP