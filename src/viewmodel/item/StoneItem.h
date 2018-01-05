#ifndef STONEITEM_H
#define STONEITEM_H


#include <QGraphicsPathItem>
#include "Common.h"

class StoneItem : public QGraphicsPathItem
{
public:
    StoneItem(Color color, QGraphicsItem *parent = Q_NULLPTR);
    virtual ~StoneItem();

    void updateView();

    Color color() const;

private:
    Color m_color;
};

#endif // STONEITEM_H
