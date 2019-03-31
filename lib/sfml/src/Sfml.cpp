/*
** EPITECH PROJECT, 2019
** sfml
** File description:
** InitWindow
*/

#include <memory>
#include "Sfml.hpp"

using namespace displayModule;

Sfml::Sfml() : _window(sf::VideoMode(1920, 1080), "Let's play!", sf::Style::Resize | sf::Style::Close)
{
}

std::string Sfml::cutEndFile(const std::string &name)
{
	std::size_t pos = name.find(".");

	if (pos == std::string::npos)
		return (name);
	return (name.substr(0, pos));
}

bool Sfml::createAsset(const std::string &path, const std::string &assetName)
{
	std::string realPath = path + "/2d/" + assetName + ".png";

	if (!this->_texture.loadFromFile(realPath))
		return false;
	this->_mapOfSprite.insert(std::pair<std::string, sf::Texture>(assetName, this->_texture));
	return true;
}

bool Sfml::drawAsset(const std::string &assetName, int x, int y)
{
	sf::Sprite sprite;
	sprite.setTexture(this->_mapOfSprite.find(assetName)->second);
	sprite.setPosition(x * 32, y * 32);
	this->_window.draw(sprite);
	return true;
}

void Sfml::refreshWindow()
{
	this->_window.display();
}

void Sfml::clearScreen()
{
	this->_window.clear();
}

// Text
bool Sfml::createText(const std::string &text, const std::string &assetName)
{
	this->_mapOfText.insert(std::pair<std::string, std::string>(assetName, text));
	return true;
}

bool Sfml::drawText(const std::string &textName, int x, int y)
{
	sf::Text _text;
	sf::Font _font;

	_font.loadFromFile("./.fonts/default.ttf");
	_text.setFont(_font);
	_text.setString(_mapOfText.find(textName)->second);
	_text.setCharacterSize(30);
	_text.setFillColor(sf::Color::White);
	_text.setStyle(sf::Text::Bold);
	_text.setPosition(x * 32, y * 32);
	_window.draw(_text);
	return true;
}

// Events
e_event Sfml::catchEvent()
{
	while (this->_window.pollEvent(this->_event))
	{
		if (this->_event.type == sf::Event::Closed)
			return ESCAPE;
		if (this->_event.type == sf::Event::KeyPressed)
		{
			switch (this->_event.key.code)
			{
			case sf::Keyboard::Enter:
				return (displayModule::ENTER);
			case sf::Keyboard::Escape:
				return (displayModule::ESCAPE);
			case sf::Keyboard::A:
				return (displayModule::KEY_A);
			case sf::Keyboard::B:
				return (displayModule::KEY_B);
			case sf::Keyboard::C:
				return (displayModule::KEY_C);
			case sf::Keyboard::D:
				return (displayModule::KEY_D);
			case sf::Keyboard::E:
				return (displayModule::KEY_E);
			case sf::Keyboard::F:
				return (displayModule::KEY_F);
			case sf::Keyboard::G:
				return (displayModule::KEY_G);
			case sf::Keyboard::H:
				return (displayModule::KEY_H);
			case sf::Keyboard::I:
				return (displayModule::KEY_I);
			case sf::Keyboard::J:
				return (displayModule::KEY_J);
			case sf::Keyboard::K:
				return (displayModule::KEY_K);
			case sf::Keyboard::L:
				return (displayModule::KEY_L);
			case sf::Keyboard::M:
				return (displayModule::KEY_M);
			case sf::Keyboard::N:
				return (displayModule::KEY_N);
			case sf::Keyboard::O:
				return (displayModule::KEY_O);
			case sf::Keyboard::P:
				return (displayModule::KEY_P);
			case sf::Keyboard::Q:
				return (displayModule::KEY_Q);
			case sf::Keyboard::R:
				return (displayModule::KEY_R);
			case sf::Keyboard::S:
				return (displayModule::KEY_S);
			case sf::Keyboard::T:
				return (displayModule::KEY_T);
			case sf::Keyboard::U:
				return (displayModule::KEY_U);
			case sf::Keyboard::V:
				return (displayModule::KEY_V);
			case sf::Keyboard::W:
				return (displayModule::KEY_W);
			case sf::Keyboard::X:
				return (displayModule::KEY_X);
			case sf::Keyboard::Y:
				return (displayModule::KEY_Y);
			case sf::Keyboard::Z:
				return (displayModule::KEY_Z);
			case sf::Keyboard::Up:
				return (displayModule::ARROW_UP);
			case sf::Keyboard::Down:
				return (displayModule::ARROW_DOWN);
			case sf::Keyboard::Right:
				return (displayModule::ARROW_RIGHT);
			case sf::Keyboard::Left:
				return (displayModule::ARROW_LEFT);
			case sf::Keyboard::Space:
				return (displayModule::SPACE);
			default:
				return (displayModule::NOTHING);
			}
		}
	}
	return (displayModule::NOTHING);
}

void Sfml::createSound(const std::string &path, const std::string &soundKey)
{
	std::string realPath = path + "/2d/" + soundKey + ".ogg";
	_mapOfMusic.insert(std::pair<std::string, std::string>(soundKey, realPath));
}

void Sfml::startSound(const std::string &soundKey)
{
	this->_music.setVolume(50);
	this->_music.openFromFile(this->_mapOfMusic.find(soundKey)->second);
	this->_music.play();
}

void Sfml::stopSound(UNUSED const std::string &soundKey)
{
	this->_music.stop();
}

Sfml::~Sfml()
{
	this->_window.close();
}

extern "C"
{
	std::shared_ptr<IDisplayModule> allocator()
	{
		return std::make_shared<Sfml>();
	}
}