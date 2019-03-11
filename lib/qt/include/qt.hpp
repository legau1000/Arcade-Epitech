/*
** EPITECH PROJECT, 2017
** Arcarde Epitech Tek2
** File description:
** lib_qt.hpp
*/

#ifndef QT_HPP_
# define QT_HPP_

#include <QtGui/QApplication>
#include <QtGui/QStyleOptionGraphicsItem>
#include <QtGui/QWidget>
#include <QtGui/QGraphicsScene>
#include <QtGui/QGraphicsRectItem>
#include <QtGui/QPrinter>
#include <QtGui/QGraphicsView>
#include <QtGui/QGraphicsItem>
#include <QtGui/QApplication>
#include <QtGui/QtGui>
// #include "IDisplayModule.hpp"
// #include <iostream>


class qt
{
    public:
        qt();
        ~qt();

        void setpos(int nb);
    //     e_type getType();

    //     // Sprites
    //     void *createAsset(std::string &path);
    //     void drawAsset(void *sprite, int x = 0, int y = 0);
    //     void drawWindow();
    //     void destroyAsset(void *sprite);

    //     // Events
    //     e_event catchEvent();

    //     // Sounds
    //     void start_sound();
    //     void stop_sound();

    //     // void addModule(const std::string &);
    //     // void deleteModule(const std::string &);
    //     // void displayWallpaper();

    // protected:
    private:
        QGraphicsView *vue;
        QApplication *app;
        QGraphicsScene *scene;
        // e_type type;
};

#endif /* !QT_HPP_ */