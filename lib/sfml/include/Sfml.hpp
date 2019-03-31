/*
** EPITECH PROJECT, 2019
** sfml
** File description:
** Window
*/

#ifndef WINDOW_HPP_
#define WINDOW_HPP_

/*!
 * \file Sfml.hpp
 * \brief Classe de la SFML
 * \author prune.blanc@epitech.eu
 */

#include <iostream>
#include <utility>
#include <unordered_map>

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "def.hpp"
#include "IDisplayModule.hpp"

/*! \namespace displayModule
 * 
 *  espace de nommage regroupant les outils utiles au bon
 *  fonctionnement des libs
 */

namespace displayModule
{
    /*! \class Sfml
     * \brief classe décrivant les fonctions pour la Sfml
     *
     *  La classe gère la définition des méthodes pures de
     *  l'interface IDisplayModule
     */
    class Sfml : public IDisplayModule
    {
        public:
            /*!
             *  \brief Constructeur
             *
             *  Constructeur de la classe Sfml
             */
            Sfml();
            
            /*!
             *  \brief Destructeur
             *
             *  Destructeur de la classe Sfml
             */
            ~Sfml() final;

            /*!
             *  \brief Création d'un asset
             *
             *  Methode qui permet de créer un asset et de le stocker dans la
             *  map sprites
             *
             *  \param path : le chemin du fichier contenant l'asset
             *  \param assetName : le nom de l'asset
             *  \return true si l'asset a bien été créé,
             *  false sinon
             */
            bool createAsset(const std::string &path, const std::string &assetName) final;

            /*!
             *  \brief Affichage d'un asset
             *
             *  Methode qui permet d'afficher un asset aux coordonnées fournies
             *
             *  \param assetName : le nom de l'asset
             *  \param x : coordonnée abscisse
             *  \param y : coordonnée ordonnée
             *  \return true si l'asset a bien été affiché,
             *  false sinon
             */
            bool drawAsset(const std::string &assetName, int x, int y) final;

            /*!
             *  \brief Rafraichissement de l'affichage
             *
             *  Methode qui permet de rafraichir l'affichage
             */
            void refreshWindow() final;

            /*!
             *  \brief Nettoyage de l'affichage
             *
             *  Methode qui permet de nettoyer l'affichage
             */
            void clearScreen() final;

            /*!
             *  \brief Création de texte
             *
             *  Methode qui permet de créer du texte et de le stocker dans la
             *  map sprites
             *
             *  \param text : le texte à stocker
             *  \param assetName : le nom du texte
             *  \return true si le texte a bien été créé,
             *  false sinon
             */
            bool createText(const std::string &text, const std::string &assetName) final;

            /*!
             *  \brief Affichage de texte
             *
             *  Methode qui permet d'afficher du texte aux coordonnées fournies
             *
             *  \param textName : le nom du texte
             *  \param x : coordonnée abscisse
             *  \param y : coordonnée ordonnée
             *  \return true si le texte a bien été affiché,
             *  false sinon
             */
            bool drawText(const std::string &textName, int x, int y) final;

            /*!
             *  \brief Catch d'events
             *
             *  Methode qui permet de catch des events dans le programme
             *
             *  \return un displayModule::e_event
             */
            e_event catchEvent() final;

            /*!
             *  \brief Création d'un son
             *
             *  Créé un son
             */
            void createSound(const std::string &path, const std::string &soundKey) final;

            /*!
             *  \brief Lecture d'un son
             *
             *  Lance la lecture d'un son
             */
            void startSound(const std::string &soundKey) final;

            /*!
             *  \brief Arrêt d'un son
             *
             *  Arrête le son joué
             */
            void stopSound(const std::string &soundKey) final;

        protected:
        private:
            sf::RenderWindow _window; /*!< Définition de la fenêtre dans laquelle afficher*/
            std::unordered_map<std::string, sf::Texture> _mapOfSprite; /*!< Liste de sprites à afficher*/
            std::unordered_map<std::string, std::string> _mapOfText; /*!< Liste de textes à afficher*/
            std::unordered_map<std::string, std::string> _mapOfMusic; /*!< Liste de musiques à jouer*/
            sf::Music _music; /*!< Definition de la musique jouée*/
            sf::Texture _texture; /*!< Definition de la texture affichée*/
            sf::Event _event; /*!< Definition d'une variable de catch d'events*/

            /*!< Méthodes propres à la sfml*/
            std::string cutEndFile(const std::string &name);
    };

} // namespace displayModule

#endif /* !WINDOW_HPP_ */
