#ifndef CARD_H
#define CARD_H

#include <QByteArray>
#include <QVector>
#include <QXmlStreamReader>
#include <QMap>
#include <QSet>

namespace CardProperty {
const constexpr int Twin            = 1 << 0;
const constexpr int Spy             = 1 << 1;
const constexpr int Mobility        = 1 << 2;
const constexpr int Medic           = 1 << 3;
const constexpr int Bro             = 1 << 4;
const constexpr int Enforce         = 1 << 5;
const constexpr int Execution       = 1 << 6;
const constexpr int Horn            = 1 << 7;
const constexpr int Frost           = 1 << 8;
const constexpr int Fog             = 1 << 9;
const constexpr int Rain            = 1 << 10;
const constexpr int ClearWeather    = 1 << 11;
const constexpr int Dummy           = 1 << 12;
const constexpr int Hero            = 1 << 13;

const constexpr int All             = Twin | Spy | Mobility | Medic | Bro | Enforce | Execution | Horn | Frost | Fog | Rain | ClearWeather | Dummy | Hero;

const constexpr int PropertiesCount = 14;
}

namespace CardRow {
const constexpr int Melee           = 1 << 0;
const constexpr int Ranged          = 1 << 1;
const constexpr int Sage            = 1 << 2;

const constexpr int All             = Melee | Ranged | Sage;
}

namespace CardParam {
const constexpr int Id              = 0;
const constexpr int Damage          = 1;
const constexpr int Properties      = 2;
const constexpr int Rows            = 3;
}

class Card;

typedef QSet<Card*> CardsSet;
typedef QMap<int, int> CardConfiguration;

class Card
{
    QString m_image;
    QString m_name;
    CardConfiguration m_configuration;

public:
    Card(QXmlStreamReader &configXml);

    static int getMaskSize(const int &mask);

    const inline QString getName() {
        return  m_name;
    }

    const inline QString getImage() {
        return m_image;
    }

    const QMap<int, int> &getConfiguration() const {
        return m_configuration;
    }

    inline int getConfiguration(const int &conf) const {
        return m_configuration[conf];
    }

    inline int getRow() const {
        return getConfiguration(CardParam::Rows);
    }

    inline int getId() const {
        return getConfiguration(CardParam::Id);
    }

    inline int getDamage() const {
        return getConfiguration(CardParam::Damage);
    }

    inline int getProperties() const {
        return getConfiguration(CardParam::Properties);
    }

    inline bool is(const int &property) const {
        return getConfiguration(CardParam::Properties) & property;
    }

    inline bool isTwin() const {
        return is(CardProperty::Twin);
    }

    inline bool isSpy() const {
        return is(CardProperty::Spy);
    }

    inline bool isMobility() {
        return is(CardProperty::Mobility);
    }

    inline bool isMedic() const {
        return is(CardProperty::Medic);
    }

    inline bool isBro() const {
        return is(CardProperty::Bro);
    }

    inline bool isEnforce() {
        return is(CardProperty::Enforce);
    }

    inline bool isHorn() const {
        return is(CardProperty::Horn);
    }

    inline bool isFrost() const {
        return is(CardProperty::Frost);
    }

    inline bool isFog() const {
        return is(CardProperty::Fog);
    }

    inline bool isRain() const {
        return is(CardProperty::Rain);
    }

    inline bool isClearWeather() const {
        return is(CardProperty::ClearWeather);
    }

    inline bool isDummy() const {
        return is(CardProperty::Dummy);
    }

    inline bool isHero() const {
        return is(CardProperty::Hero);
    }
};


class CardsStorage
{
private:
    CardsSet m_cards;
    QMap<int, QMap<int, CardsSet>> m_sortedCards;
    QMap<int, CardsSet*> getSetPtr(const int &param, const int &paramVal);

public:
    CardsStorage();
    virtual ~CardsStorage();

    inline const CardsSet &getCards() {
        return m_cards;
    }

    void add(Card *card);
    CardsSet get(const int &param, const int &paramVal,
                  const bool &intersection = true);
    void clear();
};

#endif // CARD_H
