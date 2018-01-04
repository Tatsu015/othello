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

bool Board::canPlaceStone(Color color, Cell *cell)
{
    unsigned int index = m_cells.indexOf(cell);

    foreach (Board::Direction direction, DIRECTIONS) {
        int checkIndex = index + direction;

        //ignore not exist index
        if(0 > checkIndex){
            continue;
        }

        Cell* checkCell = m_cells.at(checkIndex);
        Color checkStoneColor = checkCell->stoneColor();

        //ignore when neighbor cell have same color
        if(anotherColor(color) == checkStoneColor){
            if(checkPlace(color, direction, checkCell)){
                return true;
            }
        }

    }
    return false;
}

Cell*Board::cell(unsigned int index)
{
    return m_cells.at(index);
}

bool Board::checkPlace(Color targetColor, Board::Direction direction, Cell *cell)
{
    int checkIndex = m_cells.indexOf(cell) + direction;

    //ignore not exist index
    if(0 > checkIndex){
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
