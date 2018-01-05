#include "gtest/gtest.h"

using namespace ::testing;

#define private   public
#define protected public

#include "Turn.h"

class Turn_test : public ::testing::Test
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

TEST_F(Turn_test, Turn)
{
    Turn turn;
    //ASSERT_EQ(, Eq());
}

TEST_F(Turn_test, change)
{
    Turn turn;
    //ASSERT_EQ(, Eq());
}

TEST_F(Turn_test, now)
{
    Turn turn;
    //ASSERT_EQ(, Eq());
}


