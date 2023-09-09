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

Circle::Circle(double rds) : radius_(rds) {
  std::cout << "The parameter constructor was called." << std::endl;
}

Circle::Circle() : radius_(0.0) {
  std::cout << "The default constructor was called." << std::endl;
}

Circle::Circle(const Circle& circle) : radius_(circle.radius_) {
  std::cout << "The copy constructor was called." << std::endl;
}

Circle::~Circle() {
  std::cout << "The destructor was called for circle with radius " << radius_
            << std::endl;
}

double Circle::get_radius() const {
  return radius_;
}

double Circle::get_area() const {
  return kPi * radius_ * radius_;
}

double Circle::get_perimeter() const {
  return 2 * kPi * radius_;
}

void Circle::set_radius(double r) {
  radius_ = r;
}

