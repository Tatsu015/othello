#include "gtest/gtest.h"

using namespace ::testing;

#define private   public
#define protected public

#include "Board.h"
#include "Cell.h"

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
        c[i].setStoneColor(NONE);
        board.m_cells << &c[i];
    }
    c[27].setStoneColor(WHITE);
    c[28].setStoneColor(BLACK);
    c[35].setStoneColor(BLACK);
    c[36].setStoneColor(WHITE);

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
    Board board;
    Cell c0;
    Cell c1;
    Cell c2;
    Cell c3;

    c0.setStoneColor(WHITE);
    c1.setStoneColor(BLACK);
    c2.setStoneColor(BLACK);
    c3.setStoneColor(NONE);

    board.m_cells << &c0;
    board.m_cells << &c1;
    board.m_cells << &c2;
    board.m_cells << &c3;

    board.reverseStone(WHITE, &c2, Board::UPPER);
    ASSERT_EQ(board.m_cells.at(0)->stoneColor(), WHITE);
    ASSERT_EQ(board.m_cells.at(1)->stoneColor(), WHITE);
    ASSERT_EQ(board.m_cells.at(2)->stoneColor(), WHITE);
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

//    c0.setStoneColor(WHITE);
//    c1.setStoneColor(BLACK);
//    c2.setStoneColor(BLACK);
//    c3.setStoneColor(NONE);

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
        c[i].setStoneColor(NONE);
        board.m_cells << &c[i];
    }

    //UPPER
    board.m_cells.at(8)->setStoneColor(WHITE);
    board.m_cells.at(9)->setStoneColor(BLACK);
    board.m_cells.at(10)->setStoneColor(BLACK);
    ASSERT_EQ(board.isOppositeStoneSameColor(board.m_cells.at(11), WHITE, Board::UPPER), true);

    board.m_cells.at(8)->setStoneColor(BLACK);
    board.m_cells.at(9)->setStoneColor(BLACK);
    board.m_cells.at(10)->setStoneColor(BLACK);
    ASSERT_EQ(board.isOppositeStoneSameColor(board.m_cells.at(11), WHITE, Board::UPPER), false);

    board.m_cells.at(8)->setStoneColor(NONE);
    board.m_cells.at(9)->setStoneColor(BLACK);
    board.m_cells.at(10)->setStoneColor(BLACK);
    ASSERT_EQ(board.isOppositeStoneSameColor(board.m_cells.at(11), WHITE, Board::UPPER), false);

    //UPPER_LEFT
    board.m_cells.at(0)->setStoneColor(WHITE);
    board.m_cells.at(9)->setStoneColor(BLACK);
    board.m_cells.at(18)->setStoneColor(BLACK);
    ASSERT_EQ(board.isOppositeStoneSameColor(board.m_cells.at(27), WHITE, Board::UPPER_LEFT), true);

    board.m_cells.at(0)->setStoneColor(BLACK);
    board.m_cells.at(9)->setStoneColor(BLACK);
    board.m_cells.at(18)->setStoneColor(BLACK);
    ASSERT_EQ(board.isOppositeStoneSameColor(board.m_cells.at(27), WHITE, Board::UPPER_LEFT), false);

    board.m_cells.at(0)->setStoneColor(NONE);
    board.m_cells.at(9)->setStoneColor(BLACK);
    board.m_cells.at(18)->setStoneColor(BLACK);
    ASSERT_EQ(board.isOppositeStoneSameColor(board.m_cells.at(27), WHITE, Board::UPPER_LEFT), false);

    //LEFT
    board.m_cells.at(0)->setStoneColor(WHITE);
    board.m_cells.at(8)->setStoneColor(BLACK);
    board.m_cells.at(16)->setStoneColor(BLACK);
    ASSERT_EQ(board.isOppositeStoneSameColor(board.m_cells.at(24), WHITE, Board::LEFT), true);

    board.m_cells.at(0)->setStoneColor(BLACK);
    board.m_cells.at(8)->setStoneColor(BLACK);
    board.m_cells.at(16)->setStoneColor(BLACK);
    ASSERT_EQ(board.isOppositeStoneSameColor(board.m_cells.at(24), WHITE, Board::LEFT), false);

    board.m_cells.at(0)->setStoneColor(NONE);
    board.m_cells.at(8)->setStoneColor(BLACK);
    board.m_cells.at(16)->setStoneColor(BLACK);
    ASSERT_EQ(board.isOppositeStoneSameColor(board.m_cells.at(24), WHITE, Board::LEFT), false);

    //LOWER_LEFT
    board.m_cells.at(7)->setStoneColor(WHITE);
    board.m_cells.at(14)->setStoneColor(BLACK);
    board.m_cells.at(21)->setStoneColor(BLACK);
    ASSERT_EQ(board.isOppositeStoneSameColor(board.m_cells.at(28), WHITE, Board::LOWER_LEFT), true);

    board.m_cells.at(7)->setStoneColor(BLACK);
    board.m_cells.at(14)->setStoneColor(BLACK);
    board.m_cells.at(21)->setStoneColor(BLACK);
    ASSERT_EQ(board.isOppositeStoneSameColor(board.m_cells.at(28), WHITE, Board::LOWER_LEFT), false);

    board.m_cells.at(7)->setStoneColor(NONE);
    board.m_cells.at(14)->setStoneColor(BLACK);
    board.m_cells.at(21)->setStoneColor(BLACK);
    ASSERT_EQ(board.isOppositeStoneSameColor(board.m_cells.at(28), WHITE, Board::LOWER_LEFT), false);

    //LOWER
    board.m_cells.at(7)->setStoneColor(WHITE);
    board.m_cells.at(6)->setStoneColor(BLACK);
    board.m_cells.at(5)->setStoneColor(BLACK);
    ASSERT_EQ(board.isOppositeStoneSameColor(board.m_cells.at(4), WHITE, Board::LOWER), true);

    board.m_cells.at(7)->setStoneColor(BLACK);
    board.m_cells.at(6)->setStoneColor(BLACK);
    board.m_cells.at(5)->setStoneColor(BLACK);
    ASSERT_EQ(board.isOppositeStoneSameColor(board.m_cells.at(4), WHITE, Board::LOWER), false);

    board.m_cells.at(7)->setStoneColor(NONE);
    board.m_cells.at(6)->setStoneColor(BLACK);
    board.m_cells.at(5)->setStoneColor(BLACK);
    ASSERT_EQ(board.isOppositeStoneSameColor(board.m_cells.at(4), WHITE, Board::LOWER), false);

    //LOWER_RIGHT
    board.m_cells.at(63)->setStoneColor(WHITE);
    board.m_cells.at(54)->setStoneColor(BLACK);
    board.m_cells.at(45)->setStoneColor(BLACK);
    ASSERT_EQ(board.isOppositeStoneSameColor(board.m_cells.at(36), WHITE, Board::LOWER_RIGHT), true);

    board.m_cells.at(63)->setStoneColor(BLACK);
    board.m_cells.at(54)->setStoneColor(BLACK);
    board.m_cells.at(45)->setStoneColor(BLACK);
    ASSERT_EQ(board.isOppositeStoneSameColor(board.m_cells.at(36), WHITE, Board::LOWER_RIGHT), false);

    board.m_cells.at(63)->setStoneColor(NONE);
    board.m_cells.at(54)->setStoneColor(BLACK);
    board.m_cells.at(45)->setStoneColor(BLACK);
    ASSERT_EQ(board.isOppositeStoneSameColor(board.m_cells.at(36), WHITE, Board::LOWER_RIGHT), false);

    //RIGHT
    board.m_cells.at(63)->setStoneColor(WHITE);
    board.m_cells.at(55)->setStoneColor(BLACK);
    board.m_cells.at(47)->setStoneColor(BLACK);
    ASSERT_EQ(board.isOppositeStoneSameColor(board.m_cells.at(39), WHITE, Board::RIGHT), true);

    board.m_cells.at(63)->setStoneColor(BLACK);
    board.m_cells.at(55)->setStoneColor(BLACK);
    board.m_cells.at(47)->setStoneColor(BLACK);
    ASSERT_EQ(board.isOppositeStoneSameColor(board.m_cells.at(39), WHITE, Board::RIGHT), false);

    board.m_cells.at(63)->setStoneColor(NONE);
    board.m_cells.at(55)->setStoneColor(BLACK);
    board.m_cells.at(47)->setStoneColor(BLACK);
    ASSERT_EQ(board.isOppositeStoneSameColor(board.m_cells.at(39), WHITE, Board::RIGHT), false);

    //UPPER_RIGHT
    board.m_cells.at(56)->setStoneColor(WHITE);
    board.m_cells.at(49)->setStoneColor(BLACK);
    board.m_cells.at(42)->setStoneColor(BLACK);
    ASSERT_EQ(board.isOppositeStoneSameColor(board.m_cells.at(35), WHITE, Board::UPPER_RIGHT), true);

    board.m_cells.at(56)->setStoneColor(BLACK);
    board.m_cells.at(49)->setStoneColor(BLACK);
    board.m_cells.at(42)->setStoneColor(BLACK);
    ASSERT_EQ(board.isOppositeStoneSameColor(board.m_cells.at(35), WHITE, Board::UPPER_RIGHT), false);

    board.m_cells.at(56)->setStoneColor(NONE);
    board.m_cells.at(49)->setStoneColor(BLACK);
    board.m_cells.at(42)->setStoneColor(BLACK);
    ASSERT_EQ(board.isOppositeStoneSameColor(board.m_cells.at(35), WHITE, Board::UPPER_RIGHT), false);
}

TEST_F(Board_test, isInvalidIndex)
{
    Board board;
    //ASSERT_EQ(, Eq());
}

TEST_F(Board_test, insideFieldDirections)
{
    Board board;
    Cell c[64];

    for (int i = 0; i < 64; ++i) {
        c[i].setStoneColor(NONE);
        board.m_cells << &c[i];
    }
    c[27].setStoneColor(WHITE);
    c[28].setStoneColor(BLACK);
    c[35].setStoneColor(BLACK);
    c[36].setStoneColor(WHITE);

    ASSERT_EQ(board.insideFieldDirections(&c[0]).contains(Board::UPPER_LEFT),  false);
    ASSERT_EQ(board.insideFieldDirections(&c[0]).contains(Board::UPPER),       false);
    ASSERT_EQ(board.insideFieldDirections(&c[0]).contains(Board::UPPER_RIGHT), false);
    ASSERT_EQ(board.insideFieldDirections(&c[0]).contains(Board::LEFT),        false);
    ASSERT_EQ(board.insideFieldDirections(&c[0]).contains(Board::RIGHT),       true);
    ASSERT_EQ(board.insideFieldDirections(&c[0]).contains(Board::LOWER_LEFT),  false);
    ASSERT_EQ(board.insideFieldDirections(&c[0]).contains(Board::LOWER),       true);
    ASSERT_EQ(board.insideFieldDirections(&c[0]).contains(Board::LOWER_RIGHT), true);

    ASSERT_EQ(board.insideFieldDirections(&c[1]).contains(Board::UPPER_LEFT),  false);
    ASSERT_EQ(board.insideFieldDirections(&c[1]).contains(Board::UPPER),       true);
    ASSERT_EQ(board.insideFieldDirections(&c[1]).contains(Board::UPPER_RIGHT), true);
    ASSERT_EQ(board.insideFieldDirections(&c[1]).contains(Board::LEFT),        false);
    ASSERT_EQ(board.insideFieldDirections(&c[1]).contains(Board::RIGHT),       true);
    ASSERT_EQ(board.insideFieldDirections(&c[1]).contains(Board::LOWER_LEFT),  false);
    ASSERT_EQ(board.insideFieldDirections(&c[1]).contains(Board::LOWER),       true);
    ASSERT_EQ(board.insideFieldDirections(&c[1]).contains(Board::LOWER_RIGHT), true);

    ASSERT_EQ(board.insideFieldDirections(&c[18]).contains(Board::UPPER_LEFT),  true);
    ASSERT_EQ(board.insideFieldDirections(&c[18]).contains(Board::UPPER),       true);
    ASSERT_EQ(board.insideFieldDirections(&c[18]).contains(Board::UPPER_RIGHT), true);
    ASSERT_EQ(board.insideFieldDirections(&c[18]).contains(Board::LEFT),        true);
    ASSERT_EQ(board.insideFieldDirections(&c[18]).contains(Board::RIGHT),       true);
    ASSERT_EQ(board.insideFieldDirections(&c[18]).contains(Board::LOWER_LEFT),  true);
    ASSERT_EQ(board.insideFieldDirections(&c[18]).contains(Board::LOWER),       true);
    ASSERT_EQ(board.insideFieldDirections(&c[18]).contains(Board::LOWER_RIGHT), true);

    ASSERT_EQ(board.insideFieldDirections(&c[63]).contains(Board::UPPER_LEFT),  true);
    ASSERT_EQ(board.insideFieldDirections(&c[63]).contains(Board::UPPER),       true);
    ASSERT_EQ(board.insideFieldDirections(&c[63]).contains(Board::UPPER_RIGHT), false);
    ASSERT_EQ(board.insideFieldDirections(&c[63]).contains(Board::LEFT),        true);
    ASSERT_EQ(board.insideFieldDirections(&c[63]).contains(Board::RIGHT),       false);
    ASSERT_EQ(board.insideFieldDirections(&c[63]).contains(Board::LOWER_LEFT),  false);
    ASSERT_EQ(board.insideFieldDirections(&c[63]).contains(Board::LOWER),       false);
    ASSERT_EQ(board.insideFieldDirections(&c[63]).contains(Board::LOWER_RIGHT), false);
}

TEST_F(Board_test, isInsideFieldDirection)
{
    Board board;
    Cell c[64];

    for (int i = 0; i < 64; ++i) {
        c[i].setStoneColor(NONE);
        board.m_cells << &c[i];
    }

    ASSERT_EQ(board.isInsideFieldDirection(&c[0], Board::UPPER_LEFT),  true);
    ASSERT_EQ(board.isInsideFieldDirection(&c[0], Board::UPPER),       true);
    ASSERT_EQ(board.isInsideFieldDirection(&c[0], Board::UPPER_RIGHT), true);
    ASSERT_EQ(board.isInsideFieldDirection(&c[0], Board::LEFT)       , true);
    ASSERT_EQ(board.isInsideFieldDirection(&c[0], Board::RIGHT),       false);
    ASSERT_EQ(board.isInsideFieldDirection(&c[0], Board::LOWER_LEFT),  true);
    ASSERT_EQ(board.isInsideFieldDirection(&c[0], Board::LOWER),       false);
    ASSERT_EQ(board.isInsideFieldDirection(&c[0], Board::LOWER_RIGHT), false);

    ASSERT_EQ(board.isInsideFieldDirection(&c[1], Board::UPPER_LEFT),  true);
    ASSERT_EQ(board.isInsideFieldDirection(&c[1], Board::UPPER),       false);
    ASSERT_EQ(board.isInsideFieldDirection(&c[1], Board::UPPER_RIGHT), false);
    ASSERT_EQ(board.isInsideFieldDirection(&c[1], Board::LEFT)       , true);
    ASSERT_EQ(board.isInsideFieldDirection(&c[1], Board::RIGHT),       false);
    ASSERT_EQ(board.isInsideFieldDirection(&c[1], Board::LOWER_LEFT),  true);
    ASSERT_EQ(board.isInsideFieldDirection(&c[1], Board::LOWER),       false);
    ASSERT_EQ(board.isInsideFieldDirection(&c[1], Board::LOWER_RIGHT), false);

    ASSERT_EQ(board.isInsideFieldDirection(&c[8], Board::UPPER_LEFT),  true);
    ASSERT_EQ(board.isInsideFieldDirection(&c[8], Board::UPPER),       true);
    ASSERT_EQ(board.isInsideFieldDirection(&c[8], Board::UPPER_RIGHT), true);
    ASSERT_EQ(board.isInsideFieldDirection(&c[8], Board::LEFT)       , false);
    ASSERT_EQ(board.isInsideFieldDirection(&c[8], Board::RIGHT),       false);
    ASSERT_EQ(board.isInsideFieldDirection(&c[8], Board::LOWER_LEFT),  false);
    ASSERT_EQ(board.isInsideFieldDirection(&c[8], Board::LOWER),       false);
    ASSERT_EQ(board.isInsideFieldDirection(&c[8], Board::LOWER_RIGHT), false);

    ASSERT_EQ(board.isInsideFieldDirection(&c[15], Board::UPPER_LEFT),  false);
    ASSERT_EQ(board.isInsideFieldDirection(&c[15], Board::UPPER),       false);
    ASSERT_EQ(board.isInsideFieldDirection(&c[15], Board::UPPER_RIGHT), false);
    ASSERT_EQ(board.isInsideFieldDirection(&c[15], Board::LEFT)       , false);
    ASSERT_EQ(board.isInsideFieldDirection(&c[15], Board::RIGHT),       false);
    ASSERT_EQ(board.isInsideFieldDirection(&c[15], Board::LOWER_LEFT),  true);
    ASSERT_EQ(board.isInsideFieldDirection(&c[15], Board::LOWER),       true);
    ASSERT_EQ(board.isInsideFieldDirection(&c[15], Board::LOWER_RIGHT), true);

    ASSERT_EQ(board.isInsideFieldDirection(&c[63], Board::UPPER_LEFT),  false);
    ASSERT_EQ(board.isInsideFieldDirection(&c[63], Board::UPPER),       false);
    ASSERT_EQ(board.isInsideFieldDirection(&c[63], Board::UPPER_RIGHT), true);
    ASSERT_EQ(board.isInsideFieldDirection(&c[63], Board::LEFT)       , false);
    ASSERT_EQ(board.isInsideFieldDirection(&c[63], Board::RIGHT),       true);
    ASSERT_EQ(board.isInsideFieldDirection(&c[63], Board::LOWER_LEFT),  true);
    ASSERT_EQ(board.isInsideFieldDirection(&c[63], Board::LOWER),       true);
    ASSERT_EQ(board.isInsideFieldDirection(&c[63], Board::LOWER_RIGHT), true);
}

TEST_F(Board_test, isSelectableCell)
{
    Board board;
    Cell c[64];

    for (int i = 0; i < 64; ++i) {
        c[i].setStoneColor(NONE);
        board.m_cells << &c[i];
    }
    c[27].setStoneColor(WHITE);
    c[28].setStoneColor(BLACK);
    c[35].setStoneColor(BLACK);
    c[36].setStoneColor(WHITE);

    ASSERT_EQ(board.isSelectableCell(&c[18], BLACK), false);
    ASSERT_EQ(board.isSelectableCell(&c[18], WHITE), false);

    ASSERT_EQ(board.isSelectableCell(&c[19], BLACK), true);
    ASSERT_EQ(board.isSelectableCell(&c[19], WHITE), false);

    ASSERT_EQ(board.isSelectableCell(&c[20], BLACK), false);
    ASSERT_EQ(board.isSelectableCell(&c[20], WHITE), true);

    ASSERT_EQ(board.isSelectableCell(&c[21], BLACK), false);
    ASSERT_EQ(board.isSelectableCell(&c[21], WHITE), false);

    ASSERT_EQ(board.isSelectableCell(&c[26], BLACK), true);
    ASSERT_EQ(board.isSelectableCell(&c[26], WHITE), false);

    ASSERT_EQ(board.isSelectableCell(&c[29], BLACK), false);
    ASSERT_EQ(board.isSelectableCell(&c[29], WHITE), true);

    ASSERT_EQ(board.isSelectableCell(&c[34], BLACK), false);
    ASSERT_EQ(board.isSelectableCell(&c[34], WHITE), true);

    ASSERT_EQ(board.isSelectableCell(&c[37], BLACK), true);
    ASSERT_EQ(board.isSelectableCell(&c[37], WHITE), false);

    ASSERT_EQ(board.isSelectableCell(&c[42], BLACK), false);
    ASSERT_EQ(board.isSelectableCell(&c[42], WHITE), false);

    ASSERT_EQ(board.isSelectableCell(&c[43], BLACK), false);
    ASSERT_EQ(board.isSelectableCell(&c[43], WHITE), true);

    ASSERT_EQ(board.isSelectableCell(&c[44], BLACK), true);
    ASSERT_EQ(board.isSelectableCell(&c[44], WHITE), false);

    ASSERT_EQ(board.isSelectableCell(&c[45], BLACK), false);
    ASSERT_EQ(board.isSelectableCell(&c[45], WHITE), false);
}
