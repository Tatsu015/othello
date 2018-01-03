#ifndef CELLITEM_H
#define CELLITEM_H


#include <QGraphicsPathItem>

class StoneItem;

class CellItem : public QGraphicsPathItem
{
public:
    CellItem(qreal x, qreal y, QGraphicsItem *parent = Q_NULLPTR);
    virtual ~CellItem();

    bool existStone();
};

#endif // CELLITEM_H
