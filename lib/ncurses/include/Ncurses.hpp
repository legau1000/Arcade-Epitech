/*
** EPITECH PROJECT, 2019
** pool
** File description:
** Ncurses
*/

#ifndef NCURSES_HPP_
#define NCURSES_HPP_

#include <ncurses.h>
#include <fstream>
#include <bits/stdc++.h>
#include "IDisplayModule.hpp"
#include "def.hpp"

namespace displayModule
{
    class Ncurses : public IDisplayModule
    {
        public:
            Ncurses();
            ~Ncurses();

            // Sprites
            bool createAsset(const std::string &path, const std::string &assetName);
            bool drawAsset(const std::string &assetName, int x, int y);
            bool drawText(const std::string &textName, int x, int y);

            // Window Gestion
            void refreshWindow();
            void clearScreen();

            // Create Text
            bool createText(const std::string &text, const std::string &assetName);

            // Events
            e_event catchEvent();

            // Sounds Useless On Ncurses
            /*!
             *  \brief Création d'une bande son
             *
             *  Crée un Son SANS le lancé
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
            std::unordered_map<std::string, std::string> sprites;
            e_event catchLetterEvents(int h);
            e_event catchSpecialEvents(int h);
            e_event catchArrow(int h);
            e_event catchSysButton(int h);
            std::string cutEndFile(const std::string &name);

    };
}

#endif /* !NCURSES_HPP_ */
