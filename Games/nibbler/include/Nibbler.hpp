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
			std::vector<stockPrint> _allNibblerSprite;

			void moveNibbler(displayModule::e_event ev);
			e_move _move;
			std::vector<stockPrint> _Nibbler;
			void printPlayer();

	};
}

#endif //OOP_ARCADE_2018_NIBBLER_HPP