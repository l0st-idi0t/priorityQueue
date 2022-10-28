#include <gtest/gtest.h>
#include "priorityqueue.h"

TEST(priorityqueue, sizeCheck) {
  //non-dups test: int
  priorityqueue<int> intNoDups;

  intNoDups.enqueue(10, 5);
  intNoDups.enqueue(5, 4);
  intNoDups.enqueue(3, 8);
  intNoDups.enqueue(8, 2);
  intNoDups.enqueue(9, 6);
  intNoDups.enqueue(1, 11);

  EXPECT_EQ(6, intNoDups.Size());

  //dups test: int
  priorityqueue<int> intDups;

  intDups.enqueue(10, 4);
  intDups.enqueue(5, 4);
  intDups.enqueue(3, 8);
  intDups.enqueue(8, 8);
  intDups.enqueue(9, 8);
  intDups.enqueue(1, 11);

  EXPECT_EQ(6, intDups.Size());

  //non-dups test: char
  priorityqueue<char> charNoDups;

  charNoDups.enqueue('a', 5);
  charNoDups.enqueue('b', 4);
  charNoDups.enqueue('c', 8);
  charNoDups.enqueue('d', 2);
  charNoDups.enqueue('e', 1);
  charNoDups.enqueue('f', 11);

  EXPECT_EQ(6, charNoDups.Size());

  //dups test: char
  priorityqueue<char> charDups;

  charDups.enqueue('a', 5);
  charDups.enqueue('b', 4);
  charDups.enqueue('c', 8);
  charDups.enqueue('d', 8);
  charDups.enqueue('e', 8);
  charDups.enqueue('f', 11);

  EXPECT_EQ(6, charDups.Size());

  //non-dups test: bool
  priorityqueue<bool> boolNoDups;

  boolNoDups.enqueue(true, 5);
  boolNoDups.enqueue(false, 4);
  boolNoDups.enqueue(false, 8);
  boolNoDups.enqueue(true, 2);
  boolNoDups.enqueue(false, 1);
  boolNoDups.enqueue(true, 11);

  EXPECT_EQ(6, boolNoDups.Size());

  //dups test: bool
  priorityqueue<bool> boolDups;

  boolDups.enqueue(true, 5);
  boolDups.enqueue(false, 4);
  boolDups.enqueue(false, 8);
  boolDups.enqueue(true, 8);
  boolDups.enqueue(false, 11);
  boolDups.enqueue(true, 11);

  EXPECT_EQ(6, boolDups.Size());

  //non-dups test: double
  priorityqueue<double> doubleNoDups;

  doubleNoDups.enqueue(1.1, 5);
  doubleNoDups.enqueue(2.2, 4);
  doubleNoDups.enqueue(3.3, 8);
  doubleNoDups.enqueue(4.4, 2);
  doubleNoDups.enqueue(5.5, 1);
  doubleNoDups.enqueue(6.6, 11);

  EXPECT_EQ(6, doubleNoDups.Size());

  //dups test: double
  priorityqueue<double> doubleDups;

  doubleDups.enqueue(1.1, 5);
  doubleDups.enqueue(2.2, 5);
  doubleDups.enqueue(3.3, 8);
  doubleDups.enqueue(4.4, 8);
  doubleDups.enqueue(5.5, 8);
  doubleDups.enqueue(6.6, 11);

  EXPECT_EQ(6, doubleDups.Size());
}
// TO DO: write lots of tests here.