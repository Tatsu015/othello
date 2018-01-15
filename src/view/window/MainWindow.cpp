#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "Common.h"
#include "StoneFactory.h"
#include "Game.h"
#include "Turn.h"
#include "Board.h"
#include "Cell.h"
#include "Scene.h"
#include "CellItem.h"
#include "StoneItem.h"

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

    for (unsigned int i = 0; i < BOARD_SIZE; ++i) {
        for (unsigned int j = 0; j < BOARD_SIZE; ++j) {
            Cell* cell = new Cell();
            board->add(cell);
            CellItem* cellItem = new CellItem(i*CELL_WIDTH, j*CELL_HEIGHT);
            cellItem->setCell(cell);
            scene->addCellItem(cellItem);

            if((((BOARD_SIZE/2) - 1) == i) && (((BOARD_SIZE/2) - 1) == j)){
                StoneItem* stoneItem = StoneFactory::getInstance()->create(WHITE);
                cellItem->setStoneItem(stoneItem);
            }
            if(((BOARD_SIZE/2) == i) && (((BOARD_SIZE/2) - 1) == j)){
                StoneItem* stoneItem = StoneFactory::getInstance()->create(BLACK);
                cellItem->setStoneItem(stoneItem);
            }
            if((((BOARD_SIZE/2) - 1) == i) && ((BOARD_SIZE/2) == j)){
                StoneItem* stoneItem = StoneFactory::getInstance()->create(BLACK);
                cellItem->setStoneItem(stoneItem);
            }
            if(((BOARD_SIZE/2) == i) && ((BOARD_SIZE/2) == j)){
                StoneItem* stoneItem = StoneFactory::getInstance()->create(WHITE);
                cellItem->setStoneItem(stoneItem);
            }
        }
    }

    board->checkSelectableCells(Game::getInstance()->turn()->now());
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}
