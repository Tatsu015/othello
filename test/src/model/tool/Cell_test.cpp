#include "gtest/gtest.h"

using namespace ::testing;

#define private   public
#define protected public

#include "Cell.h"

class Cell_test : public ::testing::Test
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

TEST_F(Cell_test, Cell)
{
    Cell cell;
    //ASSERT_EQ(, Eq());
}

TEST_F(Cell_test, isFilled)
{
    Cell cell;
    //ASSERT_EQ(, Eq());
}

TEST_F(Cell_test, stoneColor)
{
    Cell cell;
    //ASSERT_EQ(, Eq());
}

TEST_F(Cell_test, setStoneColor)
{
    Cell cell;
    //ASSERT_EQ(, Eq());
}

TEST_F(Cell_test, reverseStone)
{
    Cell cell;
    //ASSERT_EQ(, Eq());
}


