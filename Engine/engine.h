#ifndef GAME_H
#define GAME_H

#include <QObject>

#include "player.h"

class Engine : public QObject
{
    Q_OBJECT

public:
    Engine();

    void start();

public slots:
    void playersSelectedDecksSlot(const QString &player1Deck, const QString &player2Deck);
};

#endif // GAME_H
