#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include "deck.h"

class Player : public QObject
{
    Q_OBJECT

    Deck *m_deck = NULL;

public:
    Player(QObject *parent = NULL);

    void loadDeck(Deck *deck);

    inline void turn() {
        emit turnSignal(m_deck);
    }

signals:
    void turnSignal(Deck *deck);

public slots:
    void putCardSlot(Card *card);
};

#endif // PLAYER_H
