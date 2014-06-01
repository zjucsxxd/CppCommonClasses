#include "Queue.C"
#include <gtest/gtest.h>
 
class QueueTest : public ::testing::Test
{
protected:
  virtual void SetUp()
  {
    q1_.add(1);
    q2_.add(2);
    q2_.add(3);
  }

  // virtual void TearDown() { } // not needed post-destructor

  Queue<int> q0_;
  Queue<int> q1_;
  Queue<int> q2_;
};



TEST_F(QueueTest, IsEmptyInitially)
{
  ASSERT_TRUE(q0_.isEmpty());
}
 
// *Note that removing an element from empty queue causes program to exit
// * => Must carefully check that queue isn't empty before removing an element
TEST_F(QueueTest, removeWorks)
{
  int n;

  // one element in q1_
  ASSERT_FALSE(q1_.isEmpty());
  n = q1_.remove();
  EXPECT_EQ(1, n);
  EXPECT_TRUE(q1_.isEmpty());

  // two elements in q2_
  ASSERT_FALSE(q2_.isEmpty());
  n = q2_.remove();
  EXPECT_EQ(2, n);
  EXPECT_FALSE(q2_.isEmpty());



  // empty queue q0_
  n = q0_.remove(); // will cause program to exit

}

 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
