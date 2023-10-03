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

#include "ellipse.hpp"  // [NOLINT]

#include <iostream>
#include <cassert>
#include <cmath>

Ellipse::Ellipse(double r1, double r2) : radius1_(r1), radius2_(r2) {
  if (!is_valid()) {
    std::cout << "Invalid ellipse!";
    assert(false);
  }
}

void Ellipse::print() const {
  std::cout << "Ellipse of radii : " << radius1_ << " X " << radius2_
            << std::endl;
}

double Ellipse::get_area() const { return 3.14 * radius1_ * radius2_; }

double Ellipse::get_perimeter() const {
  double temp = (radius1_ * radius1_ + radius2_ * radius2_) / 2.0;
  return 2 * 3.14 * std::sqrt(temp);
}

bool Ellipse::is_valid() const { return radius1_ > 0.0 && radius2_ > 0.0; }

