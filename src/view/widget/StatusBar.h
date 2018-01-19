#ifndef STATUSBAR_H
#define STATUSBAR_H


#include <QStatusBar>

class QPixmap;
class QLabel;
class Board;

class StatusBar : public QStatusBar
{
public:
    explicit StatusBar(QWidget *parent = Q_NULLPTR);
    virtual ~StatusBar();

    void setBoard(Board* board);
    void updateView();

private:
    Board*   m_board     = Q_NULLPTR;
};

#endif // STATUSBAR_H
