#include "engine.h"
#include <QDir>
#include <QDebug>

Engine::Engine()
{
    QDir decksDir(":/Decks");
    for(unsigned i = 0; i < decksDir.count(); i++) {
        m_decks.insert(new Deck(decksDir[i]));
    }
}

Engine::~Engine()
{
    for(auto &it: m_decks) {
        delete it;
    }
}

void Engine::startGame()
{
    emit gameStartedSignal(m_decks);
}

void Engine::playersSelectedDecksSlot(const QString &player1Deck, const QString &player2Deck)
{

}
