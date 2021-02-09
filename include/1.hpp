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
    len=0;
  }
  void push(T&& value) {
    auto mov = new StackObj(std::move(ref), std::forward<T>(value));
    ref = std::make_unique(mov);
    len++;
  }
  void push(const T& value) {
    auto mov = new StackObj(std::move(ref), std::forward<T>(value));
    ref = std::make_unique(mov);
    len++;
  }
  T pop() {
    if(len>=1) {
      len--;
      auto del = ref;
      std::shared_ptr<auto> ptr(del);
      ref = ref->last;
      return del;
    }
    return nullptr;
  }
  const T& head() const {
    return ref->val;
  }

 private:
  struct StackObj{
    typedef  std::unique_ptr < StackObj> StackObjPtr;
    StackObjPtr last;
    T val;
    explicit StackObj(StackObjPtr ref = nullptr, T val= T()) {
      auto valu = val;
      last = std::move(ref);
    }
  };
  std::unique_ptr<StackObj> ref;
  size_t len;
};

#endif // INCLUDE_HEADER_HPP_
