#include "gtest/gtest.h"

using namespace ::testing;

#define private   public
#define protected public

#include "Common.h"

class Common_test : public ::testing::Test
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

TEST_F(Common_test, anotherColor)
{
    Common common;
    //ASSERT_EQ(, Eq());
}

TEST_F(Common_test, =)
{
    Common common;
    //ASSERT_EQ(, Eq());
}

TEST_F(Common_test, *)
{
    Common common;
    //ASSERT_EQ(, Eq());
}


