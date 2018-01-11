#include "Board.h"
#include "Cell.h"

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

    foreach (Board::Direction direction, DIRECTIONS) {
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

void Board::reverseStone(Color oppositeColor, Cell* neighborCell, Board::Direction direction)
{
    Cell* reverseCell = neighborCell;
    while(oppositeColor != reverseCell->stoneColor()){
        reverseCell->reverseStone();
        int nextIndex = m_cells.indexOf(reverseCell) + direction;
        if(isInvalidIndex(nextIndex)){
            return;
        }
        reverseCell = m_cells.at(nextIndex);
    }
}

bool Board::isInvalidIndex(int index)
{
    if((0 > index) || (63 < index)){
        return true;
    }
    return false;
}

bool Board::isInsideFieldDirection(Cell* cell, Board::Direction direction)
{
    int index    = m_cells.indexOf(cell);
    int tmpIndex = index + direction;

    if(isInvalidIndex(tmpIndex)){
        return true;
    }
    if(0 == ((index + 8) % 8)){
        if((UPPER_LEFT == direction)
                || (UPPER == direction)
                || (UPPER_RIGHT == direction)){
            return true;
        }
    }
    if(7 == ((index + 8) % 8)){
        if((LOWER_LEFT == direction)
                || (LOWER == direction)
                || (LOWER_RIGHT == direction)){
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
    int checkCellIndex = m_cells.indexOf(checkCell);
    foreach (Board::Direction direction, insideFieldDirections(checkCell)) {
        int tmpIndex = checkCellIndex + direction;
        if(isInvalidIndex(tmpIndex)){
            continue;
        }
        Cell* neighborCell = m_cells.at(tmpIndex);

        if(NONE == neighborCell->stoneColor()){
            continue;
        }
        if(nowColor == neighborCell->stoneColor()){
            continue;
        }
        if(isOppositeStoneSameColor(m_cells.at(tmpIndex), nowColor ,direction)){
            return true;
        }
    }
    return false;
}

QList<Board::Direction> Board::insideFieldDirections(Cell* cell)
{
    QList<Board::Direction> directions;

    foreach (Board::Direction direction, DIRECTIONS) {
        if(!isInsideFieldDirection(cell, direction)){
            directions << direction;
        }
    }

    return directions;
}

QList<Cell*> Board::reversableCells() const
{
    return m_selectableCells;
}

bool Board::isOppositeStoneSameColor(Cell* selectedAroundCell, Color nowColor, Board::Direction direction)
{
    int oppositeIndex = m_cells.indexOf(selectedAroundCell) + direction;
    if(isInvalidIndex(oppositeIndex)){
        return false;
    }

    Cell* oppositeCell = m_cells.at(oppositeIndex);
    while(true){
        if(NONE == oppositeCell->stoneColor()){
            return false;
        }
        if(nowColor == oppositeCell->stoneColor()){
            return true;
        }

        oppositeIndex += direction;
        if(isInvalidIndex(oppositeIndex)){
            return false;
        }
        if(isInsideFieldDirection(oppositeCell, direction)){
            return false;
        }
        oppositeCell = m_cells.at(oppositeIndex);
    }
    return false;
}
