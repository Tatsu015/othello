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

    Stone* stone() const;
    void setStone(Stone* stone);

    void reset();

    Color stoneColor() const;
    void setStoneColor(const Color& stoneColor);
    void reverseStone();

private:
    Stone* m_stone = Q_NULLPTR;
};

#endif // CELL_H
