#include <QDebug>
#include <QApplication>

#include "Interface/mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow *window = new MainWindow(540, 960);
    window->show();

//    qRegisterMetaType<CardProperty>("CardProperty");
//    qRegisterMetaType<CardRow>("CardRow");
//    qRegisterMetaType<CardParam>("CardParam");
//    qRegisterMetaType<PropertiesList>("PropertiesList");
//    qRegisterMetaType<RowsList>("RowsList");

//    QQmlApplicationEngine field;
//    field.load(QUrl(QStringLiteral("qrc:/Qml/Field.qml")));

//    QQmlApplicationEngine selectCardMenu(&field);
//    selectCardMenu.load(QUrl(QStringLiteral("qrc:/Qml/SelectCardMenu.qml")));

//    Deck deck("North");

//    qDebug() << CardProperty::All;

//    qDebug() << (16383 & 8);
    int ret = app.exec();
    delete window;
    return ret;
}

