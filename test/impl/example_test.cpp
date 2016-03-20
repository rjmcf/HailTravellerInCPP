#include "gtest/gtest.h"

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
  int result = 1;
  ASSERT_EQ(1, result);
}