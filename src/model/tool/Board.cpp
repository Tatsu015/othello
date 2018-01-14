#include "Board.h"
#include <QDebug>
#include "Cell.h"

const static QVector<Board::Direction> ALL_DIRECTIONS = {
    Board::UPPER_LEFT,
    Board::LEFT,
    Board::LOWER_LEFT,
    Board::UPPER,
    Board::LOWER,
    Board::UPPER_RIGHT,
    Board::RIGHT,
    Board::LOWER_RIGHT
};

Board::Board()
{
}

Board::~Board()
{
}

void Board::add(Cell* cell)
{
    m_cells << cell;
}

void Board::checkSelectableCells(Color nowColor)
{
    m_selectableCells.clear();

    foreach (Cell* cell, m_cells) {
        if(true == isReversable(cell, nowColor)){
            m_selectableCells << cell;
        }
    }
}

bool Board::canSelect(Cell* cell)
{
    if(m_selectableCells.contains(cell)){
        return true;
    }
    return false;
}

bool Board::isBoardFilled()
{
    foreach (Cell* cell, m_cells) {
        if(!cell->isFilled()){
            return false;
        }
    }
    return true;
}

QList<Cell*> Board::reversableCells() const
{
    return m_selectableCells;
}

void Board::reverseStones(Cell* cell, Color oppositeColor, Board::Direction direction)
{
    Cell* reverseCell = cell;
    while(oppositeColor != reverseCell->stoneColor()){
        reverseCell->reverseStone();

        reverseCell = neighborCell(reverseCell, direction);
        if(Q_NULLPTR == reverseCell){
            return;
        }
    }
}

void Board::reverseStonesAllDir(Cell* startCell)
{
    foreach (Direction d, ALL_DIRECTIONS) {
        reverseStonesInLine(startCell, d);
    }
}

void Board::reverseStonesInLine(Cell* startCell, Board::Direction direction)
{
    Cell* c = startCell;
    Color oppositeColor = startCell->stoneColor();

    if(isReversable(startCell, oppositeColor, direction)){
        while(oppositeColor != neighborCell(c, direction)->stoneColor()){
            c->reverseStone();
            c = neighborCell(c, direction);
        }
    }
}

QList<Cell*> Board::reversableNeighborCells(Cell* centerCell, Color putStoneColor)
{
    QList<Cell*> cells;
    foreach (Cell* c, neighborCells(centerCell)) {
        if(isReversable(c, putStoneColor)){
            cells << c;
        }
    }
    return cells;
}

bool Board::isReversable(Cell* targetCell, Color putStoneColor)
{
    foreach (Direction d, ALL_DIRECTIONS) {
        if(isReversable(targetCell, putStoneColor, d)){
            return true;
        }
    }
    return false;
}

bool Board::isReversable(Cell* targetCell, Color putStoneColor, Board::Direction direction)
{
    Cell* neighborcell = neighborCell(targetCell, direction);
    if(nullptr == neighborcell){
        return false;
    }
    //target next color must another color
    if(isSame(putStoneColor, neighborcell->stoneColor())){
        return false;
    }

    while(true){
        if(Q_NULLPTR == neighborcell){
            return false;
        }
        Color color = neighborcell->stoneColor();
        if(isSame(NONE, color)){
            return false;
        }
        if(isSame(putStoneColor, color)){
            return true;
        }

        neighborcell = neighborCell(neighborcell, direction);
    }
    return false;
}

QList<Cell*> Board::neighborCells(Cell* centerCell)
{
    QList<Cell*> cells;
    foreach (Direction direction, ALL_DIRECTIONS) {
        Cell* c = neighborCell(centerCell, direction);
        if(nullptr != c){
            cells << c;
        }
    }

    return cells;
}

Cell*Board::neighborCell(Cell* centerCell, Board::Direction direction)
{
    int index = m_cells.indexOf(centerCell) + direction;

    if(isOutside(centerCell, direction)){
        return Q_NULLPTR;
    }
    return m_cells.at(index);
}

bool Board::isOutside(Cell* targetCell, Board::Direction direction)
{
    int targetCellIndex = m_cells.indexOf(targetCell);
    int nextCellIndex   = targetCellIndex + direction;

    if((0 > nextCellIndex) || (MAX_INDEX < nextCellIndex)){
        return true;
    }
    if(0 == ((targetCellIndex + BOARD_SIZE) % BOARD_SIZE)){
        if((UPPER_LEFT == direction) ||
                (UPPER == direction) ||
                (UPPER_RIGHT == direction)){
            return true;
        }
    }
    if((BOARD_SIZE-1) == ((targetCellIndex + BOARD_SIZE) % BOARD_SIZE)){
        if((LOWER_LEFT == direction) ||
                (LOWER == direction) ||
                (LOWER_RIGHT == direction)){
            return true;
        }
    }
    return false;
}
