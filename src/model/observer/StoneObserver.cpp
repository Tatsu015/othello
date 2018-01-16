#include "StoneObserver.h"
#include <QDebug>
#include "StoneItem.h"

StoneObserver::StoneObserver()
{
}

StoneObserver::~StoneObserver()
{
}

void StoneObserver::update()
{
    m_stoneItem->updateView();
}

void StoneObserver::setStoneItem(StoneItem* stoneItem)
{
    m_stoneItem = stoneItem;
    update();
}
