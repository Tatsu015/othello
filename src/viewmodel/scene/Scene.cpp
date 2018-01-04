#include "Scene.h"
#include <QGraphicsSceneMouseEvent>
#include "Common.h"
#include "Game.h"
#include "Turn.h"
#include "Board.h"
#include "CellItem.h"
#include "StoneItem.h"

Scene::Scene(QObject* parent):QGraphicsScene(parent)
{
}

Scene::~Scene()
{
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

    if(!m_board->canPlaceStone(nowColor, cellItem->cell())){
        return;
    }

    cellItem->setStoneItem(new StoneItem(nowColor));
    Game::getInstance()->turn()->change();
}

void Scene::setBoard(Board *board)
{
    m_board = board;
}
