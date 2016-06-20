#ifndef DECK_H
#define DECK_H

#include <QString>

#include "card.h"

class Deck
{
    inline QString getFileName(const QString &name) {
        return name + ".xml";
    }

    CardsStorage m_cards;

public:
    Deck(const QString &name);
    virtual ~Deck();
};

#endif // DECK_H
