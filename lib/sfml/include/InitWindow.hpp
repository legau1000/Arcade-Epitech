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

class InitWindow : public displayModule::IDisplayModule
{
public:
  InitWindow();
  ~InitWindow();
  // Sprites
  void *createAsset(std::string &path);
  void drawAsset(void *sprite, int x, int y);
  void destroyAsset(void *sprite);
  void drawWindow();

  // Events
  displayModule::e_event catchEvent(){};

  // Sounds
  void start_sound();
  void stop_sound();

  sf::RenderWindow *window;
  bool displaySprite = false;
  sf::Music music;

protected:
private:
};

#endif /* !WINDOW_HPP_ */
