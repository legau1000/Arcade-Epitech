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
#include <utility>
#include <unordered_map>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

namespace displayModule
{
class InitWindow : public IDisplayModule
{
public:
  InitWindow();
  ~InitWindow() final;
  bool createAsset(const std::string &path, const std::string &assetName) final;
  bool drawAsset(const std::string &assetName, int x, int y) final;
  void refreshWindow() final;
  void clearScreen() final;
  sf::RenderWindow &getWindow();
  sf::Event getEvent();

  // Text
  bool createText(const std::string &text, const std::string &assetName) final;
  bool drawText(const std::string &textName, int x, int y) final;

  // Events
  e_event catchEvent() final;

  // Sounds
  // Je les ai implémenté dans le .cpp mais à toi de les faire
  void createSound(const std::string &path, const std::string &soundKey) final;
  void startSound(const std::string &soundKey) final;
  void stopSound(const std::string &soundKey) final;

protected:
private:
  std::string cutEndFile(const std::string &name);
  sf::RenderWindow _window;
  std::unordered_map<std::string, sf::Texture> _mapOfSprite;
  std::unordered_map<std::string, std::string> _mapOfText;
  std::unordered_map<std::string, std::string> _mapOfMusic;
  sf::Music _music;
  sf::Texture _texture;
  sf::Event _event;
};

} // namespace displayModule

extern "C"
{
  displayModule::InitWindow *allocator()
  {
    return new displayModule::InitWindow();
  }

  void deleter(displayModule::InitWindow *ptr)
  {
    delete ptr;
  }
}

#endif /* !WINDOW_HPP_ */
