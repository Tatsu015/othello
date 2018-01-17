#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "Common.h"
#include "Application.h"
#include "StoneFactory.h"
#include "Game.h"
#include "Turn.h"
#include "Board.h"
#include "Cell.h"
#include "Stone.h"
#include "Scene.h"
#include "CellItem.h"
#include "StoneItem.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionReset, &QAction::triggered, []{
        Application::getInstance()->reset();
    });

    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setBackgroundBrush(Qt::gray);

    Scene* scene = Application::getInstance()->scene();
    Board* board = Application::getInstance()->board();

    for (unsigned int i = 0; i < BOARD_SIZE; ++i) {
        for (unsigned int j = 0; j < BOARD_SIZE; ++j) {
            Cell* cell = new Cell();
            board->add(cell);
            CellItem* cellItem = new CellItem(i*CELL_WIDTH, j*CELL_HEIGHT);
            cellItem->setCell(cell);
            scene->addCellItem(cellItem);
        }
    }

    addStone(INIT_UPPER, INIT_LEFT , WHITE);
    addStone(INIT_UPPER, INIT_RIGHT, BLACK);
    addStone(INIT_LOWER, INIT_LEFT , BLACK);
    addStone(INIT_LOWER, INIT_RIGHT, WHITE);

    board->checkSelectableCells(Application::getInstance()->game()->turn()->now());
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addStone(unsigned int row, unsigned int clm, Color color)
{
    CellItem* cellItem = Application::getInstance()->scene()->cellItem(row, clm);
    StoneItem* stoneItem = StoneFactory::getInstance()->createStoneItem();
    Stone* stone = StoneFactory::getInstance()->createStone(color);
    stoneItem->setStone(stone);
    stone->setStoneItem(stoneItem);
    cellItem->setStoneItem(stoneItem);
}
