#ifndef SCENE_H
#define SCENE_H


#include <QGraphicsScene>
#include "Common.h"

class Board;
class CellItem;

class Scene : public QGraphicsScene
{
public:
    Scene(QObject *parent = Q_NULLPTR);
    virtual ~Scene();

    void addCellItem(CellItem* cellItem);
    void setBoard(Board *board);

    CellItem* cellItem(unsigned int row, unsigned int clm) const;

    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void reset();

private:
    CellItem* clickedCellItem(QPointF clickedScenePos);
    bool isEndGame();
    bool isDoubleSkip(const Color& nextColor);
    bool needSkip();
    Color winnerColor();
    void displayResult(const Color& winnerColor);

private:
    Board* m_board = Q_NULLPTR;
    QList<CellItem*> m_cellItems;
    bool m_isSkip;
};

#endif // SCENE_H
