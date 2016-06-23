#ifndef GAME_H
#define GAME_H

#include <QObject>

#include "player.h"
#include "deck.h"
#include "Interface/mainwindow.h"

class Engine : public QObject
{
    Q_OBJECT

    DecksSet m_decks;
    MainWindow *m_window = NULL;
    Player *m_player1 = NULL;
    Player *m_player2 = NULL;
    Player *m_turningPlayer = NULL;

public:
    Engine(MainWindow *window);
    virtual ~Engine();

    void startGame();
    void startRound();
    void nextTurn(const bool &randomPlayer);

signals:
    void gameStartedSignal(const DecksSet &availableDecks);
    void roundStartedSignal();

public slots:
    void playersSelectedDecksSlot(Deck *player1Deck, Deck *player2Deck);
};

#endif // GAME_H
