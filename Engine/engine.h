#ifndef GAME_H
#define GAME_H

#include <QObject>

#include "player.h"
#include "deck.h"

class Engine : public QObject
{
    Q_OBJECT

    DecksSet m_decks;

public:
    Engine();
    virtual ~Engine();

    void startGame();

signals:
    void gameStartedSignal(const DecksSet &availableDecks);

public slots:
    void playersSelectedDecksSlot(const QString &player1Deck, const QString &player2Deck);
};

#endif // GAME_H
