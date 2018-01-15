#include "Application.h"
#include "Game.h"
#include "Board.h"
#include "Scene.h"

Application* Application::getInstance()
{
    static Application s;
    return &s;
}

void Application::reset()
{
    m_board->reset();
    m_game->reset();
    m_scene->reset();
}

Game* Application::game() const
{
    return m_game;
}

Board* Application::board() const
{
    return m_board;
}

Scene* Application::scene() const
{
    return m_scene;
}

Application::Application():
    m_game(new Game()),
    m_board(new Board()),
    m_scene(new Scene())
{
    m_scene->setBoard(m_board);
}

Application::~Application()
{
}
