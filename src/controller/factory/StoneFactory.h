#ifndef STONEFACTORY_H
#define STONEFACTORY_H


#include "Common.h"

class Stone;
class StoneItem;

class StoneFactory
{
public:
    static StoneFactory* getInstance();
    StoneItem* createStoneItem();
    Stone* createStone(Color color);

private:
    StoneFactory();
    ~StoneFactory();
};

#endif // STONEFACTORY_H
