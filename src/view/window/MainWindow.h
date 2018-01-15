#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Common.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void addStone(unsigned int row, unsigned int clm, Color color);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
