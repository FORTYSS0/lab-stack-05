// Copyright 2021 by FORTYSS

#include <gtest/gtest.h>
#include "1.hpp"
#include "2.hpp"

TEST(Example, EmptyTest) {
    EXPECT_TRUE(true);
}
TEST(First, True) {
  Stack<int> MySteck;
  int t=2;
  MySteck.push(1);
  MySteck.push(t);
  EXPECT_EQ(MySteck.head(), 2);
  EXPECT_EQ(MySteck.pop(), 2);
  EXPECT_EQ(MySteck.head(), 1);
  EXPECT_EQ(MySteck.pop(), 1);
  EXPECT_EQ(MySteck.size(), 0);
  std::string err = "Stack is empty";
  try {
    size_t k = MySteck.pop();
  }
  catch (std::runtime_error& error) {
    EXPECT_EQ(error.what(), err);
  }
  EXPECT_FALSE(std::is_copy_constructible<Stack<int>>::value);
  EXPECT_FALSE(std::is_copy_assignable<Stack<int>>::value);
}
TEST(First, False) {

  EXPECT_TRUE(true);
}

TEST(Second, True) {

  EXPECT_TRUE(true);
}

TEST(Second, False) {

  EXPECT_TRUE(true);
}
