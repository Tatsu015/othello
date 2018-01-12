#ifndef BOARD_H
#define BOARD_H


#include <QList>
#include "Common.h"

class Cell;

class Board
{
public:
    enum Direction{
        UPPER       = -1,
        UPPER_LEFT  = -9,
        LEFT        = -8,
        LOWER_LEFT  = -7,
        LOWER       = 1,
        LOWER_RIGHT = 9,
        RIGHT       = 8,
        UPPER_RIGHT = 7,
    };

public:
    Board();
    ~Board();

    void add(Cell* cell);
    void checkSelectableCells(Color nowColor);
    QList<Direction> reversableDirection(Color color, Cell* cell);
    void reverseStones(Color color, Cell* putCell, QList<Direction> directions);

    QList<Cell*> reversableCells() const;

private:
    bool isSelectableCell(Cell* checkCell, Color nowColor);
    bool isOppositeStoneSameColor(Cell* cell, Color nowColor, Board::Direction direction);
    bool isInvalidIndex(int index);
    bool isOutsideFieldDirection(Cell* centerCell, Direction direction);
    bool checkPlace(Color targetColor, Direction direction, Cell* cell);
    void reverseStone(Color oppositeColor, Cell* cell, Direction direction);
    QList<Direction> insideFieldDirections(Cell* cell);

    QList<Cell*> neighborCells(Cell* cell);
    Cell* neighborCell(Cell* cell, Direction direction);


private:
    QList<Cell*> m_cells;
    QList<Cell*> m_selectableCells;
};

#endif // BOARD_H
