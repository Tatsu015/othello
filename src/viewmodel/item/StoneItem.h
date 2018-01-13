#ifndef STONEITEM_H
#define STONEITEM_H


#include <QGraphicsPathItem>
#include "Common.h"

class Stone;

class StoneItem : public QGraphicsPathItem
{
public:
    StoneItem(Color color, QGraphicsItem *parent = Q_NULLPTR);
    virtual ~StoneItem();

    Color color() const;

    void setColor(const Color& color);
    void setStone(Stone* stone);

private:
    Color m_color;
    Stone* m_stone = Q_NULLPTR;
};

#endif // STONEITEM_H
