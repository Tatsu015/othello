#ifndef GAME_H
#define GAME_H


#include <qcompilerdetection.h>

class Turn;

class Game
{
public:
    static Game* getInstance();
    void start();
    void end();
    void reset();

    Turn* turn() const;

private:
    Turn* m_turn = Q_NULLPTR;

private:
    Game();
    ~Game();
};
#endif // GAME_H
