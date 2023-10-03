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

#include <iostream>

#include "square.hpp"  // [NOLINT]
#include "rectangle.hpp"  // [NOLINT]
#include "triangle.hpp"  // [NOLINT]
#include "circle.hpp"  // [NOLINT]
#include "ellipse.hpp"  // [NOLINT]

int main() {
  Square square(5);
  square.print();
  std::cout << "area: " << square.get_area() << std::endl;
  std::cout << "Perimeter: " << square.get_perimeter() << std::endl;
  std::cout << std::endl;

  Rectangle rectangle(5, 4);
  rectangle.print();
  std::cout << "area: " << rectangle.get_area() << std::endl;
  std::cout << "Perimeter: " << rectangle.get_perimeter() << std::endl;
  std::cout << std::endl;
  std::cout << "Information about a triangle" << std::endl;

  Triangle triangle(3, 4, 5);
  triangle.print();
  std::cout << "area: " << triangle.get_area() << std::endl;
  std::cout << "Perimeter: " << triangle.get_perimeter() << std::endl;
  std::cout << std::endl;
  std::cout << "Information about a circle" << std::endl;

  Circle circle(5);
  circle.print();
  std::cout << "area: " << circle.get_area() << std::endl;
  std::cout << "Perimeter: " << circle.get_perimeter() << std::endl;
  std::cout << std::endl;
  std::cout << "Information about an ellipse" << std::endl;

  Ellipse ellipse(5, 4);
  ellipse.print();
  std::cout << "area: " << ellipse.get_area() << std::endl;;
  std::cout << "Perimeter: " << ellipse.get_perimeter()<< std::endl;
  return 0;
}

