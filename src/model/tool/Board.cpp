#include "Board.h"

const static QVector<int> AROUNDS = {-9,-8,-7,-1,1,7,8,9};

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

bool Board::canPutStoneSomeware(Color color)
{
    return true;
}

bool Board::canPutStone(Color color, unsigned int index)
{
    foreach (int around, AROUNDS) {
        int checkIndex = index + around;
        if(0 > checkIndex){
            continue;
        }
    }
    return true;
}

Cell*Board::cell(unsigned int index)
{
    return m_cells.at(index);
}
