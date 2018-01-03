#include "Board.h"

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

bool Board::canPutStone(Color color)
{
    return true;
}
