#include "deck.h"

#include <QFile>
#include <QXmlStreamReader>
#include <QDebug>
#include <QUrl>

Deck::Deck(const QString &name)
{
    QFile xmlFile(":/Decks/" + getFileName(name));
    xmlFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QXmlStreamReader xml(&xmlFile);
    while(!xml.atEnd() && !xml.hasError()) {
        QXmlStreamReader::TokenType token = xml.readNext();
        if (token == QXmlStreamReader::StartDocument)
            continue;
        if (token == QXmlStreamReader::StartElement && xml.name() == "card") {
            Card *c = new Card(xml);
            m_cards.add(c);
        }
    }
}

Deck::~Deck()
{
}
