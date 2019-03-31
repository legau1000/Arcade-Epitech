/*
** EPITECH PROJECT, 2019
** pool
** File description:
** Ncurses
*/

#ifndef NCURSES_HPP_
#define NCURSES_HPP_

/*!
 * \file Sfml.hpp
 * \brief Classe de la SFML
 * \author florian.gau@epitech.eu
 */

#include <ncurses.h>
#include <fstream>
#include <memory>
#include <unordered_map>
#include "IDisplayModule.hpp"
// #include "def.hpp"

/*! \namespace displayModule
 * 
 *  espace de nommage regroupant les outils utiles au bon
 *  fonctionnement des libs
 */

namespace displayModule
{
    /*! \class Ncurses
     * \brief classe décrivant les fonctions pour la ncurses
     *
     *  La classe gère la définition des méthodes pures de
     *  l'interface IDisplayModule
     */
    class Ncurses : public IDisplayModule
    {
        public:
            /*!
             *  \brief Constructeur
             *
             *  Constructeur de la classe Ncurses
             */
            Ncurses();
            
            /*!
             *  \brief Destructeur
             *
             *  Destructeur de la classe Ncurses
             */
            ~Ncurses();

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
            bool createAsset(const std::string &path, const std::string &assetName);

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
            bool drawAsset(const std::string &assetName, int x, int y);

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
            bool drawText(const std::string &textName, int x, int y);

            /*!
             *  \brief Rafraichissement de l'affichage
             *
             *  Methode qui permet de rafraichir l'affichage
             */
            void refreshWindow();

            /*!
             *  \brief Nettoyage de l'affichage
             *
             *  Methode qui permet de nettoyer l'affichage
             */
            void clearScreen();

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
            bool createText(const std::string &text, const std::string &assetName);

            /*!
             *  \brief Catch d'events
             *
             *  Methode qui permet de catch des events dans le programme
             *
             *  \return un displayModule::e_event
             */
            e_event catchEvent();

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
            std::unordered_map<std::string, std::string> sprites; /*!< Liste de sprites à afficher*/

            /*!< Méthodes propres à la ncurses*/
            e_event catchLetterEvents(int h);
            e_event catchSpecialEvents(int h);
            e_event catchArrow(int h);
            e_event catchSysButton(int h);
            std::string cutEndFile(const std::string &name);
    };

}

#endif /* !NCURSES_HPP_ */
