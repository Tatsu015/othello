#ifndef SCENE_H
#define SCENE_H


#include <QGraphicsScene>

class Board;
class CellItem;

class Scene : public QGraphicsScene
{
public:
    Scene(QObject *parent = Q_NULLPTR);
    virtual ~Scene();

    void addCellItem(CellItem* cellItem);
    void setBoard(Board *board);

    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void updateView();


private:
    Board* m_board = Q_NULLPTR;
    QList<CellItem*> m_cellItems;
};

#endif // SCENE_H
