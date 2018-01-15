#include "Board.h"
#include <QDebug>
#include "Cell.h"
#include "Stone.h"

const static QVector<Board::Direction> DIRECTIONS = {
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
    qDeleteAll(m_cells);
}

void Board::add(Cell* cell)
{
    m_cells << cell;
}

void Board::checkSelectableCells(Color nowColor)
{
    m_cacheSelectableCells.clear();

    foreach (Cell* cell, m_cells) {
        if(cell->isFilled()){
            continue;
        }
        if(true == isReversable(cell, nowColor)){
            m_cacheSelectableCells << cell;
        }
    }
}

bool Board::isSelectable(Cell* cell)
{
    if(m_cacheSelectableCells.contains(cell)){
        return true;
    }
    return false;
}

bool Board::isFilled()
{
    foreach (Cell* cell, m_cells) {
        if(!cell->isFilled()){
            return false;
        }
    }
    return true;
}

QList<Cell*> Board::cacheSelectableCells() const
{
    return m_cacheSelectableCells;
}

void Board::reverseStones(Cell* startCell)
{
    foreach (Direction d, DIRECTIONS) {
        reverseStones(startCell, d);
    }
}

unsigned int Board::stoneCount(Color color)
{
    unsigned int count = 0;
    foreach (Cell* c, m_cells) {
        Stone* s = c->stone();
        if(nullptr == s){
            continue;
        }
        if(color == c->stone()->color()){
            ++count;
        }
    }
    return count;
}

void Board::reverseStones(Cell* startCell, Board::Direction direction)
{
    Cell* c = startCell;
    Color oppositeColor = startCell->stoneColor();

    if(isReversable(startCell, oppositeColor, direction)){
        while(oppositeColor != neighborCell(c, direction)->stoneColor()){
            c = neighborCell(c, direction);
            c->reverseStone();
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

bool Board::isReversable(Cell* centerCell, Color putStoneColor)
{
    foreach (Direction d, DIRECTIONS) {
        if(isReversable(centerCell, putStoneColor, d)){
            return true;
        }
    }
    return false;
}

bool Board::isReversable(Cell* startCell, Color putStoneColor, Board::Direction direction)
{
    Cell* neighborcell = neighborCell(startCell, direction);
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
    foreach (Direction direction, DIRECTIONS) {
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

bool Board::isOutside(Cell* baseCell, Board::Direction direction)
{
    int baseCellIndex = m_cells.indexOf(baseCell);
    int nextCellIndex   = baseCellIndex + direction;

    if((0 > nextCellIndex) || (MAX_INDEX < nextCellIndex)){
        return true;
    }
    if(0 == ((baseCellIndex + BOARD_SIZE) % BOARD_SIZE)){
        if((UPPER_LEFT == direction) ||
                (UPPER == direction) ||
                (UPPER_RIGHT == direction)){
            return true;
        }
    }
    if((BOARD_SIZE-1) == ((baseCellIndex + BOARD_SIZE) % BOARD_SIZE)){
        if((LOWER_LEFT == direction) ||
                (LOWER == direction) ||
                (LOWER_RIGHT == direction)){
            return true;
        }
    }
    return false;
}
