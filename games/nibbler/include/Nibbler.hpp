/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** my
*/

#ifndef NIBBLER_HPP_
# define NIBBLER_HPP_

/*!
 * \file Caca.hpp
 * \brief Classe du jeu Nibbler
 * \author louis.pezet@epitech.eu
 */

#include <iostream>
#include <memory>
#include <vector>
#include <unordered_map>
#include "IDisplayModule.hpp"
#include "IGameModule.hpp"
#include "stockPrint.hpp"

/*! \namespace displayModule
 * 
 *  espace de nommage regroupant les outils utiles au bon
 *  fonctionnement des jeux
 */

namespace gameModule
{
	/*!
	 * \enum e_move
	 * \brief Constantes de déplacements
	 *
	 * e_move est une série de constantes prédéfinie pour divers  
	 * déplacements gérés par le jeu
	 */
	enum e_move
	{
		ERROR = -1,
		RIGHT,
		LEFT,
		TOP,
		BOT
	};

	/*!
	 * \enum e_scene
	 * \brief Constantes de menus
	 *
	 * e_scene est une série de constantes prédéfinie pour divers  
	 * menus gérés par le jeu
	 */
	enum e_scene
	{
		MENU = 0,
		GAME,
		GAMEOVER
	};

    /*! \class Nibbler
     * \brief classe décrivant les fonctions pour le Nibbler
     *
     *  La classe gère la définition des méthodes pures de
     *  l'interface IGameModule
     */
	class Nibbler : public IGameModule
	{
		public:
            /*!
             *  \brief Constructeur
             *
             *  Constructeur de la classe Nibbler
             */
			Nibbler();
            
            /*!
             *  \brief Destructeur
             *
             *  Destructeur de la classe Nibbler
             */
			~Nibbler();

            /*!
             *  \brief Création d'un asset
             *
             *  Methode qui permet de lancer le jeu depuis le Core
             *
             *  \return displayModule::e_event si le joueur souhaite revenir
			 *  à la sélection des jeux ou des librairies
             */
			displayModule::e_event game();

            /*!
             *  \brief Initialisation du jeu
             *
             *  Methode qui permet d'initialiser le jeu au lancement de celui-ci
             *
             * \param asset : la librairie à utiliser
             *
             *  \return true si le jeu est bien initialisé,
			 *  false sinon
             */
			bool initGame(const std::shared_ptr<displayModule::IDisplayModule> &asset);

            /*!
             *  \brief Stockage de la librairie
             *
             *  Methode qui permet de stocker ou de changer de librairie
             *
             * \param asset : la librairie à stocker
             *
             *  \return true si la librairie est bien stockée,
			 *  false sinon
             */
			bool setLib(const std::shared_ptr<displayModule::IDisplayModule> &asset);

		protected:
		private:
            /*!
             *  \brief Initialisation des assets
             *
             *  Methode qui permet de créer tous les assets et de les stocker
             *  dans la librairie
             */
			void initAssets();

            /*!
             *  \brief Initialisation des sons
             *
             *  Methode qui permet de créer tous les sons et de les stocker
             *  dans la librairie
             */
			void initSound();

            /*!
             *  \brief Création d'un sprite
             *
             *  Methode qui permet de créer un sprite et de le stocker dans la
             *  librairie
             *
             *  \param file : le nom du fichier contenant le sprite
             *  \param text : le texte à afficher en cas d'absence de fichier
             *  \param index : l'index du sprite
             */
			void initSprite(std::string file, std::string text, int index);

            /*!
             *  \brief Stockage de la map
             *
             *  Methode qui permet de récupérer la map dans un fichier et de la
             *  stocker
             *
             *  \param path : le chemin du fichier contenant la map
             *  \return true si la map a bien été stockée,
             *  false sinon
             */
			bool stockMap(const std::string &path);

            /*!
             *  \brief Lecture d'un son
             *
             *  Lance la lecture d'un son
			 * 
             *  \param key : le son à jouer
             */
			void startSound(const std::string &key);

            /*!
             *  \brief Analyse d'events de sortie
             *
             *  Methode qui permet d'analyser des events de sortie
             *  dans le jeu
			 * 
			 *  \param evt : l'event à analyser
			 * 
             *  \return true si l'event est bien sortant,
			 *  false sinon
             */
			bool exitEvent(displayModule::e_event evt);

            /*!
             *  \brief Gestion des mouvements du nibbler
             *
             *  Methode qui permet de gérer la direction des mouvements du
			 *  nibbler
			 * 
			 *  \param ev : l'event de direction à gérer
             */
			void moveNibbler(displayModule::e_event ev);

            /*!
             *  \brief Déplace le nibbler
             *
             *  Methode qui permet de déplacer le nibbler
			 * 
			 *  \param x : nouvelle abscisse du nibbler
			 *  \param y : nouvelle ordonnée du nibbler
             */
			void nibblerMove(int x, int y);

            /*!
             *  \brief Ajoute un coeur au nibbler
             *
             *  Methode qui permet d'ajouter un coeur au nibbler
			 * 
			 *  \param x : abscisse du nouveau coeur
			 *  \param y : ordonnée du nouveau coeur
             */
			void addCore(int x, int y);

            /*!
             *  \brief Ajoute un nouveau fruit
             *
             *  Methode qui permet d'ajouter un nouveau fruit sur la map
             */
			void setFoodPosition(void);

            /*!
             *  \brief Affiche le menu
             *
             *  Methode qui permet d'afficher le menu
             */
			void printMenu();

            /*!
             *  \brief Affiche le jeu
             *
             *  Methode qui permet d'afficher le jeu
             */
			void printGame();

            /*!
             *  \brief Affiche le game over
             *
             *  Methode qui permet d'afficher le game over
             */
			void printGameover();

            /*!
             *  \brief Affiche la map
             *
             *  Methode qui permet d'afficher la map
             */
			void printMap();

            /*!
             *  \brief Affiche le joueur / nibbler
             *
             *  Methode qui permet d'afficher le joueur / nibbler
             */
			void printPlayer();

            /*!
             *  \brief Affiche le fruit
             *
             *  Methode qui permet d'afficher le fruit
             */
			void printFood();

            /*!
             *  \brief Affiche le score
             *
             *  Methode qui permet d'afficher le score
             */
			void printScore();

            /*!
             *  \brief Détecte et gére un mur ou un fruit
             *
             *  Methode qui permet de détecter et de gérer si le nibbler tombe
			 *  sur un mur ou un fruit
             */
			void detectNibbler();

            /*!
             *  \brief Détecte une morsure de queue
             *
             *  Methode qui permet de détecter si le nibbler se mort la queue
			 * 
			 *  /return true si le nibbler se mort la queue,
			 * 	false sinon
             */
			bool detectMe();

			std::shared_ptr<displayModule::IDisplayModule> _graph; /*!< Définition de la librairie*/
			std::vector<std::string> _map; /*!< Définition de la map*/
			std::vector<stockPrint> _allNibblerSprite; /*!< Définition de la liste des sprites*/
			std::vector<stockPrint> _nibbler; /*!< Définition du nibbler*/

			e_move _move; /*!< Définition de la sauvegarde du mouvement*/
			e_scene _scene = MENU; /*!< Définition de la scene actuelle*/
			int x_food; /*!< Définition de l'abscisse du fruit*/
			int y_food; /*!< Définition de l'ordonnée du fruit*/
			int _score; /*!< Définition du score*/
	};
}

#endif //OOP_ARCADE_2018_NIBBLER_HPP