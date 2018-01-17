#ifndef SCENE_H
#define SCENE_H


#include <QGraphicsScene>
#include "Common.h"

class Board;
class CellItem;
class Flow;

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
    void setFlow(Flow* flow);

private:
    CellItem* clickedCellItem(QPointF clickedScenePos);


private:
    Board* m_board = Q_NULLPTR;
    QList<CellItem*> m_cellItems;
    Flow* m_flow = Q_NULLPTR;
};

#endif // SCENE_H
