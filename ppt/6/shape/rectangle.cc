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

#include "rectangle.hpp"  // [NOLINT]

#include <iostream>
#include <cassert>

Rectangle::Rectangle(double length, double width)
    : length_(length), width_(width) {
  if (!is_valid()) {
    std::cout << "Invalid rectangle!";
    assert(false);
  }
}

void Rectangle::print() const {
  std::cout << "Rectangle of " << length_ << " X " << width_ << std::endl;
}

double Rectangle::get_area() const { return length_ * width_; }

double Rectangle::get_perimeter() const { return 2 * (length_ + width_); }

bool Rectangle::is_valid() const { return length_ > 0.0 && width_ > 0.0; }

