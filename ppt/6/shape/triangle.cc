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

#include "triangle.hpp"  // [NOLINT]

#include <iostream>
#include <cassert>
#include <cmath>

Triangle::Triangle(double s1, double s2, double s3)
    : side1_(s1), side2_(s2), side3_(s3) {
  if (!is_valid()) {
    std::cout << "Invalid triangle!";
    assert(false);
  }
}

void Triangle::print() const {
  std::cout << "Triangle of : " << side1_ << " X " << side2_ << " X " << side3_
            << std::endl;
}

double Triangle::get_area() const {
  double s = (side1_ + side2_ + side3_) / 2;
  return (std::sqrt (s * (s - side1_) * (s - side2_) * (s - side3_)));
}

double Triangle::get_perimeter() const { return side1_ + side2_ + side3_; }

bool Triangle::is_valid() const {
  bool fact1 = side1_ + side2_ > side3_;
  bool fact2 = side1_ + side3_ > side2_;
  bool fact3 = side2_ + side3_ > side1_;
  return fact1 && fact2 && fact3;
}
