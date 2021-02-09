// Copyright 2021 by FORTYSS

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_

#include <memory>

template <typename T>
class Stack
{
 public:
  Stack(const Stack&) = delete;
  Stack operator = (const Stack&&) = delete;
  Stack() {
    StackObj* now = new StackObj();
    now->last = nullptr;
    now->val = T();
    len++;
  }
  void push(T&& value) {
    auto mov = new StackObj(std::forward<T>(value), std::move(ref));
    ref = std::make_unique(mov);
    len++;
  }
  void push(const T& value) {
    auto mov = new StackObj(std::forward<T>(value), std::move(ref));
    ref = std::make_unique(mov);
    len++;
  }
  void pop(){
    if(len>=1) {
      len--;
      auto del = ref;
      ref = ref->last;
      delete del;
    }
  }
  const T& head() const {
    return ref->val;
  }

 private:
  struct StackObj{
    typedef  std::unique_ptr < StackObj> StackObjPtr;
    StackObjPtr last;
    T val;
    StackObj(T val, StackObjPtr ref) {
      auto valu = val;
      last = std::move(ref);
    }
  };
  std::unique_ptr<StackObj> ref;
  size_t len;
};

#endif // INCLUDE_HEADER_HPP_
