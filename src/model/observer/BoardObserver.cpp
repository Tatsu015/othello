#include "BoardObserver.h"
#include "StatusBar.h"

BoardObserver::BoardObserver()
{
}

BoardObserver::~BoardObserver()
{
}

void BoardObserver::notify()
{
    m_statusBar->updateView();
}

void BoardObserver::setStatusBar(StatusBar* statusBar)
{
    m_statusBar = statusBar;
}
