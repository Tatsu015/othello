#include <QDebug>
#include "Board.h"
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

void Board::reset()
{
    foreach (Cell* c, m_cells) {
        c->reset();
    }
}

void Board::checkSelectableCells(const Color& nowColor)
{
    m_cacheSelectableCells.clear();

    foreach (Cell* c, m_cells) {
        if(c->isFilled()){
            continue;
        }
        if(true == isReversable(c, nowColor)){
            m_cacheSelectableCells << c;
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
    foreach (Cell* c, m_cells) {
        if(!c->isFilled()){
            return false;
        }
    }
    return true;
}

QList<Cell*> Board::cacheSelectableCells() const
{
    return m_cacheSelectableCells;
}

Color Board::greater()
{
    unsigned int whiteStoneCount = stoneCount(WHITE);
    unsigned int blackStoneCount = stoneCount(BLACK);

    if(whiteStoneCount < blackStoneCount){
        return BLACK;
    }
    else if(whiteStoneCount > blackStoneCount){
        return WHITE;
    }
    else{
        return NONE;
    }
}

void Board::reverseStones(Cell* startCell)
{
    foreach (Direction d, DIRECTIONS) {
        reverseStones(startCell, d);
    }
}

unsigned int Board::stoneCount(const Color& color)
{
    unsigned int count = 0;
    foreach (Cell* c, m_cells) {
        Stone* s = c->stone();
        if(nullptr == s){
            continue;
        }
        if(color == c->stoneColor()){
            ++count;
        }
    }
    return count;
}

void Board::reverseStones(Cell* startCell, const Board::Direction& direction)
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

QList<Cell*> Board::reversableNeighborCells(Cell* centerCell, const Color& putStoneColor)
{
    QList<Cell*> cs;
    foreach (Cell* c, neighborCells(centerCell)) {
        if(isReversable(c, putStoneColor)){
            cs << c;
        }
    }
    return cs;
}

bool Board::isReversable(Cell* centerCell, const Color& putStoneColor)
{
    foreach (Direction d, DIRECTIONS) {
        if(isReversable(centerCell, putStoneColor, d)){
            return true;
        }
    }
    return false;
}

bool Board::isReversable(Cell* startCell, const Color& putStoneColor, const Board::Direction& direction)
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

Cell*Board::neighborCell(Cell* centerCell, const Board::Direction& direction)
{
    int index = m_cells.indexOf(centerCell) + direction;

    if(isOutside(centerCell, direction)){
        return Q_NULLPTR;
    }
    return m_cells.at(index);
}

bool Board::isOutside(Cell* baseCell, const Board::Direction& direction)
{
    int baseCellIndex = m_cells.indexOf(baseCell);
    int nextCellIndex = baseCellIndex + direction;

    if((0 > nextCellIndex) || (MAX_INDEX < nextCellIndex)){
        return true;
    }
    if(isTop(baseCell)){
        if((UPPER_LEFT == direction) ||
                (UPPER == direction) ||
                (UPPER_RIGHT == direction)){
            return true;
        }
    }
    if(isBottom(baseCell)){
        if((LOWER_LEFT == direction) ||
                (LOWER == direction) ||
                (LOWER_RIGHT == direction)){
            return true;
        }
    }
    return false;
}

bool Board::isTop(Cell* cell)
{
    unsigned int index = m_cells.indexOf(cell);

    if(0 == ((index + BOARD_SIZE) % BOARD_SIZE)){
        return true;
    }
    return false;
}

bool Board::isBottom(Cell* cell)
{
    unsigned int index = m_cells.indexOf(cell);

    if((BOARD_SIZE-1) == ((index + BOARD_SIZE) % BOARD_SIZE)){
        return true;
    }
    return false;
}

