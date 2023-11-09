/*
    Copyright 2023 Munseong Jeong <munseong.jeong@daejin.ac.kr>

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at
    http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include <iostream>
#include <cassert>

template <typename T>
class Stack {
  T* ptr_;
  int cap_;
  int size_;

 public:
  explicit Stack(int cap) : cap_(cap), size_(0) { ptr_ = new T[cap]; }
  ~Stack() { delete[] ptr_; }

  void push(const T& elem) {
    if (size_ >= cap_) {
      std::cerr << "Can't push; the stack is full." << std::endl;
      assert(false);
    }
    ptr_[size_++] = elem;
  }

  T pop() {
    if (size_ <= 0) {
      std::cerr << "Can't pop; the stack is empty." << std::endl;
      assert(false);
    }
    return ptr_[--size_];
  }
};

