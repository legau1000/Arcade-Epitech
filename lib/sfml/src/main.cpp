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
		sf::Event event;
		while (win.pollEvent(event))
		{
			win.clear();
			prune.createAsset("../../games/pacman/assets/sfml/", "miss.png");
			prune.createAsset("../../games/pacman/assets/sfml/", "mushroom.png");
			prune.drawAsset("miss.png", 200, 300);
			prune.drawAsset("mushroom.png", 800, 500);
			prune.createText("MS. PacMan", "../../games/pacman/assets/sfml/pacman.ttf");
			prune.drawText("MS. PacMan", 500, 100);
			if (event.type == sf::Event::Closed)
			{
				win.close();
			}
			prune.refreshWindow();
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Z)
			{
				prune.stop_sound();
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A)
			{
				prune.start_sound();
			}
		}
	}
	return 0;
}