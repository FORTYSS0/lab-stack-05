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
    MySteck.pop();
  }
  catch (std::runtime_error& error) {
    EXPECT_EQ(error.what(), err);
  }
  EXPECT_FALSE(std::is_copy_constructible<Stack<int>>::value);
  EXPECT_FALSE(std::is_copy_assignable<Stack<int>>::value);
}
class Myclass {
 public:
  Myclass(){
    t0 = 0;
    t1 = 0.1;
    t2 = "0";
  }
  Myclass(int a, double b, std::string c){
    t0 = a;
    t1 = b;
    t2 = c;
  }
  int t0;
  double t1;
  std::string t2;
};
TEST(Second, True) {
  StackTwo<Myclass> MySteck;
  int t0 = 2;
  double t1 = 2.2;
  std::string t2 = "2";
  //MySteck.push(Myclass());
  MySteck.push_emplace(1, 1.1, "1");
  MySteck.push_emplace(t0, t1, t2);
  EXPECT_EQ(MySteck.head(), 2);
  EXPECT_EQ(MySteck.pop(), 2);
  EXPECT_EQ(MySteck.head(), 1);
  EXPECT_EQ(MySteck.pop(), 1);
  EXPECT_EQ(MySteck.size(), 0);
  std::string err = "Stack is empty";
  try {
    MySteck.pop();
  }
  catch (std::runtime_error& error) {
    EXPECT_EQ(error.what(), err);
  }
  EXPECT_FALSE(std::is_copy_constructible<Stack<int>>::value);
  EXPECT_FALSE(std::is_copy_assignable<Stack<int>>::value);
}
