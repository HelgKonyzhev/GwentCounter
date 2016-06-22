#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtDeclarative/QDeclarativeView>
#include "../Engine/deck.h"

class MainWindow : public QDeclarativeView
{
    Q_OBJECT

    int m_width = 0;
    int m_height = 0;
    DecksSet m_decks;
    Deck *m_player1Deck = NULL;
    Deck *m_player2Deck = NULL;

    void selectPlayer1Deck(const bool &next);
    void selectPlayer2Deck(const bool &next);

public:
    MainWindow(const int &width, const int &height);

signals:
    Q_INVOKABLE void showMainMenuSignal();
    Q_INVOKABLE void hideMainMenuSignal();
    Q_INVOKABLE void player1SetDeckSignal(const QString &alias, const QString &logo);
    Q_INVOKABLE void player2SetDeckSignal(const QString &alias, const QString &logo);

public slots:
    void gameStartedSlot(const DecksSet &availableDecks);

    Q_INVOKABLE inline void player1SelectNextDeckSlot() {
        selectPlayer1Deck(true);
    }

    Q_INVOKABLE inline void player2SelectNextDeckSlot() {
        selectPlayer2Deck(true);
    }

    Q_INVOKABLE inline void player1SelectPrevDeckSlot() {
        selectPlayer1Deck(false);
    }

    Q_INVOKABLE void player2SelectPrevDeckSlot() {
        selectPlayer2Deck(false);
    }

};

#endif // MAINWINDOW_H
