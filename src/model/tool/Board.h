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

    void checkSelectableCells(const Color& nowColor);

    bool isSelectable(Cell* cell);
    bool isFilled();

    void reverseStones(Cell* startCell);

    unsigned int stoneCount(const Color& color);
    QList<Cell*> cacheSelectableCells() const;

private:
    void reverseStones(Cell* startCell, const Direction& direction);

    QList<Cell*> reversableNeighborCells(Cell* centerCell, const Color& putStoneColor);
    bool isReversable(Cell* centerCell, const Color& putStoneColor);
    bool isReversable(Cell* startCell, const Color& putStoneColor, const Direction& direction);

    QList<Cell*> neighborCells(Cell* centerCell);
    Cell* neighborCell(Cell* centerCell, const Direction& direction);

    bool isOutside(Cell* baseCell, const Direction& direction);

private:
    QList<Cell*> m_cells;
    QList<Cell*> m_cacheSelectableCells;
};

#endif // BOARD_H
