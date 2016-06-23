#include <QDebug>
#include <QApplication>

#include "Interface/mainwindow.h"
#include "Engine/engine.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow *window = new MainWindow(540, 960);        
    window->show();

    Engine *engine = new Engine(window);

    engine->startGame();

    int ret = app.exec();
    delete window;
    delete engine;
    return ret;
}

