#ifndef FLOW_H
#define FLOW_H


#include <qcompilerdetection.h>
#include "Common.h"

class Board;
class CellItem;

class Flow
{
public:
    Flow();
    ~Flow();

    void progress();

    void setBoard(Board* board);
    void setCellItem(CellItem* cellItem);

private:
    bool isEndGame();
    bool needSkip();
    bool isDoubleSkip(const Color& nextColor);
    void displayResult(const Color& winnerColor);

private:
    Board*    m_board    = Q_NULLPTR;
    CellItem* m_cellItem = Q_NULLPTR;
    bool m_isSkiped;
};

#endif // FLOW_H
