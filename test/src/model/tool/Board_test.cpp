#include "gtest/gtest.h"

using namespace ::testing;

#define private   public
#define protected public

#include "Board.h"
#include "Cell.h"
#include "Stone.h"

class Board_test : public ::testing::Test
{
protected:
    virtual void SetUp()
    {
        //write this test class setup process
    }

    virtual void TearDown()
    {
        //write this test class end process
    }
};

TEST_F(Board_test, add)
{
    Board board;
    //ASSERT_EQ(, Eq());
}

TEST_F(Board_test, checkSelectableCells)
{
    Board board;
    Cell c[64];

    for (int i = 0; i < 64; ++i) {
        Stone* stone = new Stone(NONE);
        board.m_cells << &c[i];
        c[i].setStone(stone);
    }
    c[27].stone()->setColor(WHITE);
    c[28].stone()->setColor(BLACK);
    c[35].stone()->setColor(BLACK);
    c[36].stone()->setColor(WHITE);

    board.checkSelectableCells(WHITE);

//    ASSERT_EQ(, Eq());
}

TEST_F(Board_test, reversableDirection)
{
    Board board;
    //ASSERT_EQ(, Eq());
}

TEST_F(Board_test, reverseStones)
{
//    Board board;
//    Cell c0;
//    Cell c1;
//    Cell c2;
//    Cell c3;

//    c0.stone()->setColor(WHITE);
//    c1.stone()->setColor(BLACK);
//    c2.stone()->setColor(BLACK);
//    c3.stone()->setColor(NONE);

//    board.m_cells << &c0;
//    board.m_cells << &c1;
//    board.m_cells << &c2;
//    board.m_cells << &c3;

//    board.reverseStone(WHITE, &c2, Board::UPPER);
//    ASSERT_EQ(board.m_cells.at(0)->stoneColor(), WHITE);
//    ASSERT_EQ(board.m_cells.at(1)->stoneColor(), WHITE);
//    ASSERT_EQ(board.m_cells.at(2)->stoneColor(), WHITE);
//    ASSERT_EQ(board.cell(3)->stoneColor(), WHITE);
}

TEST_F(Board_test, cell)
{
    Board board;
    //ASSERT_EQ(, Eq());
}

TEST_F(Board_test, cells)
{
    Board board;
    //ASSERT_EQ(, Eq());
}

TEST_F(Board_test, checkPlace)
{
    Board board;
    //ASSERT_EQ(, Eq());
}

TEST_F(Board_test, reverseStone)
{
    Board board;
    //ASSERT_EQ(, Eq());
}

TEST_F(Board_test, isReversableCell)
{
//    Board board;
//    Cell c0;
//    Cell c1;
//    Cell c2;
//    Cell c3;

//    c0.stone()->setColor(WHITE);
//    c1.stone()->setColor(BLACK);
//    c2.stone()->setColor(BLACK);
//    c3.stone()->setColor(NONE);

//    board.m_cells << &c0;
//    board.m_cells << &c1;
//    board.m_cells << &c2;
//    board.m_cells << &c3;

//    board.reverseStone(WHITE, &c2, Board::UPPER);
//    ASSERT_EQ(board.m_cells.at(0)->stoneColor(), WHITE);
//    ASSERT_EQ(board.m_cells.at(1)->stoneColor(), WHITE);
//    ASSERT_EQ(board.m_cells.at(2)->stoneColor(), WHITE);
}

TEST_F(Board_test, isOppositeStoneSameColor)
{
    Board board;
    Cell c[64];

    for (int i = 0; i < 64; ++i) {
        Stone* stone = new Stone(NONE);
        board.m_cells << &c[i];
        c[i].setStone(stone);
    }

    //UPPER
    board.m_cells.at(8)->stone()->setColor(WHITE);
    board.m_cells.at(9)->stone()->setColor(BLACK);
    board.m_cells.at(10)->stone()->setColor(BLACK);
    ASSERT_EQ(board.isReversable(board.m_cells.at(11), WHITE, Board::UPPER), true);

    board.m_cells.at(8)->stone()->setColor(BLACK);
    board.m_cells.at(9)->stone()->setColor(BLACK);
    board.m_cells.at(10)->stone()->setColor(BLACK);
    ASSERT_EQ(board.isReversable(board.m_cells.at(11), WHITE, Board::UPPER), false);

    board.m_cells.at(8)->stone()->setColor(NONE);
    board.m_cells.at(9)->stone()->setColor(BLACK);
    board.m_cells.at(10)->stone()->setColor(BLACK);
    ASSERT_EQ(board.isReversable(board.m_cells.at(11), WHITE, Board::UPPER), false);

    //UPPER_LEFT
    board.m_cells.at(0)->stone()->setColor(WHITE);
    board.m_cells.at(9)->stone()->setColor(BLACK);
    board.m_cells.at(18)->stone()->setColor(BLACK);
    ASSERT_EQ(board.isReversable(board.m_cells.at(27), WHITE, Board::UPPER_LEFT), true);

    board.m_cells.at(0)->stone()->setColor(BLACK);
    board.m_cells.at(9)->stone()->setColor(BLACK);
    board.m_cells.at(18)->stone()->setColor(BLACK);
    ASSERT_EQ(board.isReversable(board.m_cells.at(27), WHITE, Board::UPPER_LEFT), false);

    board.m_cells.at(0)->stone()->setColor(NONE);
    board.m_cells.at(9)->stone()->setColor(BLACK);
    board.m_cells.at(18)->stone()->setColor(BLACK);
    ASSERT_EQ(board.isReversable(board.m_cells.at(27), WHITE, Board::UPPER_LEFT), false);

    //LEFT
    board.m_cells.at(0)->stone()->setColor(WHITE);
    board.m_cells.at(8)->stone()->setColor(BLACK);
    board.m_cells.at(16)->stone()->setColor(BLACK);
    ASSERT_EQ(board.isReversable(board.m_cells.at(24), WHITE, Board::LEFT), true);

    board.m_cells.at(0)->stone()->setColor(BLACK);
    board.m_cells.at(8)->stone()->setColor(BLACK);
    board.m_cells.at(16)->stone()->setColor(BLACK);
    ASSERT_EQ(board.isReversable(board.m_cells.at(24), WHITE, Board::LEFT), false);

    board.m_cells.at(0)->stone()->setColor(NONE);
    board.m_cells.at(8)->stone()->setColor(BLACK);
    board.m_cells.at(16)->stone()->setColor(BLACK);
    ASSERT_EQ(board.isReversable(board.m_cells.at(24), WHITE, Board::LEFT), false);

    //LOWER_LEFT
    board.m_cells.at(7)->stone()->setColor(WHITE);
    board.m_cells.at(14)->stone()->setColor(BLACK);
    board.m_cells.at(21)->stone()->setColor(BLACK);
    ASSERT_EQ(board.isReversable(board.m_cells.at(28), WHITE, Board::LOWER_LEFT), true);

    board.m_cells.at(7)->stone()->setColor(BLACK);
    board.m_cells.at(14)->stone()->setColor(BLACK);
    board.m_cells.at(21)->stone()->setColor(BLACK);
    ASSERT_EQ(board.isReversable(board.m_cells.at(28), WHITE, Board::LOWER_LEFT), false);

    board.m_cells.at(7)->stone()->setColor(NONE);
    board.m_cells.at(14)->stone()->setColor(BLACK);
    board.m_cells.at(21)->stone()->setColor(BLACK);
    ASSERT_EQ(board.isReversable(board.m_cells.at(28), WHITE, Board::LOWER_LEFT), false);

    //LOWER
    board.m_cells.at(7)->stone()->setColor(WHITE);
    board.m_cells.at(6)->stone()->setColor(BLACK);
    board.m_cells.at(5)->stone()->setColor(BLACK);
    ASSERT_EQ(board.isReversable(board.m_cells.at(4), WHITE, Board::LOWER), true);

    board.m_cells.at(7)->stone()->setColor(BLACK);
    board.m_cells.at(6)->stone()->setColor(BLACK);
    board.m_cells.at(5)->stone()->setColor(BLACK);
    ASSERT_EQ(board.isReversable(board.m_cells.at(4), WHITE, Board::LOWER), false);

    board.m_cells.at(7)->stone()->setColor(NONE);
    board.m_cells.at(6)->stone()->setColor(BLACK);
    board.m_cells.at(5)->stone()->setColor(BLACK);
    ASSERT_EQ(board.isReversable(board.m_cells.at(4), WHITE, Board::LOWER), false);

    //LOWER_RIGHT
    board.m_cells.at(63)->stone()->setColor(WHITE);
    board.m_cells.at(54)->stone()->setColor(BLACK);
    board.m_cells.at(45)->stone()->setColor(BLACK);
    ASSERT_EQ(board.isReversable(board.m_cells.at(36), WHITE, Board::LOWER_RIGHT), true);

    board.m_cells.at(63)->stone()->setColor(BLACK);
    board.m_cells.at(54)->stone()->setColor(BLACK);
    board.m_cells.at(45)->stone()->setColor(BLACK);
    ASSERT_EQ(board.isReversable(board.m_cells.at(36), WHITE, Board::LOWER_RIGHT), false);

    board.m_cells.at(63)->stone()->setColor(NONE);
    board.m_cells.at(54)->stone()->setColor(BLACK);
    board.m_cells.at(45)->stone()->setColor(BLACK);
    ASSERT_EQ(board.isReversable(board.m_cells.at(36), WHITE, Board::LOWER_RIGHT), false);

    //RIGHT
    board.m_cells.at(63)->stone()->setColor(WHITE);
    board.m_cells.at(55)->stone()->setColor(BLACK);
    board.m_cells.at(47)->stone()->setColor(BLACK);
    ASSERT_EQ(board.isReversable(board.m_cells.at(39), WHITE, Board::RIGHT), true);

    board.m_cells.at(63)->stone()->setColor(BLACK);
    board.m_cells.at(55)->stone()->setColor(BLACK);
    board.m_cells.at(47)->stone()->setColor(BLACK);
    ASSERT_EQ(board.isReversable(board.m_cells.at(39), WHITE, Board::RIGHT), false);

    board.m_cells.at(63)->stone()->setColor(NONE);
    board.m_cells.at(55)->stone()->setColor(BLACK);
    board.m_cells.at(47)->stone()->setColor(BLACK);
    ASSERT_EQ(board.isReversable(board.m_cells.at(39), WHITE, Board::RIGHT), false);

    //UPPER_RIGHT
    board.m_cells.at(56)->stone()->setColor(WHITE);
    board.m_cells.at(49)->stone()->setColor(BLACK);
    board.m_cells.at(42)->stone()->setColor(BLACK);
    ASSERT_EQ(board.isReversable(board.m_cells.at(35), WHITE, Board::UPPER_RIGHT), true);

    board.m_cells.at(56)->stone()->setColor(BLACK);
    board.m_cells.at(49)->stone()->setColor(BLACK);
    board.m_cells.at(42)->stone()->setColor(BLACK);
    ASSERT_EQ(board.isReversable(board.m_cells.at(35), WHITE, Board::UPPER_RIGHT), false);

    board.m_cells.at(56)->stone()->setColor(NONE);
    board.m_cells.at(49)->stone()->setColor(BLACK);
    board.m_cells.at(42)->stone()->setColor(BLACK);
    ASSERT_EQ(board.isReversable(board.m_cells.at(35), WHITE, Board::UPPER_RIGHT), false);
}

TEST_F(Board_test, isInvalidIndex)
{
    Board board;
    //ASSERT_EQ(, Eq());
}

//TEST_F(Board_test, insideFieldDirections)
//{
//    Board board;
//    Cell c[64];

//    for (int i = 0; i < 64; ++i) {
//        c[i].stone()->setColor(NONE);
//        board.m_cells << &c[i];
//    }
//    c[27].stone()->setColor(WHITE);
//    c[28].stone()->setColor(BLACK);
//    c[35].stone()->setColor(BLACK);
//    c[36].stone()->setColor(WHITE);

//    ASSERT_EQ(board.insideFieldDirections(&c[0]).contains(Board::UPPER_LEFT),  false);
//    ASSERT_EQ(board.insideFieldDirections(&c[0]).contains(Board::UPPER),       false);
//    ASSERT_EQ(board.insideFieldDirections(&c[0]).contains(Board::UPPER_RIGHT), false);
//    ASSERT_EQ(board.insideFieldDirections(&c[0]).contains(Board::LEFT),        false);
//    ASSERT_EQ(board.insideFieldDirections(&c[0]).contains(Board::RIGHT),       true);
//    ASSERT_EQ(board.insideFieldDirections(&c[0]).contains(Board::LOWER_LEFT),  false);
//    ASSERT_EQ(board.insideFieldDirections(&c[0]).contains(Board::LOWER),       true);
//    ASSERT_EQ(board.insideFieldDirections(&c[0]).contains(Board::LOWER_RIGHT), true);

//    ASSERT_EQ(board.insideFieldDirections(&c[1]).contains(Board::UPPER_LEFT),  false);
//    ASSERT_EQ(board.insideFieldDirections(&c[1]).contains(Board::UPPER),       true);
//    ASSERT_EQ(board.insideFieldDirections(&c[1]).contains(Board::UPPER_RIGHT), true);
//    ASSERT_EQ(board.insideFieldDirections(&c[1]).contains(Board::LEFT),        false);
//    ASSERT_EQ(board.insideFieldDirections(&c[1]).contains(Board::RIGHT),       true);
//    ASSERT_EQ(board.insideFieldDirections(&c[1]).contains(Board::LOWER_LEFT),  false);
//    ASSERT_EQ(board.insideFieldDirections(&c[1]).contains(Board::LOWER),       true);
//    ASSERT_EQ(board.insideFieldDirections(&c[1]).contains(Board::LOWER_RIGHT), true);

//    ASSERT_EQ(board.insideFieldDirections(&c[18]).contains(Board::UPPER_LEFT),  true);
//    ASSERT_EQ(board.insideFieldDirections(&c[18]).contains(Board::UPPER),       true);
//    ASSERT_EQ(board.insideFieldDirections(&c[18]).contains(Board::UPPER_RIGHT), true);
//    ASSERT_EQ(board.insideFieldDirections(&c[18]).contains(Board::LEFT),        true);
//    ASSERT_EQ(board.insideFieldDirections(&c[18]).contains(Board::RIGHT),       true);
//    ASSERT_EQ(board.insideFieldDirections(&c[18]).contains(Board::LOWER_LEFT),  true);
//    ASSERT_EQ(board.insideFieldDirections(&c[18]).contains(Board::LOWER),       true);
//    ASSERT_EQ(board.insideFieldDirections(&c[18]).contains(Board::LOWER_RIGHT), true);

//    ASSERT_EQ(board.insideFieldDirections(&c[63]).contains(Board::UPPER_LEFT),  true);
//    ASSERT_EQ(board.insideFieldDirections(&c[63]).contains(Board::UPPER),       true);
//    ASSERT_EQ(board.insideFieldDirections(&c[63]).contains(Board::UPPER_RIGHT), false);
//    ASSERT_EQ(board.insideFieldDirections(&c[63]).contains(Board::LEFT),        true);
//    ASSERT_EQ(board.insideFieldDirections(&c[63]).contains(Board::RIGHT),       false);
//    ASSERT_EQ(board.insideFieldDirections(&c[63]).contains(Board::LOWER_LEFT),  false);
//    ASSERT_EQ(board.insideFieldDirections(&c[63]).contains(Board::LOWER),       false);
//    ASSERT_EQ(board.insideFieldDirections(&c[63]).contains(Board::LOWER_RIGHT), false);
//}

TEST_F(Board_test, isSelectableCell)
{
    Board board;
    Cell c[64];

    for (int i = 0; i < 64; ++i) {
        Stone* stone = new Stone(NONE);
        board.m_cells << &c[i];
        c[i].setStone(stone);
    }

    c[27].stone()->setColor(WHITE);
    c[28].stone()->setColor(BLACK);
    c[35].stone()->setColor(BLACK);
    c[36].stone()->setColor(WHITE);

    board.checkSelectableCells(BLACK);
    ASSERT_EQ(board.canSelect(&c[18]), false);
    board.checkSelectableCells(WHITE);
    ASSERT_EQ(board.canSelect(&c[18]), false);

    board.checkSelectableCells(BLACK);
    ASSERT_EQ(board.canSelect(&c[19]), true);
    board.checkSelectableCells(WHITE);
    ASSERT_EQ(board.canSelect(&c[19]), false);

    board.checkSelectableCells(BLACK);
    ASSERT_EQ(board.canSelect(&c[20]), false);
    board.checkSelectableCells(WHITE);
    ASSERT_EQ(board.canSelect(&c[20]), true);

    board.checkSelectableCells(BLACK);
    ASSERT_EQ(board.canSelect(&c[21]), false);
    board.checkSelectableCells(WHITE);
    ASSERT_EQ(board.canSelect(&c[21]), false);

    board.checkSelectableCells(BLACK);
    ASSERT_EQ(board.canSelect(&c[26]), true);
    board.checkSelectableCells(WHITE);
    ASSERT_EQ(board.canSelect(&c[26]), false);

    board.checkSelectableCells(BLACK);
    ASSERT_EQ(board.canSelect(&c[29]), false);
    board.checkSelectableCells(WHITE);
    ASSERT_EQ(board.canSelect(&c[29]), true);

    board.checkSelectableCells(BLACK);
    ASSERT_EQ(board.canSelect(&c[34]), false);
    board.checkSelectableCells(WHITE);
    ASSERT_EQ(board.canSelect(&c[34]), true);

    board.checkSelectableCells(BLACK);
    ASSERT_EQ(board.canSelect(&c[37]), true);
    board.checkSelectableCells(WHITE);
    ASSERT_EQ(board.canSelect(&c[37]), false);

    board.checkSelectableCells(BLACK);
    ASSERT_EQ(board.canSelect(&c[42]), false);
    board.checkSelectableCells(WHITE);
    ASSERT_EQ(board.canSelect(&c[42]), false);

    board.checkSelectableCells(BLACK);
    ASSERT_EQ(board.canSelect(&c[43]), false);
    board.checkSelectableCells(WHITE);
    ASSERT_EQ(board.canSelect(&c[43]), true);

    board.checkSelectableCells(BLACK);
    ASSERT_EQ(board.canSelect(&c[44]), true);
    board.checkSelectableCells(WHITE);
    ASSERT_EQ(board.canSelect(&c[44]), false);

    board.checkSelectableCells(BLACK);
    ASSERT_EQ(board.canSelect(&c[45]), false);
    board.checkSelectableCells(WHITE);
    ASSERT_EQ(board.canSelect(&c[45]), false);
}

TEST_F(Board_test, isReversable)
{
    Board board;
    Cell c[64];

    for (int i = 0; i < 64; ++i) {
        Stone* stone = new Stone(NONE);
        board.m_cells << &c[i];
        c[i].setStone(stone);
    }

    c[0].stone()->setColor(WHITE);
    ASSERT_EQ(board.isReversable(&c[1], WHITE, Board::UPPER_LEFT), false);
    c[0].stone()->setColor(WHITE);
    ASSERT_EQ(board.isReversable(&c[1], BLACK, Board::UPPER_LEFT), false);
    c[0].stone()->setColor(NONE);


    c[9].stone()->setColor(WHITE);
    ASSERT_EQ(board.isReversable(&c[18], WHITE, Board::UPPER_LEFT), false);
    c[9].stone()->setColor(WHITE);
    ASSERT_EQ(board.isReversable(&c[18], BLACK, Board::UPPER_LEFT), false);


    c[0].stone()->setColor(WHITE);
    c[9].stone()->setColor(WHITE);
    ASSERT_EQ(board.isReversable(&c[18], WHITE, Board::UPPER_LEFT), false);
    c[0].stone()->setColor(BLACK);
    c[9].stone()->setColor(WHITE);
    ASSERT_EQ(board.isReversable(&c[18], WHITE, Board::UPPER_LEFT), false);
    c[0].stone()->setColor(BLACK);
    c[9].stone()->setColor(WHITE);
    ASSERT_EQ(board.isReversable(&c[18], BLACK, Board::UPPER_LEFT), true);
    c[0].stone()->setColor(NONE);
    c[9].stone()->setColor(NONE);


    c[0].stone()->setColor(BLACK);
    c[9].stone()->setColor(WHITE);
    c[18].stone()->setColor(WHITE);
    ASSERT_EQ(board.isReversable(&c[27], WHITE, Board::UPPER_LEFT), false);
    c[0].stone()->setColor(BLACK);
    c[9].stone()->setColor(WHITE);
    c[18].stone()->setColor(WHITE);
    ASSERT_EQ(board.isReversable(&c[27], BLACK, Board::UPPER_LEFT), true);
}

TEST_F(Board_test, neighborCells)
{
    Board board;
    Cell c[64];

    for (int i = 0; i < 64; ++i) {
        Stone* stone = new Stone(NONE);
        board.m_cells << &c[i];
        c[i].setStone(stone);
    }

    QList<Cell*> cells = board.neighborCells(&c[0]);

    ASSERT_EQ(cells.count(), 3);
    ASSERT_EQ(cells.contains(&c[1]), true);
    ASSERT_EQ(cells.contains(&c[9]), true);
    ASSERT_EQ(cells.contains(&c[8]), true);
}

TEST_F(Board_test, neighborCell)
{
    Board board;
    Cell c[64];

    for (int i = 0; i < 64; ++i) {
        Stone* stone = new Stone(NONE);
        board.m_cells << &c[i];
        c[i].setStone(stone);
    }

    ASSERT_EQ(board.neighborCell(&c[0], Board::UPPER),        nullptr);
    ASSERT_EQ(board.neighborCell(&c[0], Board::UPPER_LEFT),   nullptr);
    ASSERT_EQ(board.neighborCell(&c[0], Board::LEFT),         nullptr);
    ASSERT_EQ(board.neighborCell(&c[0], Board::LOWER_LEFT),   nullptr);
    ASSERT_EQ(board.neighborCell(&c[0], Board::LOWER),        &c[1]);
    ASSERT_EQ(board.neighborCell(&c[0], Board::LOWER_RIGHT),  &c[9]);
    ASSERT_EQ(board.neighborCell(&c[0], Board::RIGHT),        &c[8]);
    ASSERT_EQ(board.neighborCell(&c[0], Board::UPPER_RIGHT),  nullptr);

    ASSERT_EQ(board.neighborCell(&c[9], Board::UPPER),        &c[8]);
    ASSERT_EQ(board.neighborCell(&c[9], Board::UPPER_LEFT),   &c[0]);
    ASSERT_EQ(board.neighborCell(&c[9], Board::LEFT),         &c[1]);
    ASSERT_EQ(board.neighborCell(&c[9], Board::LOWER_LEFT),   &c[2]);
    ASSERT_EQ(board.neighborCell(&c[9], Board::LOWER),        &c[10]);
    ASSERT_EQ(board.neighborCell(&c[9], Board::LOWER_RIGHT),  &c[18]);
    ASSERT_EQ(board.neighborCell(&c[9], Board::RIGHT),        &c[17]);
    ASSERT_EQ(board.neighborCell(&c[9], Board::UPPER_RIGHT),  &c[16]);

    ASSERT_EQ(board.neighborCell(&c[63], Board::UPPER),       &c[62]);
    ASSERT_EQ(board.neighborCell(&c[63], Board::UPPER_LEFT),  &c[54]);
    ASSERT_EQ(board.neighborCell(&c[63], Board::LEFT),        &c[55]);
    ASSERT_EQ(board.neighborCell(&c[63], Board::LOWER_LEFT),  nullptr);
    ASSERT_EQ(board.neighborCell(&c[63], Board::LOWER),       nullptr);
    ASSERT_EQ(board.neighborCell(&c[63], Board::LOWER_RIGHT), nullptr);
    ASSERT_EQ(board.neighborCell(&c[63], Board::RIGHT),       nullptr);
    ASSERT_EQ(board.neighborCell(&c[63], Board::UPPER_RIGHT), nullptr);
}

TEST_F(Board_test, isOutside)
{
    Board board;
    Cell c[64];

    for (int i = 0; i < 64; ++i) {
        Stone* stone = new Stone(NONE);
        board.m_cells << &c[i];
        c[i].setStone(stone);
    }

    ASSERT_EQ(board.isOutside(&c[0], Board::UPPER_LEFT),  true);
    ASSERT_EQ(board.isOutside(&c[0], Board::UPPER),       true);
    ASSERT_EQ(board.isOutside(&c[0], Board::UPPER_RIGHT), true);
    ASSERT_EQ(board.isOutside(&c[0], Board::LEFT)       , true);
    ASSERT_EQ(board.isOutside(&c[0], Board::RIGHT),       false);
    ASSERT_EQ(board.isOutside(&c[0], Board::LOWER_LEFT),  true);
    ASSERT_EQ(board.isOutside(&c[0], Board::LOWER),       false);
    ASSERT_EQ(board.isOutside(&c[0], Board::LOWER_RIGHT), false);

    ASSERT_EQ(board.isOutside(&c[1], Board::UPPER_LEFT),  true);
    ASSERT_EQ(board.isOutside(&c[1], Board::UPPER),       false);
    ASSERT_EQ(board.isOutside(&c[1], Board::UPPER_RIGHT), false);
    ASSERT_EQ(board.isOutside(&c[1], Board::LEFT)       , true);
    ASSERT_EQ(board.isOutside(&c[1], Board::RIGHT),       false);
    ASSERT_EQ(board.isOutside(&c[1], Board::LOWER_LEFT),  true);
    ASSERT_EQ(board.isOutside(&c[1], Board::LOWER),       false);
    ASSERT_EQ(board.isOutside(&c[1], Board::LOWER_RIGHT), false);

    ASSERT_EQ(board.isOutside(&c[8], Board::UPPER_LEFT),  true);
    ASSERT_EQ(board.isOutside(&c[8], Board::UPPER),       true);
    ASSERT_EQ(board.isOutside(&c[8], Board::UPPER_RIGHT), true);
    ASSERT_EQ(board.isOutside(&c[8], Board::LEFT)       , false);
    ASSERT_EQ(board.isOutside(&c[8], Board::RIGHT),       false);
    ASSERT_EQ(board.isOutside(&c[8], Board::LOWER_LEFT),  false);
    ASSERT_EQ(board.isOutside(&c[8], Board::LOWER),       false);
    ASSERT_EQ(board.isOutside(&c[8], Board::LOWER_RIGHT), false);

    ASSERT_EQ(board.isOutside(&c[15], Board::UPPER_LEFT),  false);
    ASSERT_EQ(board.isOutside(&c[15], Board::UPPER),       false);
    ASSERT_EQ(board.isOutside(&c[15], Board::UPPER_RIGHT), false);
    ASSERT_EQ(board.isOutside(&c[15], Board::LEFT)       , false);
    ASSERT_EQ(board.isOutside(&c[15], Board::RIGHT),       false);
    ASSERT_EQ(board.isOutside(&c[15], Board::LOWER_LEFT),  true);
    ASSERT_EQ(board.isOutside(&c[15], Board::LOWER),       true);
    ASSERT_EQ(board.isOutside(&c[15], Board::LOWER_RIGHT), true);

    ASSERT_EQ(board.isOutside(&c[63], Board::UPPER_LEFT),  false);
    ASSERT_EQ(board.isOutside(&c[63], Board::UPPER),       false);
    ASSERT_EQ(board.isOutside(&c[63], Board::UPPER_RIGHT), true);
    ASSERT_EQ(board.isOutside(&c[63], Board::LEFT)       , false);
    ASSERT_EQ(board.isOutside(&c[63], Board::RIGHT),       true);
    ASSERT_EQ(board.isOutside(&c[63], Board::LOWER_LEFT),  true);
    ASSERT_EQ(board.isOutside(&c[63], Board::LOWER),       true);
    ASSERT_EQ(board.isOutside(&c[63], Board::LOWER_RIGHT), true);
}
