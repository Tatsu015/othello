#include "StoneFactory.h"
#include "StoneItem.h"
#include "Stone.h"

StoneFactory* StoneFactory::getInstance()
{
    static StoneFactory s;
    return &s;
}

StoneFactory::StoneFactory()
{
}

StoneFactory::~StoneFactory()
{
}

StoneItem*StoneFactory::create(Color color)
{
    StoneItem* stoneItem = new StoneItem(color);
    Stone* stone = new Stone(color);
    stoneItem->setStone(stone);

    return stoneItem;
}
