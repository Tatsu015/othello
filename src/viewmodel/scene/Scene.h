#ifndef SCENE_H
#define SCENE_H


#include <QGraphicsScene>

class Scene : public QGraphicsScene
{
public:
    Scene(QObject *parent = Q_NULLPTR);
    virtual ~Scene();

    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // SCENE_H
