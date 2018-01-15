#include "Cell.h"
#include "Stone.h"

Cell::Cell()
{
}

Cell::~Cell()
{
    delete m_stone;
}

bool Cell::isFilled()
{
    if(Q_NULLPTR == m_stone){
        return false;
    }
    return true;
}

Color Cell::stoneColor() const
{
    if(Q_NULLPTR == m_stone){
        return NONE;
    }
    return m_stone->color();
}

void Cell::reverseStone()
{
    m_stone->changeColor();
}

Stone* Cell::stone() const
{
    return m_stone;
}

void Cell::setStone(Stone* stone)
{
    m_stone = stone;
}
