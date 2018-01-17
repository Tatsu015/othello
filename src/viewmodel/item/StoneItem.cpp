#include "StoneItem.h"
#include <QBrush>
#include <QPen>
#include <QDebug>
#include "Common.h"
#include "Stone.h"

StoneItem::StoneItem(QGraphicsItem* parent):QGraphicsPathItem(parent)
{
    QPainterPath p;
    p.addEllipse(STONE_WIDTH_OFFSET,STONE_HEIGHT_OFFSET,STONE_WIDTH,STONE_HEIGHT);
    setPath(p);
    setPen(QPen(Qt::transparent,0));
}

StoneItem::~StoneItem()
{
}

Color StoneItem::color() const
{
    return m_stone->color();
}

void StoneItem::setColor(const Color& color)
{
    m_stone->setColor(color);
    setBrush(toColor(color));
}

Stone* StoneItem::stone() const
{
    return m_stone;
}

void StoneItem::setStone(Stone* stone)
{
    m_stone = stone;
    setBrush(toColor(m_stone->color()));
}

void StoneItem::updateView()
{
    setBrush(toColor(m_stone->color()));
}
