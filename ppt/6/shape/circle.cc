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

#include "circle.hpp"  // [NOLINT]

#include <iostream>
#include <cassert>

Circle::Circle(double r) : radius_(r) {
  if (!is_valid()) {
    std::cout << "Invalid circle!";
    assert(false);
  }
}

void Circle::print() const {
  std::cout << "Circle of radius : " << radius_ << std::endl;
}

double Circle::get_area() const { return 3.14 * radius_ * radius_; }

double Circle::get_perimeter() const { return 2 * 3.14 * radius_; }

bool Circle::is_valid() const { return radius_ > 0.0; }

