#include "CellItem.h"
#include <QPen>
#include <QBrush>
#include "Common.h"
#include "Cell.h"
#include "StoneItem.h"

CellItem::CellItem(qreal x, qreal y, QGraphicsItem* parent):QGraphicsPathItem(parent)
{
    QPainterPath p;
    p.addRect(0,0,CELL_WIDTH,CELL_HEIGHT);
    setPath(p);
    setPen(QPen(Qt::black, CELL_LINE_WIDTH));
    setBrush(QBrush(QColor("forestgreen")));
    setPos(x,y);
}

CellItem::~CellItem()
{
}

void CellItem::setStoneItem(StoneItem* stoneItem)
{
    m_stoneItem = stoneItem;
    stoneItem->setParentItem(this);
}

void CellItem::updateView()
{
    if(Q_NULLPTR != m_stoneItem){
        m_stoneItem->updateView();
    }
}

bool CellItem::existStone()
{
    if(m_cell->isFilled()){
        return true;
    }
    else{
        return false;
    }
}

Cell *CellItem::cell() const
{
    return m_cell;
}

void CellItem::setCell(Cell* cell)

{
    m_cell = cell;
}
