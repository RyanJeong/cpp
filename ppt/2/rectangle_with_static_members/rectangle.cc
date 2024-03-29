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

int Rectangle::count_ = 0;

Rectangle::Rectangle(double len, double hgt) : length_(len), height_(hgt) {
  if (length_ <= 0.0 || height_ <= 0.0) {
    std::cout << "No rectangle can be made!" << std::endl;
    assert(false);
  }
  ++count_;
}

Rectangle::Rectangle(const Rectangle& rect)
    : length_(rect.length_), height_(rect.height_) { ++count_; }

Rectangle::~Rectangle() { --count_; }

void Rectangle::print() const {
  std::cout << "A rectangle of " << length_ << " by " << height_ << std::endl;
}

double Rectangle::get_area() const { return length_ * height_; }

double Rectangle::get_perimeter() const { return 2 * (length_ + height_); }

int Rectangle::get_count() { return count_; }

