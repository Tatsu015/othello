#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "Common.h"
#include "Scene.h"
#include "CellItem.h"
#include "StoneItem.h"
#include "Board.h"
#include "Cell.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setBackgroundBrush(Qt::gray);

    Board* board = new Board();
    Scene* scene = new Scene();
    scene->setBoard(board);

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            Cell* cell = new Cell();
            board->add(cell);
            CellItem* cellItem = new CellItem(i*CELL_WIDTH, j*CELL_HEIGHT);
            cellItem->setCell(cell);
            scene->addCellItem(cellItem);

            if((3 == i) && (3 == j)){
                cellItem->setStoneItem(new StoneItem(WHITE));
            }
            if((4 == i) && (3 == j)){
                cellItem->setStoneItem(new StoneItem(BLACK));
            }
            if((3 == i) && (4 == j)){
                cellItem->setStoneItem(new StoneItem(BLACK));
            }
            if((4 == i) && (4 == j)){
                cellItem->setStoneItem(new StoneItem(WHITE));
            }
        }
    }
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}
