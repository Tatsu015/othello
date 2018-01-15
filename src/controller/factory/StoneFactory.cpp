#include "StoneFactory.h"
#include "Stone.h"
#include "StoneItem.h"

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

StoneItem*StoneFactory::createStoneItem()
{
    StoneItem* stoneItem = new StoneItem();
    return stoneItem;
}

Stone*StoneFactory::createStone(Color color)
{
    Stone* stone = new Stone(color);
    return stone;
}
