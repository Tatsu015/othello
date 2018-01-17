#ifndef APPLICATION_H
#define APPLICATION_H


#include <qcompilerdetection.h>

class Flow;
class Game;
class Board;
class Scene;

class Application
{
public:
    static Application* getInstance();

    void reset();

    Game* game() const;

    Board* board() const;

    Scene* scene() const;

private:
    Flow*  m_flow  = Q_NULLPTR;
    Game*  m_game  = Q_NULLPTR;
    Board* m_board = Q_NULLPTR;
    Scene* m_scene = Q_NULLPTR;

private:
    Application();
    ~Application();
};
#endif // APPLICATION_H
