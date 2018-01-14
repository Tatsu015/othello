#include "Stone.h"

Stone::Stone(Color color):
    m_color(color)
{
}

Stone::~Stone()
{
}

Color Stone::color() const
{
    return m_color;
}

void Stone::setColor(const Color& color)
{
    m_color = color;
}

void Stone::changeColor()
{
    m_color = anotherColor(m_color);
}
