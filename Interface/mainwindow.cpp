#include "mainwindow.h"
#include <QDeclarativeContext>

MainWindow::MainWindow(const int &width, const int &height)
    :QDeclarativeView()
{
    setWindowFlags(Qt::FramelessWindowHint);
    m_width = width;
    m_height = height;
    QDeclarativeView::setGeometry(0, 0, m_width, m_height);
    rootContext()->setContextProperty("windowWidth", QVariant(m_width));
    rootContext()->setContextProperty("windowHeight", QVariant(m_height));
    rootContext()->setContextProperty("resolution", QVariant(QString::number(m_width) + "x" + QString::number(m_height)));
    rootContext()->setContextProperty("windowContext", this);
    setSource(QUrl("qrc:/Interface/Qml/MainWindow.qml"));
}

