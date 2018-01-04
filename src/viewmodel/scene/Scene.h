#ifndef SCENE_H
#define SCENE_H


#include <QGraphicsScene>

class Board;

class Scene : public QGraphicsScene
{
public:
    Scene(QObject *parent = Q_NULLPTR);
    virtual ~Scene();

    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);

    void setBoard(Board *board);

private:
    Board* m_board = Q_NULLPTR;
};

#endif // SCENE_H
