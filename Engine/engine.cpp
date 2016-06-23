#include "engine.h"
#include <QDir>
#include <QDebug>

Engine::Engine(MainWindow *window)
{
    m_window = window;
    QDir decksDir(":/Decks");
    for(unsigned i = 0; i < decksDir.count(); i++) {
        m_decks.insert(new Deck(decksDir[i]));
    }

    m_player1 = new Player(this);
    m_player2 = new Player(this);

    connect(this, SIGNAL(gameStartedSignal(const DecksSet&)),
            window, SLOT(gameStartedSlot(const DecksSet&)));
    connect(window, SIGNAL(playersSelectedDecksSignal(Deck*,Deck*)),
            this, SLOT(playersSelectedDecksSlot(Deck*,Deck*)));
    connect(m_player1, SIGNAL(turnSignal(Deck*)),
            window, SLOT(player1TurnSlot(Deck*)));
    connect(m_player2, SIGNAL(turnSignal(Deck*)),
            window, SLOT(player2TurnSlot(Deck*)));
    connect(this, SIGNAL(roundStartedSignal()),
            window, SLOT(roundStartedSlot()));
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

void Engine::startRound()
{
    emit roundStartedSignal();
}

void Engine::nextTurn(const bool &randomPlayer)
{
    if(randomPlayer || !m_turningPlayer) {
        srand(time(NULL));
        int random = rand() % 100;
        m_turningPlayer = random > 49 ? m_player1 : m_player2;
    } else {
        m_turningPlayer = (m_turningPlayer == m_player1) ? m_player2 : m_player1;
    }
    m_turningPlayer->turn();
}

void Engine::playersSelectedDecksSlot(Deck *player1Deck, Deck *player2Deck)
{
    m_player1->loadDeck(player1Deck);
    m_player2->loadDeck(player2Deck);
    startRound();
    nextTurn(true);
}
