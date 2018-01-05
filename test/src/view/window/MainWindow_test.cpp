#include "gtest/gtest.h"

using namespace ::testing;

#define private   public
#define protected public

#include "MainWindow.h"

class MainWindow_test : public ::testing::Test
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

TEST_F(MainWindow_test, MainWindow)
{
    MainWindow mainWindow;
    //ASSERT_EQ(, Eq());
}


