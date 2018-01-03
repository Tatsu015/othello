#ifndef GAME_H
#define GAME_H


class Turn;

class Game
{
public:
    static Game* getInstance();
    void start();
    void end();

    Turn* turn() const;

private:
    Turn* m_turn = nullptr;

private:
    Game();
    ~Game();
};
#endif // GAME_H
