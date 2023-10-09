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

#include "array.hpp"  // [NOLINT]

#include <iostream>
#include <cassert>

Array::Array(int s) : size_(s) { ptr_ = new double[size_]; }

Array::~Array() { delete[] ptr_; }

double& Array::operator[](int index) const {
  if (index < 0 || index >= size_) {
    std::cerr << "Index is out of range. Program terminates.";
    assert(false);
  }
  return ptr_[index];
}

double& Array::operator[](int index) {
  if (index < 0 || index >= size_) {
    std::cerr << "Index is out of range. Program terminates.";
    assert(false);
  }
  return ptr_[index];
}

