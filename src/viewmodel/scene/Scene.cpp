#include "Scene.h"
#include <QGraphicsSceneMouseEvent>
#include <QMessageBox>
#include <QDebug>
#include "Common.h"
#include "Application.h"
#include "StoneFactory.h"
#include "Game.h"
#include "Turn.h"
#include "Board.h"
#include "Stone.h"
#include "Cell.h"
#include "CellItem.h"
#include "StoneItem.h"

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
        //select cell
        CellItem* cellItem = clickedCellItem(event->scenePos());
        if(Q_NULLPTR == cellItem){
            return;
        }

        Cell* cell = cellItem->cell();
        if(!m_board->isSelectable(cell)){
            return;
        }

        Color nowColor = Application::getInstance()->game()->turn()->now();
        qDebug() << "Last put color" << toString(nowColor);

        //put stone and reverse stone
        StoneItem* stoneItem = StoneFactory::getInstance()->createStoneItem();
        Stone* stone = StoneFactory::getInstance()->createStone(nowColor);
        stoneItem->setStone(stone);
        cellItem->setStoneItem(stoneItem);
        m_board->reverseStones(cell);

        //check end game
        if(isEndGame()){
            updateView();
            Color color = winnerColor();
            displayResult(color);
            return;
        }

        //turn change
        Application::getInstance()->game()->turn()->change();
        Color nextColor = Application::getInstance()->game()->turn()->now();

        //check board status
        m_board->checkSelectableCells(nextColor);

        //if need turn skip, display dialog and skip turn
        if(needSkip()){
            updateView();
            Application::getInstance()->game()->turn()->change();
            Color nextColor = Application::getInstance()->game()->turn()->now();
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

void Scene::updateView()
{
    foreach (CellItem* cellItem, m_cellItems) {
        cellItem->updateView();
    }
}

void Scene::reset()
{
    qDeleteAll(m_cellItems);
    m_cellItems.clear();
    m_isSkip = false;
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

CellItem*Scene::cellItem(unsigned int row, unsigned int clm) const
{
    unsigned int index = (row + 8*clm);
    return m_cellItems.at(index);
}

bool Scene::isEndGame()
{
    if(m_board->isFilled()){
        return true;
    }
    return false;
}

bool Scene::isDoubleSkip(const Color& nextColor)
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

void Scene::displayResult(const Color& winnerColor)
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
