#include "deck.h"

#include <QXmlStreamReader>
#include <QDebug>
#include <QUrl>
#include <QFile>

Deck::Deck(const QString &fileName)
{
    m_configPath = ":/Decks/" + fileName;
    QFile config(m_configPath);
    config.open(QIODevice::ReadOnly | QIODevice::Text);
    QXmlStreamReader xml(&config);
    while(!xml.atEnd() && !xml.hasError()) {
        QXmlStreamReader::TokenType token = xml.readNext();
        if (token == QXmlStreamReader::StartDocument)
            continue;
        if (token == QXmlStreamReader::StartElement && xml.name() == "alias") {
            m_alias = QString::fromUtf8(xml.readElementText().toStdString().c_str());
        } else if(token == QXmlStreamReader::StartElement && xml.name() == "logo") {
            m_logo = QString::fromUtf8(xml.readElementText().toStdString().c_str());
        }
        if(!m_alias.isEmpty() && !m_logo.isEmpty())
            break;
    }
    config.close();
}

Deck::~Deck()
{
}

void Deck::load()
{
    QFile config(m_configPath);
    config.open(QIODevice::ReadOnly | QIODevice::Text);
    QXmlStreamReader xml(&config);
    while(!xml.atEnd() && !xml.hasError()) {
        QXmlStreamReader::TokenType token = xml.readNext();
        if (token == QXmlStreamReader::StartDocument)
            continue;
        if (token == QXmlStreamReader::StartElement && xml.name() == "card") {
            Card *c = new Card(xml);
            m_cards.add(c);
        }
    }
    config.close();
}
