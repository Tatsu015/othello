#ifndef GAME_H
#define GAME_H


#include <qcompilerdetection.h>

class Turn;

class Game
{
public:
    Game();
    ~Game();

    void start();
    void end();
    void reset();

    Turn* turn() const;

private:
    Turn* m_turn = Q_NULLPTR;
    unsigned int m_round;
};
#endif // GAME_H
