#include "gtest/gtest.h"

using namespace ::testing;

#define private   public
#define protected public

#include "CellItem.h"

class CellItem_test : public ::testing::Test
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

TEST_F(CellItem_test, CellItem)
{
    CellItem cellItem;
    //ASSERT_EQ(, Eq());
}

TEST_F(CellItem_test, setStoneItem)
{
    CellItem cellItem;
    //ASSERT_EQ(, Eq());
}

TEST_F(CellItem_test, updateView)
{
    CellItem cellItem;
    //ASSERT_EQ(, Eq());
}

TEST_F(CellItem_test, existStone)
{
    CellItem cellItem;
    //ASSERT_EQ(, Eq());
}

TEST_F(CellItem_test, *cell)
{
    CellItem cellItem;
    //ASSERT_EQ(, Eq());
}

TEST_F(CellItem_test, setCell)
{
    CellItem cellItem;
    //ASSERT_EQ(, Eq());
}


