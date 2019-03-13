/*
** EPITECH PROJECT, 2019
** sfml
** File description:
** InitWindow
*/

#include "InitWindow.hpp"

InitWindow::InitWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "SFML!", sf::Style::Resize | sf::Style::Close);
}

void InitWindow::drawWindow()
{
	this->window->display();
}

void *InitWindow::createAsset(std::string &path)
{
	sf::Texture *texture = new sf::Texture();
	texture->loadFromFile("./src/18.png");
	return (texture);
}

void InitWindow::drawAsset(void *sprite, int x, int y)
{
	try
	{
		if (!this->displaySprite)
		{
			sf::Sprite newSprite(*(sf::Texture *)sprite);
			newSprite.setPosition(x, y);
			this->window->draw(newSprite);
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what();
	}
}

void InitWindow::destroyAsset(void *sprite)
{
	this->displaySprite = true;
}

void InitWindow::start_sound()
{
	if (!this->music.openFromFile("./src/gamesong.ogg"))
		exit;
	this->music.setVolume(50);
	this->music.play();
}
void InitWindow::stop_sound()
{
	this->music.stop();
}

InitWindow::~InitWindow()
{
}
