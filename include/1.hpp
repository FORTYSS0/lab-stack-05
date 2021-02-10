// Copyright 2021 by FORTYSS

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_

#include <memory>

template <typename T>
class Stack
{
 public:
  Stack(const Stack&) = delete;
  Stack& operator = (const Stack&) = delete;
  Stack(): ref(nullptr), len(0) {
  }
  void push(T&& value) {
    auto mov = std::unique_ptr<StackObj>(new StackObj(std::move(ref),
                                                      std::move(value)));
    ref = std::move(mov);
    len++;
  }
  void push(const T& value) {
    auto mov = std::unique_ptr<StackObj>(new StackObj(std::move(ref), (value)));
    ref = std::move(mov);
    len++;
  }
  T pop() {
    if(len>=1) {
      len--;
      auto del = ref->val;
      ref = std::move( ref->last);
      return del;
    }
    return T();
  }
  const T& head() const {
    return ref->val;
  }

  size_t size() const {
    return len;
  }

 private:
  struct StackObj{
    typedef  std::unique_ptr < StackObj> StackObjPtr;
    StackObjPtr last;
    T val;
    explicit StackObj(StackObjPtr ref = nullptr, T valu= T()) {
      val = valu;
      last = std::move(ref);
    }
  };
  std::unique_ptr<StackObj> ref;
  size_t len;
};

#endif // INCLUDE_HEADER_HPP_
