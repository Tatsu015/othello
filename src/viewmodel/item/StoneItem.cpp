#include "StoneItem.h"
#include <QBrush>
#include <QPen>
#include <QDebug>
#include "Common.h"

const static QMap<Color ,Qt::GlobalColor> COLOR = {
    {BLACK, Qt::black},
    {WHITE, Qt::white}
};

StoneItem::StoneItem(Color color, QGraphicsItem* parent):QGraphicsPathItem(parent)
{
    QPainterPath p;
    p.addEllipse(STONE_WIDTH_OFFSET,STONE_HEIGHT_OFFSET,STONE_WIDTH,STONE_HEIGHT);
    setPath(p);
    setBrush(QBrush(COLOR[color]));
    setPen(QPen(Qt::transparent,0));
}

StoneItem::~StoneItem()
{
}
