#include "Stone.h"

Stone::Stone(Color color):
    m_color(color)
{
}

Stone::~Stone()
{
}

void Stone::changeColor()
{
    m_color = anotherColor(m_color);
}
