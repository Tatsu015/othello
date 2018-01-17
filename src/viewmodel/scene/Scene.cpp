#include "Scene.h"
#include <QGraphicsSceneMouseEvent>
#include <QMessageBox>
#include <QDebug>
#include "Common.h"
#include "Application.h"
#include "StoneFactory.h"
#include "Flow.h"
#include "Game.h"
#include "Turn.h"
#include "Board.h"
#include "Stone.h"
#include "Cell.h"
#include "CellItem.h"
#include "StoneItem.h"

Scene::Scene(QObject* parent):QGraphicsScene(parent)
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

        m_flow->setCellItem(cellItem);
        m_flow->progress();
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
}

void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
    if(Qt::RightButton == event->button()){
        foreach (CellItem* cellItem, m_cellItems) {
            cellItem->setBrush(QBrush(QColor("forestgreen")));
        }
    }
}

void Scene::reset()
{
    foreach (CellItem* cellItem, m_cellItems) {
        cellItem->reset();
    }
}

CellItem*Scene::clickedCellItem(QPointF clickedScenePos)
{
    QList<QGraphicsItem *> clickedItems = items(clickedScenePos);
    if(clickedItems.isEmpty()){
        return Q_NULLPTR;
    }
    return dynamic_cast<CellItem*>(clickedItems.at(0));
}

void Scene::setFlow(Flow* flow)
{
    m_flow = flow;
}

void Scene::setBoard(Board *board)
{
    m_board = board;
}

CellItem*Scene::cellItem(unsigned int row, unsigned int clm) const
{
    unsigned int index = (row + BOARD_SIZE*clm);
    return m_cellItems.at(index);
}
