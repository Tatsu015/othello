#include "Scene.h"
#include <QGraphicsSceneMouseEvent>
#include "Common.h"
#include "Game.h"
#include "Turn.h"
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

    CellItem* cell = dynamic_cast<CellItem*>(clickedItems.at(0));
    if(nullptr == cell){
        return;
    }

    if(true == cell->existStone()){
        return;
    }

    Color nowColor = Game::getInstance()->turn()->now();
    StoneItem* stoneItem = new StoneItem(nowColor);
    stoneItem->setParentItem(cell);
    Game::getInstance()->turn()->change();
}
