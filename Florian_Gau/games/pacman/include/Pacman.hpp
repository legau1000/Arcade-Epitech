/*
** EPITECH PROJECT, 2019
** pacman
** File description:
** Pacman
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

#include <iostream>
#include <memory>
#include <vector>
#include <unordered_map>
#include "IDisplayModule.hpp"
#include "IGameModule.hpp"

namespace gameModule
{
class Pacman : public IGameModule
{
  public:
	Pacman();
	~Pacman();

	displayModule::e_event game();
	bool initGame(const std::shared_ptr<displayModule::IDisplayModule> &asset);
	bool setLib(const std::shared_ptr<displayModule::IDisplayModule> &asset);

  protected:
  private:
	/*!
             *  \brief Stockage d'une map.
             *
             *  Methode qui permet de stocker la map dans un std::string.
             */
	void fillMap();
	/*!
             *  \brief Création de tous les assets.
             *
             *  Methode qui permet l'initialisation de tous les assets nécessaires au jeu.
             */
	void createAll();
	/*!
             *  \brief Dessiner la carte
             *
             *  Methode qui permet de dessiner la carte en détectant les charactères.
             */
	void drawMap();
	/*!
             *  \brief Création du pacman
             *
             *  Methode qui permet de créer le personnage principal.
             */
	void createCharacter();
	/*!
             *  \brief Détecter les mouvements du pacman
             *
             *  Methode qui permet de détecter les mouvements et les murs
			 * pour ensuite set les positions sur lequel il peut aller.
			 *  \return l'event détecter
             */
	displayModule::e_event catchPacmanEvent(displayModule::e_event ext);
	/*!
             *  \brief déplacer le pacman
             *
             *  Methode qui permet de déplacer le pacman vers le bas et
			 * d'augmenter son score
             */
	void movePacmanS();
	/*!
             *  \brief déplacer le pacman
             *
             *  Methode qui permet de déplacer le pacman vers le haut et
			 * d'augmenter son score
             */
	void movePacmanZ();
	/*!
             *  \brief déplacer le pacman
             *
             *  Methode qui permet de déplacer le pacman vers la gauche et
			 * d'augmenter son score
             */
	void movePacmanQ();
	/*!
             *  \brief déplacer le pacman
             *
             *  Methode qui permet de déplacer le pacman vers la droite et
			 * d'augmenter son score
             */
	void movePacmanD();
	/*!
             *  \brief Affichage du fantôme
             *
             *  Methode qui permet de d'afficher le fantôme et de set les positions où il peut aller
             */
	void ghost();
	/*!
             *  \brief Test pour l'IA du fantôme
             *
             *  Methode qui permet au fantôme de se déplacer tout seul.
             */
	void ghostMoove();
	/*!
             *  \brief Déplacement du charactère
             *
             *  Methode qui permet de déplacer le charactère suivant sa position.
             */
	void moovePlayer();
	/*!
             *  \brief Dessiner tous les assets
             *
             *  Methode qui permet de clear la window et d'afficher tous les assets
             */
	void drawAllAsset();
	/*!
             *  \brief Afficher le score
             *
             *  Methode qui permet d'afficher le score tout en étant responsive.
             */
	void drawScore();
	/*!
             *  \brief GameOver
             *
             *  Methode qui permet de sauvegarder le score dans un fichier texte caché.
             */
	void gameOver();
	/*!
             *  \brief Menu
             *
             *  Methode qui permet d'afficher le menu.
             */
	void menu();
	/*!
             *  \brief Comment jouer
             *
             *  Methode qui permet de créer et d'afficher les textes qui expliquent comment jouer.
             */
	void howToPlay();
	/*!
             *  \brief Afficher le score dans le menu
             *
             *  Methode qui permet d'afficher les scores présents dans le fichier .txt caché dans le menu
             */
	void drawScoreInMenu();

	int yMap;
	int x;
	int y;
	int xGhost;
	int yGhost;
	int score;
	int directionGhost;
	int block = 0;

	bool inMenu = false;

	std::shared_ptr<displayModule::IDisplayModule> _lib;
	std::string _map;
	std::string direction;
};
} // namespace gameModule

#endif /* !PACMAN_HPP_ */
