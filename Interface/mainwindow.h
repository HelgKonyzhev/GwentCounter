#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtDeclarative/QDeclarativeView>
#include <QDebug>
#include "../Engine/deck.h"

class MainWindow : public QDeclarativeView
{
    Q_OBJECT

    int m_width = 0;
    int m_height = 0;
    DecksSet m_decks;
    Deck *m_player1Deck = NULL;
    Deck *m_player2Deck = NULL;
    Deck *m_turningDeck = NULL;

    void selectPlayer1Deck(const bool &next);
    void selectPlayer2Deck(const bool &next);

public:
    MainWindow(const int &width, const int &height);

    Q_INVOKABLE void selectedRow(int rowId);

    Q_INVOKABLE inline int getMeleeRowId() {
        return CardRow::Melee;
    }

    Q_INVOKABLE inline int getRangedRowId() {
        return CardRow::Ranged;
    }

    Q_INVOKABLE inline int getSageRowId() {
        return CardRow::Sage;
    }

    Q_INVOKABLE inline int getWeatherRowId() {
        return CardRow::Weather;
    }

signals:
    Q_INVOKABLE void showMainMenuSignal(bool show);
    Q_INVOKABLE void player1SetDeckSignal(const QString &alias, const QString &logo);
    Q_INVOKABLE void player2SetDeckSignal(const QString &alias, const QString &logo);
    Q_INVOKABLE void showFieldSignal(bool show);
    Q_INVOKABLE void player1TurnSignal();
    Q_INVOKABLE void player2TurnSignal();
    void playersSelectedDecksSignal(Deck *player1Deck, Deck *player2Deck);
    void playerPutCardSignal(Card *card);

public slots:
    void gameStartedSlot(const DecksSet &availableDecks);
    void player1TurnSlot(Deck *deck);
    void player2TurnSlot(Deck *deck);
    void roundStartedSlot();

    Q_INVOKABLE inline void player1SelectNextDeckSlot() {
        selectPlayer1Deck(true);
    }

    Q_INVOKABLE inline void player2SelectNextDeckSlot() {
        selectPlayer2Deck(true);
    }

    Q_INVOKABLE inline void player1SelectPrevDeckSlot() {
        selectPlayer1Deck(false);
    }

    Q_INVOKABLE inline void player2SelectPrevDeckSlot() {
        selectPlayer2Deck(false);
    }

    Q_INVOKABLE inline void decksChosen() {
        emit playersSelectedDecksSignal(m_player1Deck, m_player2Deck);
    }

};

#endif // MAINWINDOW_H
