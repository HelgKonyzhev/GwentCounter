#include "player.h"

Player::Player(QObject *parent)
    :QObject(parent)
{
}

void Player::loadDeck(Deck *deck)
{
    m_deck = deck;
    m_deck->load();
}

void Player::putCardSlot(Card *card)
{

}
