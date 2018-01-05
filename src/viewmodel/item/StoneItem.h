#ifndef STONEITEM_H
#define STONEITEM_H


#include <QGraphicsPathItem>
#include "Common.h"

class StoneItem : public QGraphicsPathItem
{
public:
    StoneItem(Color color, QGraphicsItem *parent = Q_NULLPTR);
    virtual ~StoneItem();

    Color color() const;

    void setColor(const Color& color);

private:
    Color m_color;
};

#endif // STONEITEM_H
