#include "gtest/gtest.h"

using namespace ::testing;

#define private   public
#define protected public

#include "StoneItem.h"

class StoneItem_test : public ::testing::Test
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

TEST_F(StoneItem_test, StoneItem)
{
    StoneItem stoneItem;
    //ASSERT_EQ(, Eq());
}

TEST_F(StoneItem_test, color)
{
    StoneItem stoneItem;
    //ASSERT_EQ(, Eq());
}

TEST_F(StoneItem_test, setColor)
{
    StoneItem stoneItem;
    //ASSERT_EQ(, Eq());
}


