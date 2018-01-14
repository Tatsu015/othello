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
        UPPER_LEFT  = -(BOARD_SIZE + 1),
        LEFT        = -(BOARD_SIZE),
        LOWER_LEFT  = -(BOARD_SIZE - 1),
        LOWER       = 1,
        LOWER_RIGHT = (BOARD_SIZE + 1),
        RIGHT       = BOARD_SIZE,
        UPPER_RIGHT = (BOARD_SIZE - 1),
    };

public:
    Board();
    ~Board();

    void add(Cell* cell);
    void checkSelectableCells(Color nowColor);
    bool canSelect(Cell* cell);
    bool isBoardFilled();
    QList<Cell*> reversableCells() const;
    void reverseStonesAllDir(Cell* startCell);

private:
    void reverseStones(Cell* cell, Color oppositeColor, Direction direction);
    void reverseStonesInLine(Cell* cell, Direction direction);
    QList<Cell*> reversableNeighborCells(Cell* centerCell, Color putStoneColor);
    bool isReversable(Cell* targetCell, Color putStoneColor);
    bool isReversable(Cell* targetCell, Color putStoneColor, Direction direction);
    QList<Cell*> neighborCells(Cell* centerCell);
    Cell* neighborCell(Cell* centerCell, Direction direction);
    bool isOutside(Cell* centerCell, Direction direction);


private:
    QList<Cell*> m_cells;
    QList<Cell*> m_selectableCells;
};

#endif // BOARD_H
