#include <gtest/gtest.h>
#include "priorityqueue.h"

TEST(priorityqueue, sizeCheck) {
  //non-dups test: int
  priorityqueue<int> pq;

  pq.enqueue(10, 5);
  pq.enqueue(5, 4);
  pq.enqueue(3, 8);
  pq.enqueue(8, 2);
  pq.enqueue(9, 6);
  pq.enqueue(1, 11);
  EXPECT_EQ(6, pq.Size());
}
// TO DO: write lots of tests here.