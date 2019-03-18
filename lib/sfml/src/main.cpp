/*
** EPITECH PROJECT, 2019
** sfml
** File description:
** main
*/

#include "InitWindow.hpp"

using namespace displayModule;

int main()
{
	InitWindow prune;
	sf::RenderWindow &win = prune.getWindow();

	while (win.isOpen())
	{
		while (win.pollEvent(prune._event))
		{
			win.clear();
			prune.createAsset("../../games/pacman/assets/sfml/", "miss.png");
			prune.createAsset("../../games/pacman/assets/sfml/", "mushroom.png");
			prune.drawAsset("miss.png", 200, 300);
			prune.drawAsset("mushroom.png", 800, 500);
			prune.createText("MS. PacMan", "MS. PacMan");
			prune.drawText("MS. PacMan", 500, 100);
			if (prune._event.type == sf::Event::Closed)
			{
				win.close();
			}
			prune.refreshWindow();
			if (prune.catchEvent() == KEY_A)
			{
				prune.stop_sound();
			}
			if (prune.catchEvent() == KEY_Z)
			{
				prune.start_sound();
			}
		}
	}
	return 0;
}