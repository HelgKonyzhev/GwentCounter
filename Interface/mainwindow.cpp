#include "mainwindow.h"
#include <QDeclarativeContext>

MainWindow::MainWindow(const int &width, const int &height)
    :QDeclarativeView()
{
    setWindowFlags(Qt::FramelessWindowHint);
    m_width = width;
    m_height = height;
    QDeclarativeView::setGeometry(0, 0, m_width, m_height);
    rootContext()->setContextProperty("windowWidth", QVariant(m_width));
    rootContext()->setContextProperty("windowHeight", QVariant(m_height));
    rootContext()->setContextProperty("resolution", QVariant(QString::number(m_width) + "x" + QString::number(m_height)));
    rootContext()->setContextProperty("windowContext", this);
    setSource(QUrl("qrc:/Interface/Qml/MainWindow.qml"));
}

static Deck *selectDeck(Deck *currentDeck, const DecksSet &decks, const bool &next) {
    Deck *ret = *(decks.begin());
    if(currentDeck != NULL) {
        auto it = decks.find(currentDeck);
        if(next) {
            if(++it == decks.end())
                ret = *(decks.begin());
            else
                ret = *(it);
        } else {
            if(it == decks.begin())
                ret = *(--decks.end());
            else
                ret = *(--it);
        }
    }
    return ret;
}

void MainWindow::selectPlayer1Deck(const bool &next)
{
    m_player1Deck = selectDeck(m_player1Deck, m_decks, next);
    if(m_player1Deck)
        emit player1SetDeckSignal(m_player1Deck->getAlias(), m_player1Deck->getLogo());
}

void MainWindow::selectPlayer2Deck(const bool &next)
{
    m_player2Deck = selectDeck(m_player2Deck, m_decks, next);
    if(m_player2Deck)
        emit player2SetDeckSignal(m_player2Deck->getAlias(), m_player2Deck->getLogo());
}

void MainWindow::gameStartedSlot(const DecksSet &availableDecks)
{
    m_decks = availableDecks;
    selectPlayer1Deck(true);
    selectPlayer2Deck(true);
    selectPlayer2Deck(true);
}

void MainWindow::player1TurnSlot(Deck *deck)
{
    m_turningDeck = deck;
    emit player1TurnSignal();
}

void MainWindow::player2TurnSlot(Deck *deck)
{
    m_turningDeck = deck;
    emit player2TurnSignal();
}

void MainWindow::roundStartedSlot()
{
    emit showMainMenuSignal(false);
    emit showFieldSignal(true);
}

void MainWindow::player1SelectedRowSlot(int rowId)
{
    qDebug() << __func__ << rowId;
}

void MainWindow::player2SelectedRowSlot(int rowId)
{
    qDebug() << __func__ << rowId;
}

void MainWindow::selectedWeatherSlot()
{
    qDebug() << __func__;
}
