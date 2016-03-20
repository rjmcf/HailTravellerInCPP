#include "gtest/gtest.h"
#include "add.h"

class MyTest : public ::testing::Test 
{
  protected:

  /* Initialise test suite - no-op. */
  virtual void SetUp() 
  {
    // No-op.
  }

  /* Clean up test suite - no-op. */
  virtual void TearDown() {
    // No-op.
  }
};

TEST_F(MyTest, mytest1)
{
  ASSERT_EQ(add(2,3), 5);
}