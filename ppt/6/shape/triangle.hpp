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

#include "shape.hpp"  // [NOLINT]

class Triangle : public Shape {
  bool is_valid() const override;
  double side1_;
  double side2_;
  double side3_;

 public:
  Triangle(double side1, double side2, double side3);
  ~Triangle() = default;
  void print() const override;
  double get_area() const override;
  double get_perimeter() const override;
};
