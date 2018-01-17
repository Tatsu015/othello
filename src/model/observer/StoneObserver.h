#ifndef STONEOBSERVER_H
#define STONEOBSERVER_H


#include <qcompilerdetection.h>

class StoneItem;

class StoneObserver
{
public:
    StoneObserver();
    ~StoneObserver();

    void notify();
    void setStoneItem(StoneItem* stoneItem);

private:
    StoneItem* m_stoneItem = Q_NULLPTR;
};

#endif // STONEOBSERVER_H
