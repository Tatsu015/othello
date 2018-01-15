#include "Game.h"
#include "Turn.h"

Game* Game::getInstance()
{
    static Game s;
    return &s;
}

void Game::start()
{

}

void Game::end()
{

}

void Game::reset()
{

}

Turn* Game::turn() const
{
    return m_turn;
}

Game::Game()
{
    m_turn = new Turn();
}

Game::~Game()
{
}
