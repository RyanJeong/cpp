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

#include "square.hpp"  // [NOLINT]

#include <iostream>
#include <cassert>

Square::Square(double s) : side_(s) {
  if (!is_valid()) {
    std::cout << "Invalid square!";
    assert(false);
  }
}

void Square::print() const {
  std::cout << "Square of size " << side_ << std::endl;
}

double Square::get_area() const { return side_ * side_; }

double Square::get_perimeter() const { return 4 * side_; }

bool Square::is_valid() const { return side_ > 0.0; }

