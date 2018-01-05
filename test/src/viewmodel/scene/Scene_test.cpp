#include "gtest/gtest.h"

using namespace ::testing;

#define private   public
#define protected public

#include "Scene.h"

class Scene_test : public ::testing::Test
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

TEST_F(Scene_test, Scene)
{
    Scene scene;
    //ASSERT_EQ(, Eq());
}

TEST_F(Scene_test, addCellItem)
{
    Scene scene;
    //ASSERT_EQ(, Eq());
}

TEST_F(Scene_test, setBoard)
{
    Scene scene;
    //ASSERT_EQ(, Eq());
}

TEST_F(Scene_test, mousePressEvent)
{
    Scene scene;
    //ASSERT_EQ(, Eq());
}

TEST_F(Scene_test, updateView)
{
    Scene scene;
    //ASSERT_EQ(, Eq());
}


