#ifndef CELL_H
#define CELL_H

#include "Common.h"

class Cell
{
public:
    Cell();
    ~Cell();

    bool isFilled();

    Color stoneColor() const;
    void setStoneColor(const Color& stoneColor);
    void reverseStone();

private:
    Color m_stoneColor;
};

#endif // CELL_H
