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
    QList<Direction> reversableDirection(Color color, Cell* cell);
    void reverseStones(Color color, Cell* putCell, QList<Direction> directions);

private:
    bool checkPlace(Color targetColor, Direction direction, Cell* cell);
    void reverseStone(Color oppositeColor, Cell* neighborCell, Direction direction);
    bool isInvalid(int index);

private:
    QList<Cell*> m_cells;
};

#endif // BOARD_H
