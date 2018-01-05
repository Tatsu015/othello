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

TEST_F(Board_test, Board)
{
    Board board;
    //ASSERT_EQ(, Eq());
}

TEST_F(Board_test, add)
{
    Board board;
    //ASSERT_EQ(, Eq());
}

TEST_F(Board_test, canPlaceStoneSomeware)
{
    Board board;
    //ASSERT_EQ(, Eq());
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

    board.add(&c0);
    board.add(&c1);
    board.add(&c2);
    board.add(&c3);

    board.reverseStone(WHITE, &c2, Board::UPPER);
    ASSERT_EQ(board.cell(0)->stoneColor(), WHITE);
    ASSERT_EQ(board.cell(1)->stoneColor(), WHITE);
    ASSERT_EQ(board.cell(2)->stoneColor(), WHITE);
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

TEST_F(Board_test, isInvalid)
{
    Board board;
    //ASSERT_EQ(, Eq());
}


