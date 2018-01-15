#ifndef STONEITEM_H
#define STONEITEM_H


#include <QGraphicsPathItem>
#include "Common.h"

class Stone;

class StoneItem : public QGraphicsPathItem
{
public:
    StoneItem(QGraphicsItem *parent = Q_NULLPTR);
    virtual ~StoneItem();

    Color color() const;

    void setColor(const Color& color);
    Stone* stone() const;
    void setStone(Stone* stone);
    void updateView();

private:
    Stone* m_stone = Q_NULLPTR;
};

#endif // STONEITEM_H
