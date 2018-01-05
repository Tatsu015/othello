#include "Cell.h"

Cell::Cell():
    m_stoneColor(NONE)
{
}

Cell::~Cell()
{
}

bool Cell::isFilled()
{
    if(NONE == m_stoneColor){
        return false;
    }
    return true;
}

Color Cell::stoneColor() const
{
    return m_stoneColor;
}

void Cell::setStoneColor(const Color& stoneColor)
{
    m_stoneColor = stoneColor;
}

void Cell::reverseStone()
{
    m_stoneColor = anotherColor(m_stoneColor);
}
