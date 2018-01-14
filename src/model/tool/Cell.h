#ifndef CELL_H
#define CELL_H


#include <qcompilerdetection.h>
#include "Common.h"

class Stone;

class Cell
{
public:
    Cell();
    ~Cell();

    bool isFilled();

    Color stoneColor() const;
    void setStoneColor(const Color& stoneColor);
    void reverseStone();

    Stone* stone() const;
    void setStone(Stone* stone);

private:
    Stone* m_stone = Q_NULLPTR;
};

#endif // CELL_H
