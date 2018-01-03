#include "CellItem.h"
#include <QPen>
#include <QBrush>
#include "Common.h"

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

bool CellItem::existStone()
{
    if(childItems().isEmpty()){
        return false;
    }
    else{
        return true;
    }
}

