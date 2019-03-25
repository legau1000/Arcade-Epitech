/*
** EPITECH PROJECT, 2019
** sfml
** File description:
** InitWindow
*/

#include "InitWindow.hpp"

using namespace displayModule;

InitWindow::InitWindow() : _window(sf::VideoMode(1920, 1080), "Let's play!", sf::Style::Resize | sf::Style::Close)
{
}

std::string InitWindow::cutEndFile(const std::string &name)
{
	std::size_t pos = name.find(".");

	if (pos == std::string::npos)
		return (name);
	return (name.substr(0, pos));
}

bool InitWindow::createAsset(const std::string &path, const std::string &assetName)
{
	std::string realPath = path + "/2d/" + assetName + ".png";

	if (!this->_texture.loadFromFile(realPath))
		return false;
	this->_mapOfSprite.insert(std::pair<std::string, sf::Texture>(assetName, this->_texture));
	return true;
}

bool InitWindow::drawAsset(const std::string &assetName, int x, int y)
{
	sf::Sprite sprite;
	sprite.setTexture(this->_mapOfSprite.find(assetName)->second);
	sprite.setPosition(x * 32, y * 32);
	this->_window.draw(sprite);
	return true;
}

void InitWindow::refreshWindow()
{
	this->_window.display();
}

void InitWindow::clearScreen()
{
	this->_window.clear();
}

// Text
bool InitWindow::createText(const std::string &text, const std::string &assetName)
{
	this->_mapOfText.insert(std::pair<std::string, std::string>(assetName, text));
	return true;
}

bool InitWindow::drawText(const std::string &textName, int x, int y)
{
	this->_font.loadFromFile("./Games/pacman/assets/2d/pacman.ttf");
	this->_text.setFont(this->_font);
	this->_text.setString(this->_mapOfText.find(textName)->second);
	this->_text.setCharacterSize(100);
	this->_text.setFillColor(sf::Color::Yellow);
	this->_text.setStyle(sf::Text::Bold);
	this->_text.setPosition(x * 32, y * 32);
	this->_window.draw(this->_text);
	return true;
}

// Events
e_event InitWindow::catchEvent()
{
	while (this->_window.pollEvent(this->_event))
	{
		if (this->_event.type == sf::Event::Closed)
			return ESCAPE;
		if (this->_event.type == sf::Event::KeyPressed)
		{
			if (this->_event.key.code == sf::Keyboard::A)
				return KEY_A;
			if (this->_event.key.code == sf::Keyboard::B)
				return KEY_B;
			if (this->_event.key.code == sf::Keyboard::C)
				return KEY_C;
			if (this->_event.key.code == sf::Keyboard::D)
				return KEY_D;
			if (this->_event.key.code == sf::Keyboard::E)
				return KEY_E;
			if (this->_event.key.code == sf::Keyboard::F)
				return KEY_F;
			if (this->_event.key.code == sf::Keyboard::G)
				return KEY_G;
			if (this->_event.key.code == sf::Keyboard::H)
				return KEY_H;
			if (this->_event.key.code == sf::Keyboard::I)
				return KEY_I;
			if (this->_event.key.code == sf::Keyboard::J)
				return KEY_J;
			if (this->_event.key.code == sf::Keyboard::K)
				return KEY_K;
			if (this->_event.key.code == sf::Keyboard::L)
				return KEY_L;
			if (this->_event.key.code == sf::Keyboard::M)
				return KEY_M;
			if (this->_event.key.code == sf::Keyboard::N)
				return KEY_N;
			if (this->_event.key.code == sf::Keyboard::O)
				return KEY_O;
			if (this->_event.key.code == sf::Keyboard::P)
				return KEY_P;
			if (this->_event.key.code == sf::Keyboard::Q)
				return KEY_Q;
			if (this->_event.key.code == sf::Keyboard::R)
				return KEY_R;
			if (this->_event.key.code == sf::Keyboard::S)
				return KEY_S;
			if (this->_event.key.code == sf::Keyboard::T)
				return KEY_T;
			if (this->_event.key.code == sf::Keyboard::U)
				return KEY_U;
			if (this->_event.key.code == sf::Keyboard::V)
				return KEY_V;
			if (this->_event.key.code == sf::Keyboard::W)
				return KEY_W;
			if (this->_event.key.code == sf::Keyboard::X)
				return KEY_X;
			if (this->_event.key.code == sf::Keyboard::Y)
				return KEY_Y;
			if (this->_event.key.code == sf::Keyboard::Z)
				return KEY_Z;
			if (this->_event.key.code == sf::Keyboard::Down)
				return ARROW_DOWN;
			if (this->_event.key.code == sf::Keyboard::Up)
				return ARROW_UP;
			if (this->_event.key.code == sf::Keyboard::Left)
				return ARROW_LEFT;
			if (this->_event.key.code == sf::Keyboard::Right)
				return ARROW_RIGHT;
			if (this->_event.key.code == sf::Keyboard::Space)
				return SPACE;
			if (this->_event.key.code == sf::Keyboard::Enter)
				return ENTER;
			if (this->_event.key.code == sf::Keyboard::Escape)
				return ESCAPE;
		}
	}
	return (NOTHING);
}

void InitWindow::createSound(const std::string &path, const std::string &soundKey)
{
	std::string realPath = path + "/2d/" + soundKey;
	std::string filename = this->cutEndFile(soundKey);
	_mapOfMusic.insert(std::pair<std::string, std::string>(filename, realPath));
}

void InitWindow::startSound(const std::string &soundKey)
{
	this->_music.setVolume(50);
	this->_music.openFromFile(this->_mapOfMusic.find(soundKey)->second);
	this->_music.play();
}

void InitWindow::stopSound(UNUSED const std::string &soundKey)
{
	this->_music.stop();
}

InitWindow::~InitWindow()
{
	this->_window.close();
}
