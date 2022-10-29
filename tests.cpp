#include <gtest/gtest.h>
#include "priorityqueue.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <cstdlib>

using namespace std;

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

TEST(priorityqueue, toStringChecks) {
  //random test: int
  map<int, vector<int>> intTest;
  priorityqueue<int> pq;

  for (int i = 0; i < 6; i++) {
    int rand1 = rand() % 6 + 1;
    int rand2 = rand() % 6 + 1;

    pq.enqueue(rand1, rand2);
    intTest[rand2].push_back(rand1);
  }
  stringstream out1;

  for (auto i: intTest) {
    for (auto j: i.second) {
      out1 << i.first << " value: " << j << endl; 
    }
  }

  EXPECT_EQ(true, out1.str() == pq.toString());
  EXPECT_EQ(6, pq.Size());
  pq.clear();
  EXPECT_EQ("", pq.toString());

  //random test: string
  map<int, vector<string>> stringTest;
  priorityqueue<string> pq2;
  string randos[6] = {"hi", "test", "am string", "reee", "abc", "def"};

  for (int i = 0; i < 6; i++) {
    string rand1 = randos[rand() % 6];
    int rand2 = rand() % 6 + 1;

    pq2.enqueue(rand1, rand2);
    stringTest[rand2].push_back(rand1);
  }
  stringstream out2;

  for (auto i: stringTest) {
    for (auto j: i.second) {
      out2 << i.first << " value: " << j << endl; 
    }
  }

  EXPECT_EQ(true, out2.str() == pq2.toString());
  EXPECT_EQ(6, pq2.Size());
  pq2.clear();
  EXPECT_EQ("", pq2.toString());
}


TEST(priorityqueue, clearChecks) {

  //non-dups test: int
  priorityqueue<int> intNoDups;

  intNoDups.enqueue(10, 5);
  intNoDups.enqueue(5, 4);
  intNoDups.enqueue(3, 8);
  intNoDups.enqueue(8, 2);
  intNoDups.enqueue(9, 6);
  intNoDups.enqueue(1, 11);

  EXPECT_EQ(6, intNoDups.Size());

  intNoDups.clear();

  EXPECT_EQ(0, intNoDups.Size());
  EXPECT_EQ("", intNoDups.toString());

  //dups test: int
  priorityqueue<int> intDups;

  intDups.enqueue(10, 4);
  intDups.enqueue(5, 4);
  intDups.enqueue(3, 8);
  intDups.enqueue(8, 8);
  intDups.enqueue(9, 8);
  intDups.enqueue(1, 11);

  EXPECT_EQ(6, intDups.Size());

  intDups.clear();

  EXPECT_EQ(0, intDups.Size());
  EXPECT_EQ("", intDups.toString());

  //non-dups test: char
  priorityqueue<char> charNoDups;

  charNoDups.enqueue('a', 5);
  charNoDups.enqueue('b', 4);
  charNoDups.enqueue('c', 8);
  charNoDups.enqueue('d', 2);
  charNoDups.enqueue('e', 1);
  charNoDups.enqueue('f', 11);

  EXPECT_EQ(6, charNoDups.Size());

  charNoDups.clear();

  EXPECT_EQ(0, charNoDups.Size());
  EXPECT_EQ("", charNoDups.toString());

  //dups test: char
  priorityqueue<char> charDups;

  charDups.enqueue('a', 5);
  charDups.enqueue('b', 4);
  charDups.enqueue('c', 8);
  charDups.enqueue('d', 8);
  charDups.enqueue('e', 8);
  charDups.enqueue('f', 11);

  EXPECT_EQ(6, charDups.Size());

  charDups.clear();

  EXPECT_EQ(0, charDups.Size());
  EXPECT_EQ("", charDups.toString());

  //non-dups test: bool
  priorityqueue<bool> boolNoDups;

  boolNoDups.enqueue(true, 5);
  boolNoDups.enqueue(false, 4);
  boolNoDups.enqueue(false, 8);
  boolNoDups.enqueue(true, 2);
  boolNoDups.enqueue(false, 1);
  boolNoDups.enqueue(true, 11);

  EXPECT_EQ(6, boolNoDups.Size());

  boolNoDups.clear();

  EXPECT_EQ(0, boolNoDups.Size());
  EXPECT_EQ("", boolNoDups.toString());

  //dups test: bool
  priorityqueue<bool> boolDups;

  boolDups.enqueue(true, 5);
  boolDups.enqueue(false, 4);
  boolDups.enqueue(false, 8);
  boolDups.enqueue(true, 8);
  boolDups.enqueue(false, 11);
  boolDups.enqueue(true, 11);

  EXPECT_EQ(6, boolDups.Size());

  boolDups.clear();

  EXPECT_EQ(0, boolDups.Size());
  EXPECT_EQ("", boolDups.toString());

  //non-dups test: double
  priorityqueue<double> doubleNoDups;

  doubleNoDups.enqueue(1.1, 5);
  doubleNoDups.enqueue(2.2, 4);
  doubleNoDups.enqueue(3.3, 8);
  doubleNoDups.enqueue(4.4, 2);
  doubleNoDups.enqueue(5.5, 1);
  doubleNoDups.enqueue(6.6, 11);

  EXPECT_EQ(6, doubleNoDups.Size());

  doubleNoDups.clear();

  EXPECT_EQ(0, doubleNoDups.Size());
  EXPECT_EQ("", doubleNoDups.toString());

  //dups test: double
  priorityqueue<double> doubleDups;

  doubleDups.enqueue(1.1, 5);
  doubleDups.enqueue(2.2, 5);
  doubleDups.enqueue(3.3, 8);
  doubleDups.enqueue(4.4, 8);
  doubleDups.enqueue(5.5, 8);
  doubleDups.enqueue(6.6, 11);

  EXPECT_EQ(6, doubleDups.Size());

  doubleDups.clear();

  EXPECT_EQ(0, doubleDups.Size());
  EXPECT_EQ("", doubleDups.toString());
}

TEST(priorityqueue, equalChecks) {
  //random test: int
  priorityqueue<int> pq;
  priorityqueue<int> pq2;

  for (int i = 0; i < 6; i++) {
    int rand1 = rand() % 6 + 1;
    int rand2 = rand() % 6 + 1;

    pq.enqueue(rand1, rand2);
  }

  pq2.enqueue(10, 5);
  pq2.enqueue(5, 4);
  pq2.enqueue(3, 8);
  pq2.enqueue(8, 2);
  pq2.enqueue(9, 6);
  pq2.enqueue(1, 11);
  pq2.enqueue(1, 11);
  
  pq = pq2;

  EXPECT_EQ(true, pq.toString() == pq2.toString());
  EXPECT_EQ(7, pq.Size());

  //random test: string
  priorityqueue<string> pq3;
  priorityqueue<string> pq4;

  string randos[6] = {"hi", "test", "am string", "reee", "abc", "def"};

  for (int i = 0; i < 6; i++) {
    string rand1 = randos[rand() % 6];
    int rand2 = rand() % 6 + 1;

    pq3.enqueue(rand1, rand2);
  }

  pq4.enqueue("yoink", 5);
  pq4.enqueue("yoink", 4);
  pq4.enqueue("yoink", 8);
  pq4.enqueue("yoink", 2);
  pq4.enqueue("yoink", 6);
  pq4.enqueue("yoink", 11);
  pq4.enqueue("yoink", 11);
  pq4.enqueue("yoink", 11);
  
  pq3 = pq4;

  EXPECT_EQ(true, pq.toString() == pq2.toString());
  EXPECT_EQ(7, pq.Size());
}

TEST(priorityqueue, equalityChecks) {
  //random test: int
  priorityqueue<int> pq;
  priorityqueue<int> pq2;

  for (int i = 0; i < 6; i++) {
    int rand1 = rand() % 6 + 1;
    int rand2 = rand() % 6 + 1;

    pq.enqueue(rand1, rand2);
    //pq2.enqueue(rand1, rand2);
  }

  pq2.enqueue(10, 5);
  pq2.enqueue(5, 4);
  pq2.enqueue(3, 8);
  pq2.enqueue(8, 2);
  pq2.enqueue(9, 6);
  pq2.enqueue(1, 11);
  

  EXPECT_EQ(false, pq.toString() == pq2.toString());
  pq = pq2;
  EXPECT_EQ(true, pq.toString() == pq2.toString());
  EXPECT_EQ(6, pq.Size());

  //random test: string
  priorityqueue<string> pq3;
  priorityqueue<string> pq4;

  string randos[6] = {"hi", "test", "am string", "reee", "abc", "def"};

  for (int i = 0; i < 6; i++) {
    string rand1 = randos[rand() % 6];
    int rand2 = rand() % 6 + 1;

    pq3.enqueue(rand1, rand2);
    //pq4.enqueue(rand1, rand2);
  }

  pq4.enqueue("yoink", 5);
  pq4.enqueue("yoink", 4);
  pq4.enqueue("yoink", 8);
  pq4.enqueue("yoink", 2);
  pq4.enqueue("yoink", 6);
  pq4.enqueue("yoink", 11);
  pq4.enqueue("yoink", 11);

  EXPECT_EQ(false, pq3.toString() == pq4.toString());
  pq3 = pq4;
  EXPECT_EQ(true, pq3.toString() == pq4.toString());
  EXPECT_EQ(6, pq.Size());
}