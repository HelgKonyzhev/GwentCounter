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
                m_configuration[CardParam::Rows] = CardRow::Melee;
            } else if(configXml.name() == "ranged") {
                m_configuration[CardParam::Rows] = CardRow::Ranged;
            } else if(configXml.name() == "sage") {
                m_configuration[CardParam::Rows] = CardRow::Sage;
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


CardsStorage::CardsStorage()
{
}

CardsStorage::~CardsStorage()
{
    clear();
}

QMap<int, CardsList*> CardsStorage::getPtr(const int &param, const int &paramVal)
{
    QMap<int, CardsList*> ret;
    if(param != Properties) {
        ret[paramVal] = &(m_sortedCards[param][paramVal]);
    } else {
        for(int i = 0; i < PropertiesCount; i++) {
            int prop = 1 << i;
            if(paramVal & prop) {
                ret[prop] = &(m_sortedCards[param][prop]);
            }
        }
    }
    return ret;
}

void CardsStorage::add(Card *card)
{
    const CardConfiguration &conf = card->getConfiguration();
    foreach(const int &key, conf.keys()) {
        QMap<int, CardsList*> lists = getPtr(key, conf[key]);
        foreach (const int &listId, lists.keys()) {
            lists[listId]->append(card);
        }
    }
    m_cards.append(card);
}

CardsList CardsStorage::get(const int &param, const int &paramVal)
{
    CardsList ret;
    QMap<int, CardsList*> lists = getPtr(param, paramVal);
    foreach (const int &listId, lists.keys()) {
        ret.append(*(lists[listId]));
    }
    return ret;
}

void CardsStorage::clear()
{
    for(auto &it: m_cards) {
        delete it;
    }
}
