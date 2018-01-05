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

bool Board::canPlaceStoneSomeware(Color color)
{
    return true;
}

QList<Board::Direction> Board::reversableDirection(Color color, Cell* cell)
{
    QList<Board::Direction> directions;

    unsigned int index = m_cells.indexOf(cell);

    foreach (Board::Direction direction, DIRECTIONS) {
        int checkIndex = index + direction;

        //ignore not exist index
        if(isInvalid(checkIndex)){
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
        if(isInvalid(checkIndex)){
            continue;
        }
        reverseStone(oppositeColor, m_cells.at(checkIndex), d);
    }
}

Cell*Board::cell(unsigned int index)
{
    return m_cells.at(index);
}

bool Board::checkPlace(Color targetColor, Board::Direction direction, Cell *cell)
{
    int checkIndex = m_cells.indexOf(cell) + direction;

    //ignore not exist index
    if(isInvalid(checkIndex)){
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
        if(isInvalid(nextIndex)){
            return;
        }
        reverseCell = m_cells.at(nextIndex);
    }
}

bool Board::isInvalid(int index)
{
    if((0 > index) || (63 < index)){
        return true;
    }
    return false;
}

QList<Cell*> Board::cells() const
{
    return m_cells;
}
