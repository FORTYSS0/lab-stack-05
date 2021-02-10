// Copyright 2021 by FORTYSS

#ifndef TEMPLATE_2_HPP
#define TEMPLATE_2_HPP

template <typename T>
class StackTwo
{
 public:

  StackTwo(const StackTwo&) = delete;
  StackTwo& operator = (const StackTwo&&) = delete;
  StackTwo() {
    StackObj* now = new StackObj(nullptr);
    len = 0;
  }
  template <typename ... Args>
    void push_emplace(Args&&... value) {
      auto vall = T (std::forward<Args>(value)...);
      auto mov = new StackObj(std::move(ref), std::move(vall));
      ref = std::move(std::make_unique(mov));
      len++;
    }
  void push(T&& value) {
    auto mov = new StackObj(std::move(ref), std::forward<T>(value));
    ref = std::make_unique(mov);
    len++;
  }
  const T& head() const {
      return ref->val;
  }
  T pop() {
    if(len>=1) {
      len--;
      auto del = ref;
      std::shared_ptr<T> ptr(del);
      ref = ref->last;
      return del;
    }
    return nullptr;
  }
 private:
  struct StackObj{
    typedef  std::unique_ptr < StackObj> StackObjPtr;
    StackObjPtr last;
    T val;
    explicit StackObj(StackObjPtr ref = nullptr, T valu= T()) {
      val=std::forward(valu);
      last = std::move(ref);
    }
  };
  std::unique_ptr<StackObj> ref;
  size_t len;
};

#endif  // TEMPLATE_2_HPP
