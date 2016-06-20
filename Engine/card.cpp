#include "card.h"

#include <QDebug>

using namespace CardProperty;
using namespace CardParam;

Card::Card(QXmlStreamReader &configXml)
{
    while(!configXml.atEnd() && !configXml.hasError()) {
        QXmlStreamReader::TokenType token = configXml.readNext();
        if(token == QXmlStreamReader::EndElement && configXml.name() == "card") {
            break;
        }
        if(token == QXmlStreamReader::StartElement) {
            if(configXml.name() == "rows") {
                continue;
            } else if(configXml.name() == "melee") {
                m_configuration[CardParam::Rows] |= CardRow::Melee;
            } else if(configXml.name() == "ranged") {
                m_configuration[CardParam::Rows] |= CardRow::Ranged;
            } else if(configXml.name() == "sage") {
                m_configuration[CardParam::Rows] |= CardRow::Sage;
            } else if(configXml.name() == "bro") {
                m_configuration[CardParam::Properties] |= Bro;
            } else {
                QStringRef param = configXml.name();
                if(param == "id") {
                    m_configuration[CardParam::Id] = param.toInt();
                } else if(param == "name") {
                    m_name = configXml.readElementText();
                } else if(param == "image") {
                    m_image = configXml.readElementText();
                } else if(param == "damage") {
                    m_configuration[CardParam::Damage] = configXml.readElementText().toInt();
                }
            }
        }
    }
}

int Card::getMaskSize(const int &mask)  {
    int size = 0;
    for(; ((unsigned)size < (sizeof(int) * 8)) && (mask & (1 << size)); size++);
    return size;
}


CardsStorage::CardsStorage()
{
}

CardsStorage::~CardsStorage()
{
    clear();
}

QMap<int, CardsSet*> CardsStorage::getSetPtr(const int &param, const int &paramVal)
{
    QMap<int, CardsSet*> ret;
    int paramsMaskSize = 0;
    switch(param) {
    case Properties:
        paramsMaskSize = Card::getMaskSize(CardProperty::All);
    case Rows:
        paramsMaskSize = Card::getMaskSize(CardRow::All);
        for(int i = 0; i < paramsMaskSize; i++) {
            int prop = 1 << i;
            if(paramVal & prop) {
                ret[prop] = &(m_sortedCards[param][prop]);
            }
        }
    default:
        ret[paramVal] = &(m_sortedCards[param][paramVal]);
    }

    return ret;
}

void CardsStorage::add(Card *card)
{
    const CardConfiguration &conf = card->getConfiguration();
    foreach(const int &key, conf.keys()) {
        QMap<int, CardsSet*> sets = getSetPtr(key, conf[key]);
        foreach (const int &setId, sets.keys()) {
            sets[setId]->insert(card);
        }
    }
    m_cards.insert(card);
}

CardsSet CardsStorage::get(const int &param, const int &paramVal, const bool &intersection)
{
    QSet<Card*> ret = m_cards;
    QMap<int, CardsSet*> sets = getSetPtr(param, paramVal);
    foreach (const int &setId, sets.keys()) {
        if(intersection)
            ret.intersect(*(sets[setId]));
        else
            ret.unite(*(sets[setId]));
    }
    return ret;
}

void CardsStorage::clear()
{
    for(auto &it: m_cards) {
        delete it;
    }
}
