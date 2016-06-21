#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtDeclarative/QDeclarativeView>

class MainWindow : public QDeclarativeView
{
    int m_width = 0;
    int m_height = 0;
public:
    MainWindow(const int &width, const int &height);
};

#endif // MAINWINDOW_H
