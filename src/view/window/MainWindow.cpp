#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "Common.h"
#include "Scene.h"
#include "CellItem.h"
#include "Board.h"
#include "Cell.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    Board* board = new Board();

    Scene* scene = new Scene();
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            Cell* cell = new Cell();
            board->add(cell);
            CellItem* cellItem = new CellItem(i*CELL_WIDTH, j*CELL_HEIGHT);
            cellItem->setCell(cell);
            scene->addItem(cellItem);
        }
    }

    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}
