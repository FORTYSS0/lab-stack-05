// Copyright 2021 by FORTYSS

#ifndef TEMPLATE_2_HPP
#define TEMPLATE_2_HPP

template <typename T>
class StackTwo
{
 public:

  StackTwo(const StackTwo&) = delete;
  StackTwo& operator = (const StackTwo&) = delete;
  StackTwo(): ref(nullptr) {}
  template <typename ... Args>
    void push_emplace(Args&&... value) {
      auto mov = new StackObj(std::move(ref), T (std::forward<Args>(value)...));
      ref = std::move(std::make_unique<StackObj>(mov));;
    }
  void push(T&& value) {
    auto mov = new StackObj(std::move(ref), std::forward<T>(value));
    ref = std::move(std::make_unique(mov));
  }
  const T& head() const {
      return ref->val;
  }
  T pop() {
    if (ref!= nullptr) {
      auto del = ref->val;
      ref = std::move(ref->last);
      return del;
    }
    throw std::runtime_error("Stack is empty");
  }
 private:
  struct StackObj{
    typedef  std::unique_ptr <StackObj> StackObjPtr;
    StackObjPtr last;
    T val;
    explicit StackObj(StackObjPtr ref = nullptr, T&& valu= T()) {
      val=std::forward<T>(valu);
      last = std::move(ref);
    }
  };
  std::unique_ptr<StackObj> ref;
};

#endif  // TEMPLATE_2_HPP
