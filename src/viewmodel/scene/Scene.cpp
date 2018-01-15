#include "Scene.h"
#include <QGraphicsSceneMouseEvent>
#include <QMessageBox>
#include <QDebug>
#include "Common.h"
#include "Game.h"
#include "Turn.h"
#include "Board.h"
#include "Cell.h"
#include "CellItem.h"
#include "StoneItem.h"
#include "StoneFactory.h"

Scene::Scene(QObject* parent):QGraphicsScene(parent),
    m_isSkip(false)
{
}

Scene::~Scene()
{
}

void Scene::addCellItem(CellItem* cellItem)
{
    m_cellItems << cellItem;
    addItem(cellItem);
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    if(Qt::LeftButton == event->button()){
        CellItem* cellItem = clickedCellItem(event->scenePos());
        if(Q_NULLPTR == cellItem){
            return;
        }

        Cell* cell = cellItem->cell();
        if(!m_board->isSelectable(cell)){
            return;
        }

        Color nowColor = Game::getInstance()->turn()->now();
        qDebug() << "Last put color" << toString(nowColor);

        //put stone and reverse stone
        StoneItem* stoneItem = StoneFactory::getInstance()->create(nowColor);
        cellItem->setStoneItem(stoneItem);
        m_board->reverseStones(cell);

        //if now color is winner end game
        if(isEndGame()){
            updateView();
            Color color = winnerColor();
            displayResult(color);
            return;
        }

        //continue game
        //turn change
        Game::getInstance()->turn()->change();
        Color nextColor = Game::getInstance()->turn()->now();

        //check board status
        m_board->checkSelectableCells(nextColor);

        //if need turn skip, display dialog and skip turn
        if(needSkip()){
            updateView();
            Game::getInstance()->turn()->change();
            Color nextColor = Game::getInstance()->turn()->now();
            if(isDoubleSkip(nextColor)){
                nextColor = winnerColor();
                displayResult(nextColor);
                return;
            }
            QMessageBox::information(Q_NULLPTR,
                                     "Infomation",
                                     "Can not put stone anyware!\n"
                                     "Skip turn!");
            m_isSkip = true;
        }
        else{
            m_isSkip = false;
        }
        qDebug() << "White : " << m_board->stoneCount(WHITE);
        qDebug() << "Black : " << m_board->stoneCount(BLACK);
    }
    else if(Qt::RightButton == event->button()){
        foreach (CellItem* cellItem, m_cellItems) {
            Cell* cell = cellItem->cell();
            QList<Cell*> cells = m_board->cacheSelectableCells();
            if(cells.contains(cell)){
                cellItem->setBrush(QBrush(QColor("gold")));
            }
        }
    }

    updateView();
}

void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
    if(Qt::RightButton == event->button()){
        foreach (CellItem* cellItem, m_cellItems) {
            cellItem->setBrush(QBrush(QColor("forestgreen")));
        }
    }
}

#include <stdio.h>
void Scene::updateView()
{
    QMap<Color, QString> m;
    m[NONE] = "-";
    m[BLACK] = "B";
    m[WHITE] = "W";
    QString s;
    foreach (CellItem* cellItem, m_cellItems) {
        s += m[cellItem->cell()->stoneColor()].toStdString().c_str();
        cellItem->updateView();
    }
//    for(int i = 0; i < 4; ++i){
//        printf("%c%c%c%c\n",s[i+0].toLatin1(), s[i+4].toLatin1(),s[i+8].toLatin1(), s[i+12].toLatin1());
//        fflush(nullptr);
//    }
//    printf("------------------------\n");
}

CellItem*Scene::clickedCellItem(QPointF clickedScenePos)
{
    QList<QGraphicsItem *> clickedItems = items(clickedScenePos);
    if(clickedItems.isEmpty()){
        return Q_NULLPTR;
    }
    return dynamic_cast<CellItem*>(clickedItems.at(0));
}

void Scene::setBoard(Board *board)
{
    m_board = board;
}

bool Scene::isEndGame()
{
    if(m_board->isFilled()){
        return true;
    }
    return false;
}

bool Scene::isDoubleSkip(Color nextColor)
{
    m_board->checkSelectableCells(nextColor);
    if(needSkip()){
        return true;
    }
    return false;
}

bool Scene::needSkip()
{
    if(m_board->cacheSelectableCells().isEmpty()){
        return true;
    }
    return false;
}

Color Scene::winnerColor()
{
    unsigned int whiteStoneCount = m_board->stoneCount(WHITE);
    unsigned int blackStoneCount = m_board->stoneCount(BLACK);

    if(whiteStoneCount < blackStoneCount){
        return BLACK;
    }
    else if(whiteStoneCount > blackStoneCount){
        return WHITE;
    }
    else{
        return NONE;
    }
}

void Scene::displayResult(Color winnerColor)
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
