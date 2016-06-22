#ifndef DECK_H
#define DECK_H

#include <QString>

#include "card.h"

class Deck
{
    QString m_configPath;
    QString m_alias;
    QString m_logo;
    CardsStorage m_cards;

public:
    Deck(const QString &fileName);
    virtual ~Deck();

    void load();

    inline const QString &getAlias() {
        return m_alias;
    }

    inline const QString &getLogo() {
        return m_logo;
    }
};

typedef QSet<Deck*> DecksSet;


#endif // DECK_H
