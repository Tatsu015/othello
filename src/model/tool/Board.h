#ifndef BOARD_H
#define BOARD_H


#include <QList>
#include "Common.h"

class Cell;

class Board
{
public:
    Board();
    ~Board();

    void add(Cell* cell);
    bool canPutStoneSomeware(Color color);
    bool canPutStone(Color color, unsigned int index);

    Cell* cell(unsigned int index);

private:
    QList<Cell*> m_cells;
};

#endif // BOARD_H
