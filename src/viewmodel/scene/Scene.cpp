#include "Scene.h"
#include <QGraphicsSceneMouseEvent>
#include <QMessageBox>
#include "Common.h"
#include "Game.h"
#include "Turn.h"
#include "Board.h"
#include "Cell.h"
#include "CellItem.h"
#include "StoneItem.h"
#include "StoneFactory.h"

Scene::Scene(QObject* parent):QGraphicsScene(parent)
{
}

Scene::~Scene()
{
}

void Scene::addCellItem(CellItem* cellItem)
{
    m_cellItems << cellItem;
    addItem(cellItem);
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    if(Qt::LeftButton == event->button()){
        CellItem* cellItem = clickedCellItem(event->scenePos());
        if(Q_NULLPTR == cellItem){
            return;
        }

        Cell* cell = cellItem->cell();
        if(!m_board->isReversable(cell)){
            return;
        }

        Color nowColor = Game::getInstance()->turn()->now();
        StoneItem* stoneItem = StoneFactory::getInstance()->create(nowColor);
        cellItem->setStoneItem(stoneItem);
        m_board->reverseStones(nowColor, cell);

        Game::getInstance()->turn()->change();
        Color nextColor = Game::getInstance()->turn()->now();
        m_board->checkSelectableCells(nextColor);
        checkWinner(nowColor);
    }
    else if(Qt::RightButton == event->button()){
        foreach (CellItem* cellItem, m_cellItems) {
            Cell* cell = cellItem->cell();
            QList<Cell*> cells = m_board->reversableCells();
            if(cells.contains(cell)){
                cellItem->setBrush(QBrush(QColor("gold")));
            }
        }
    }

    updateView();
}

void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
    if(Qt::RightButton == event->button()){
        foreach (CellItem* cellItem, m_cellItems) {
            cellItem->setBrush(QBrush(QColor("forestgreen")));
        }
    }
}

void Scene::updateView()
{
    foreach (CellItem* cellItem, m_cellItems) {
        cellItem->updateView();
    }
}

CellItem*Scene::clickedCellItem(QPointF clickedScenePos)
{
    QList<QGraphicsItem *> clickedItems = items(clickedScenePos);
    if(clickedItems.isEmpty()){
        return Q_NULLPTR;
    }
    return dynamic_cast<CellItem*>(clickedItems.at(0));
}

void Scene::setBoard(Board *board)
{
    m_board = board;
}

void Scene::checkWinner(Color nowColor)
{
    if(m_board->isBoardFilled()){
        QString winner;
        if(BLACK == nowColor){
            winner = "Black";
        }
        else{
            winner = "White";
        }
        QMessageBox::information(Q_NULLPTR,
                                 "Infomation",
                                 winner + " win !");
    }
}
