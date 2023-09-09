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

#include <iostream>

class Circle {
 private:
  double radius_;
  double kPi = 3.141592;

 public:
  explicit Circle(double radius);
  Circle();
  Circle(const Circle& circle);
  ~Circle();

  double get_radius() const;
  double get_area() const;
  double get_perimeter() const;
  void set_radius(double radius);
};

