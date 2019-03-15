/*
** EPITECH PROJECT, 2019
** sfml
** File description:
** Window
*/

#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include "def.hpp"
#include "IDisplayModule.hpp"
#include <iostream>
#include <unordered_map>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

namespace displayModule
{
class InitWindow : public IDisplayModule
{
public:
  InitWindow();
  ~InitWindow();
  bool createAsset(const std::string &path, const std::string &assetName);
  bool drawAsset(const std::string &assetName, int x, int y);
  void refreshWindow();
  sf::RenderWindow &getWindow();
  sf::Event getEvent();

  // Text
  bool createText(const std::string &text, const std::string &assetName);
  bool drawText(const std::string &textName, int x, int y);

  // Events
  e_event catchEvent();

  // Sounds
  void start_sound();
  void stop_sound();

  sf::Event _event;

protected:
private:
  sf::RenderWindow _window;
  std::unordered_map<std::string, sf::Texture> _mapOfSprite;
  std::unordered_map<std::string, sf::Font> _mapOfText;
  sf::Music _music;
};
} // namespace displayModule

#endif /* !WINDOW_HPP_ */
