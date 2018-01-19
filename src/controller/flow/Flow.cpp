#include "Flow.h"
#include <QApplication>
#include <QMessageBox>
#include <QBitmap>
#include <QDebug>
#include "Application.h"
#include "StoneFactory.h"
#include "Game.h"
#include "Turn.h"
#include "Board.h"
#include "Stone.h"
#include "StoneItem.h"
#include "CellItem.h"


Flow::Flow():
    m_isSkiped(false)
{
}

Flow::~Flow()
{
}

void Flow::progress()
{
    Color nowColor = Application::getInstance()->game()->turn()->now();
    qDebug() << "Last put color" << toString(nowColor);

    //put stone and reverse stone
    StoneItem* stoneItem = StoneFactory::getInstance()->createStoneItem();
    Stone* stone = StoneFactory::getInstance()->createStone(nowColor);

    stoneItem->setStone(stone);
    stone->setStoneItem(stoneItem);
    m_cellItem->setStoneItem(stoneItem);
    Cell* c = m_cellItem->cell();
    m_board->reverseStones(c);
    m_board->notify();

    //check end game
    if(isEndGame()){
        Color winnerColor = m_board->greater();
        displayResult(winnerColor);
        return;
    }

    //turn change
    Application::getInstance()->game()->turn()->change();
    Color nextColor = Application::getInstance()->game()->turn()->now();

    if(BLACK == nextColor){
        QCursor myCursor = QCursor(QPixmap(CURSOR_ICON_PATH));
        QApplication::setOverrideCursor(myCursor);
    }
    else{
        QApplication::setOverrideCursor(QCursor(Qt::ArrowCursor));
    }

    //check board status
    m_board->checkSelectableCells(nextColor);

    //if need turn skip, display dialog and skip turn
    if(needSkip()){
        Application::getInstance()->game()->turn()->change();
        Color nextColor = Application::getInstance()->game()->turn()->now();
        if(isDoubleSkip(nextColor)){
            Color winnerColor = m_board->greater();
            displayResult(winnerColor);
            return;
        }
        QMessageBox::information(Q_NULLPTR,
                                 "Infomation",
                                 "Can not put stone anyware!\n"
                                 "Skip turn!");
        m_isSkiped = true;
    }
    else{
        m_isSkiped = false;
    }

    qDebug() << "White : " << m_board->stoneCount(WHITE);
    qDebug() << "Black : " << m_board->stoneCount(BLACK);
}

void Flow::setBoard(Board* board)
{
    m_board = board;
}

void Flow::setCellItem(CellItem* cellItem)
{
    m_cellItem = cellItem;
}

bool Flow::isEndGame()
{
    if(m_board->isFilled()){
        return true;
    }
    return false;
}

bool Flow::needSkip()
{
    if(m_board->cacheSelectableCells().isEmpty()){
        return true;
    }
    return false;
}

bool Flow::isDoubleSkip(const Color& nextColor)
{
    m_board->checkSelectableCells(nextColor);
    if(needSkip()){
        return true;
    }
    return false;
}

void Flow::displayResult(const Color& winnerColor)
{
    QString message;
    if(NONE == winnerColor){
        message = "Draw...   ";
    }
    else{
        message = toString(winnerColor) + " win !";
    }
    QMessageBox::information(Q_NULLPTR,
                             "Infomation",
                             message);
}

