#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>

#include "Engine/deck.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

//    qRegisterMetaType<CardProperty>("CardProperty");
//    qRegisterMetaType<CardRow>("CardRow");
//    qRegisterMetaType<CardParam>("CardParam");
//    qRegisterMetaType<PropertiesList>("PropertiesList");
//    qRegisterMetaType<RowsList>("RowsList");

//    QQmlApplicationEngine field;
//    field.load(QUrl(QStringLiteral("qrc:/Qml/Field.qml")));

//    QQmlApplicationEngine selectCardMenu(&field);
//    selectCardMenu.load(QUrl(QStringLiteral("qrc:/Qml/SelectCardMenu.qml")));

    Deck deck("North");

//    qDebug() << CardProperty::All;

//    qDebug() << (16383 & 8);
//    int ret = app.exec();
//    return ret;
    return 0;
}
