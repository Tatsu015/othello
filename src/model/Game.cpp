#include "Game.h"
#include "Turn.h"


Game::Game():
    m_turn(new Turn()),
    m_round(0)
{
}

Game::~Game()
{
}

void Game::start()
{
    ++m_round;
}

void Game::end()
{
}

void Game::reset()
{
    m_turn->reset();
}

Turn* Game::turn() const
{
    return m_turn;
}
