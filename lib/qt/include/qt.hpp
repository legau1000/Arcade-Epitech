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
#include "IDisplayModule.hpp"
// #include <iostream>


class qt : virtual public IDisplayModule
{
    public:
        qt();
        ~qt();
    
        e_type getType() {};

        // Sprites
        void createAsset(std::string &path) {};
        void drawAsset(void *sprite) {};
        void destroyAsset(void *sprite) {};
        void drawWindow() {};

        // Events
        void catchEvent() {};

        // Sounds
        void start_sound() {};
        void stop_sound() {};

        void setpos(int index);

    protected:

    private:
        QApplication *app;
        QGraphicsScene *scene;
        e_type type;
};

#endif /* !QT_HPP_ */