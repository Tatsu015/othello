#ifndef BOARD_H
#define BOARD_H


#include <QList>
#include "Common.h"

class Cell;

class Board
{
public:
    enum Direction{UPPER_LEFT  = -9,
                   LEFT        = -8,
                   LOWER_LEFT  = -7,
                   UPPER       = -1,
                   LOWER       = 1,
                   LOWER_RIGHT = 7,
                   RIGHT       = 8,
                   UPPER_RIGHT = 9,
                  };

public:
    Board();
    ~Board();

    void add(Cell* cell);
    bool canPlaceStoneSomeware(Color color);
    bool canPlaceStone(Color color, Cell* cell);
    void reverseStones(Cell *cell);

    Cell* cell(unsigned int index);
    QList<Cell*> cells() const;

private:
    bool checkPlace(Color targetColor, Direction direction, Cell* cell);

private:
    QList<Cell*> m_cells;
    QList<ReverseCellInfo*> m_reverseCellInfos;
};

#endif // BOARD_H
