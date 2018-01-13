#include "Scene.h"
#include <QGraphicsSceneMouseEvent>
#include "Common.h"
#include "Game.h"
#include "Turn.h"
#include "Board.h"
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
        QList<QGraphicsItem *> clickedItems = items(event->scenePos());
        if(clickedItems.isEmpty()){
            return;
        }

        CellItem* cellItem = dynamic_cast<CellItem*>(clickedItems.at(0));
        if(nullptr == cellItem){
            return;
        }

        Color nowColor = Game::getInstance()->turn()->now();

        if(!m_board->isReversable(cellItem->cell())){
            return;
        }

        cellItem->setStoneItem(new StoneItem(nowColor));
        m_board->f(nowColor, cellItem->cell());

        Game::getInstance()->turn()->change();
        updateView();
        m_board->checkSelectableCells(Game::getInstance()->turn()->now());
    }
    else if(Qt::RightButton == event->button()){
        foreach (CellItem* cellItem, m_cellItems) {
            Cell* cell = cellItem->cell();
            QList<Cell*> cells = m_board->reversableCells();
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

void Scene::updateView()
{
    foreach (CellItem* cellItem, m_cellItems) {
        cellItem->updateView();
    }
}

void Scene::setBoard(Board *board)
{
    m_board = board;
}
