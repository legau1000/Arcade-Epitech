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
	std::string realPath = path + "/2d/" + assetName;
	std::string filename = this->cutEndFile(assetName);

	this->_texture.loadFromFile(realPath);
	this->_mapOfSprite.insert(std::pair<std::string, sf::Texture>(filename, this->_texture));
	return true;
}

bool InitWindow::drawAsset(const std::string &assetName, int x, int y)
{
	this->_sprite.setTexture(this->_mapOfSprite.find(assetName)->second);
	this->_sprite.setPosition(x, y);
	this->_window.draw(this->_sprite);
	return true;
}

void InitWindow::refreshWindow()
{
	this->_window.display();
	this->_window.clear();
}

sf::RenderWindow &InitWindow::getWindow()
{
	return this->_window;
}

sf::Event InitWindow::getEvent()
{
	return this->_event;
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
	this->_text.setPosition(x, y);
	this->_window.draw(this->_text);
	return true;
}

// Events
e_event InitWindow::catchEvent()
{
	while (this->_window.pollEvent(this->_event))
	{
		if (this->_event.type == sf::Event::KeyPressed)
		{
			if (this->_event.key.code == sf::Keyboard::A)
			{
				std::cout << "prout1" << std::endl;
				return KEY_A;
			}
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
			{
				return ARROW_LEFT;
			}
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

//Sounds
void InitWindow::start_sound()
{
	this->_music.openFromFile("./Games/pacman/assets/2d/pacman.ogg");
	this->_music.setVolume(50);
	this->_music.play();
}
void InitWindow::stop_sound()
{
	this->_music.stop();
}

InitWindow::~InitWindow()
{
	this->_window.close();
}
