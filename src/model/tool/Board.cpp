#include "Board.h"
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
        if(true == isSelectableCell(cell, nowColor)){
            m_selectableCells << cell;
        }
    }
}

QList<Board::Direction> Board::reversableDirection(Color color, Cell* cell)
{
    QList<Board::Direction> directions;

    unsigned int index = m_cells.indexOf(cell);

    foreach (Board::Direction direction, ALL_DIRECTIONS) {
        int checkIndex = index + direction;

        //ignore not exist index
        if(isInvalidIndex(checkIndex)){
            continue;
        }

        Cell* checkCell = m_cells.at(checkIndex);
        Color checkStoneColor = checkCell->stoneColor();

        //ignore when neighbor cell have same color
        if(anotherColor(color) == checkStoneColor){
            if(checkPlace(color, direction, checkCell)){
                directions << direction;
            }
        }
    }
    return directions;
}

void Board::reverseStones(Color oppositeColor, Cell* putCell, QList<Board::Direction> directions)
{
    foreach (Board::Direction d, directions) {
        int checkIndex = m_cells.indexOf(putCell) + d;
        if(isInvalidIndex(checkIndex)){
            continue;
        }
        reverseStone(oppositeColor, m_cells.at(checkIndex), d);
    }
}

bool Board::checkPlace(Color targetColor, Board::Direction direction, Cell *cell)
{
    int checkIndex = m_cells.indexOf(cell) + direction;

    //ignore not exist index
    if(isInvalidIndex(checkIndex)){
        return false;
    }

    Cell* checkCell  = m_cells.at(checkIndex);
    Color checkColor = checkCell->stoneColor();
    if(NONE == checkColor){
        return false;
    }

    if(targetColor == checkColor){
        return true;
    }

    if(checkPlace(targetColor, direction, checkCell)){
        return true;
    }
    return false;
}

void Board::reverseStone(Color oppositeColor, Cell* cell, Board::Direction direction)
{
    Cell* reverseCell = cell;
    while(oppositeColor != reverseCell->stoneColor()){
        reverseCell->reverseStone();

        reverseCell = neighborCell(reverseCell, direction);
        if(nullptr == reverseCell){
            return;
        }
    }
}

bool Board::isInvalidIndex(int index)
{
    if((0 > index) || (63 < index)){
        return true;
    }
    return false;
}

bool Board::isOutsideFieldDirection(Cell* centerCell, Board::Direction direction)
{
    int index    = m_cells.indexOf(centerCell);
    int tmpIndex = index + direction;

    if(isInvalidIndex(tmpIndex)){
        return true;
    }
    if(0 == ((index + 8) % 8)){
        if((UPPER_LEFT == direction) ||
                (UPPER == direction) ||
                (UPPER_RIGHT == direction)){
            return true;
        }
    }
    if(7 == ((index + 8) % 8)){
        if((LOWER_LEFT == direction) ||
                (LOWER == direction) ||
                (LOWER_RIGHT == direction)){
            return true;
        }
    }
    return false;
}

bool Board::isSelectableCell(Cell* checkCell, Color nowColor)
{
    if(checkCell->isFilled()){
        return false;
    }

    foreach (Board::Direction direction, insideFieldDirections(checkCell)) {
        Cell* cell = neighborCell(checkCell, direction);
        if(nullptr == cell){
            return false;
        }
//    foreach (Cell* cell, neighborCells(checkCell)) {
        if(NONE == cell->stoneColor()){
            continue;
        }
        if(nowColor == cell->stoneColor()){
            continue;
        }
        if(isOppositeStoneSameColor(cell, nowColor ,direction)){
            return true;
        }
    }
    return false;
}

QList<Board::Direction> Board::insideFieldDirections(Cell* cell)
{
    QList<Board::Direction> directions;

    foreach (Board::Direction direction, ALL_DIRECTIONS) {
        if(!isOutsideFieldDirection(cell, direction)){
            directions << direction;
        }
    }

    return directions;
}

QList<Cell*> Board::neighborCells(Cell* cell)
{
    QList<Cell*> cells;
    int index = m_cells.indexOf(cell);

    foreach (Direction direction, insideFieldDirections(cell)) {
        if(nullptr != neighborCell(cell, direction)){
            cells << m_cells.at(index + direction);
        }
    }

    return cells;
}

Cell*Board::neighborCell(Cell* cell, Board::Direction direction)
{
    int index = m_cells.indexOf(cell) + direction;

    if(isOutsideFieldDirection(cell, direction)){
        return nullptr;
    }
    return m_cells.at(index);
}

QList<Cell*> Board::reversableCells() const
{
    return m_selectableCells;
}

bool Board::isOppositeStoneSameColor(Cell* selectedAroundCell, Color nowColor, Board::Direction direction)
{
    Cell* oppositeCell = neighborCell(selectedAroundCell, direction);
    if(nullptr == oppositeCell){
        return false;
    }

    while(true){
        if(NONE == oppositeCell->stoneColor()){
            return false;
        }
        if(nowColor == oppositeCell->stoneColor()){
            return true;
        }

        oppositeCell = neighborCell(oppositeCell, direction);
        if(nullptr == oppositeCell){
            return false;
        }
    }
    return false;
}
