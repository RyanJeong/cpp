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

#pragma once

#include "list.hpp"  // [NOLINT]

template <typename T>
class Queue {
  List<T> list_;

 public:
  void push(const T& data) { list_.insert(list_.size(), data); }

  void pop() { list_.erase(0); }

  T& front() const { return list_.get(0); }

  T& back() const { return list_.get(list_.size() - 1); }

  int size() const { return list_.size(); }
};

