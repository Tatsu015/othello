#ifndef CELLITEM_H
#define CELLITEM_H


#include <QGraphicsPathItem>

class Cell;
class StoneItem;

class CellItem : public QGraphicsPathItem
{
public:
    CellItem(qreal x, qreal y, QGraphicsItem *parent = Q_NULLPTR);
    virtual ~CellItem();

    void setStoneItem(StoneItem* stoneItem);

    bool existStone();

    Cell *cell() const;
    void setCell(Cell* cell);


private:
    Cell* m_cell = Q_NULLPTR;
};

#endif // CELLITEM_H
