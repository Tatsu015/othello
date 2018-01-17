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
    m_iconLabel = new QLabel(this);
    m_iconLabel->setMaximumSize(20,20);

    m_pixmap = new QPixmap(QSize(20,20));
    m_pixmap->fill(Qt::transparent);
    QPainter p(m_pixmap);
    p.drawEllipse(0,0,18,18);
    p.setBrush(QBrush(toColor(BLACK)));
    m_iconLabel->setPixmap(*m_pixmap);

    m_textLabel = new QLabel(this);
    m_textLabel->setText("-");

    addPermanentWidget(m_iconLabel,1);
    addPermanentWidget(m_textLabel,2);
}

StatusBar::~StatusBar()
{
}

void StatusBar::setBoard(Board* board)
{
    m_board = board;
}

void StatusBar::paintEvent(QPaintEvent* e)
{
    QString blackCount = QString::number(m_board->stoneCount(BLACK));
    QString whiteCount = QString::number(m_board->stoneCount(WHITE));

    QString m = "White:" + whiteCount + "   " + "Black" + blackCount;
    m_textLabel->setText(m);

    Color nowColor = Application::getInstance()->game()->turn()->now();
    QPainter p(m_pixmap);
    p.drawEllipse(0,0,18,18);
    p.setBrush(QBrush(toColor(nowColor)));
}
