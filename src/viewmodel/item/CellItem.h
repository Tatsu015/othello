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

    void updateView();
    void reset();
    bool existStone();

    Cell *cell() const;
    void setCell(Cell* cell);


private:
    StoneItem* m_stoneItem = Q_NULLPTR;
    Cell* m_cell = Q_NULLPTR;
};

#endif // CELLITEM_H
