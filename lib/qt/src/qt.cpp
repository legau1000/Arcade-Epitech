/*
** EPITECH PROJECT, 2017
** Arcarde Epitech Tek2
** File description:
** lib_qt.cpp
*/

#include <unistd.h>
#include <qt.hpp>

qt::qt()
{
    int argc = 1;
    char *argv[1] = {"Arcade"};
    QLine ligne(50, 50, 200, 200);
    this->app = new QApplication(argc, argv);
    this->scene = new QGraphicsScene();
	// pid_t cpid = 0;

    scene->addLine(ligne);
    scene->addText("Hello world !");
    
    this->vue = new QGraphicsView(scene);
    this->vue->resize(1920, 1080);
    this->vue->show();
    // scene->removeItem(item);
	// cpid = fork();
    // if (cpid == 0) {
    //     printf("%d\n", cpid);
    this->app->exec();
    this->app->closeAllWindows();
    this->app->exit(84);
    //     exit(0);
    // }
}

void qt::setpos(int index)
{
    QLine ligne(50, 50, index, 200);
    this->scene->addLine(ligne);
    this->vue->show();
}

// void qt::setpos(int index)
// {
//     QGraphicsItem *item;
//     QPixmap monPixmap("logo.jpg");

//     item = this->scene->addPixmap(monPixmap); //load picture
//     item->setPos(index, index);
// }

qt::~qt()
{
    this->app->exit();
}