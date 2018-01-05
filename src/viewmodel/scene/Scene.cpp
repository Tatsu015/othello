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

    QList<QGraphicsItem *> clickedItems = items(event->scenePos());
    if(clickedItems.isEmpty()){
        return;
    }

    CellItem* cellItem = dynamic_cast<CellItem*>(clickedItems.at(0));
    if(nullptr == cellItem){
        return;
    }

    Color nowColor = Game::getInstance()->turn()->now();

    QList<Board::Direction> directions = m_board->reversableDirection(nowColor, cellItem->cell());
    if(0 == directions.count()){
        return;
    }

    cellItem->setStoneItem(new StoneItem(nowColor));
    m_board->reverseStones(nowColor, cellItem->cell(), directions);

    Game::getInstance()->turn()->change();
    updateView();
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
