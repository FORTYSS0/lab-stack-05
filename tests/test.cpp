// Copyright 2021 by FORTYSS

#include <gtest/gtest.h>
#include "1.hpp"
#include "2.hpp"

TEST(Example, EmptyTest) {
    EXPECT_TRUE(true);
}
TEST(First, True) {

  EXPECT_FALSE(std::is_copy_constructible<Stack<int>>::value);
  //EXPECT_TRUE(std::is_move_constructible<Stack<int>>::value);
  //EXPECT_TRUE(std::is_move_assignable<Stack<int>>::value);
  //EXPECT_FALSE(std::is_copy_assignable<Stack<int>>::value);
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
