#include "gtest/gtest.h"

using namespace ::testing;

#define private   public
#define protected public

#include "Game.h"

class Game_test : public ::testing::Test
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

TEST_F(Game_test, getInstance)
{
    Game game;
    //ASSERT_EQ(, Eq());
}

TEST_F(Game_test, start)
{
    Game game;
    //ASSERT_EQ(, Eq());
}

TEST_F(Game_test, end)
{
    Game game;
    //ASSERT_EQ(, Eq());
}

TEST_F(Game_test, turn)
{
    Game game;
    //ASSERT_EQ(, Eq());
}

TEST_F(Game_test, Game)
{
    Game game;
    //ASSERT_EQ(, Eq());
}


