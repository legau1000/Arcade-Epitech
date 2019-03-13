/*
** EPITECH PROJECT, 2019
** sfml
** File description:
** main
*/

#include "InitWindow.hpp"

int main()
{
	InitWindow prune;
	std::string path = "src/18.png";

	while (prune.window->isOpen())
	{
		sf::Event event;
		while (prune.window->pollEvent(event))
		{
			prune.window->clear();
			prune.drawAsset(prune.createAsset(path), 300, 400);

			if (event.type == sf::Event::Closed)
			{
				prune.window->close();
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A)
			{
				prune.destroyAsset(prune.createAsset(path));
			}
			prune.start_sound();
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Z)
			{
				prune.stop_sound();
			}
			prune.drawWindow();
		}
	}
	return 0;
}