#ifndef BOARDOBSERVER_H
#define BOARDOBSERVER_H


#include <qcompilerdetection.h>

class StatusBar;

class BoardObserver
{
public:
    BoardObserver();
    ~BoardObserver();

    void notify();
    void setStatusBar(StatusBar* statusBar);

private:
    StatusBar* m_statusBar = Q_NULLPTR;
};

#endif // BOARDOBSERVER_H
