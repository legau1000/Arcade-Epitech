#include <string>
#include <iostream>
#include "include/qt.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QLine ligne(50, 50, 200, 200);
    QGraphicsScene *scene = new QGraphicsScene();

    scene->addLine(ligne);

    QGraphicsView vue(scene);
    vue.resize(1920, 1080);
    vue.show();

    // delete scene;
    return app.exec();
}