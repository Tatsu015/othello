#include "StatusBar.h"
#include <QLabel>
#include <QPicture>
#include <QPainter>
#include "Application.h"
#include "Game.h"
#include "Turn.h"
#include "Common.h"
#include "Board.h"

StatusBar::StatusBar(QWidget* parent):QStatusBar(parent)
{
}

StatusBar::~StatusBar()
{
}

void StatusBar::setBoard(Board* board)
{
    m_board = board;
}

void StatusBar::updateView()
{
    QString blackCount = QString::number(m_board->stoneCount(BLACK));
    QString whiteCount = QString::number(m_board->stoneCount(WHITE));

    QString m = "White:" + whiteCount + "   " + "Black" + blackCount;
    showMessage(m);
}
