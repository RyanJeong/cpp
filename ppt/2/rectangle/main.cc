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

#include "rectangle.hpp"  // [NOLINT]

int main() {
  Rectangle rect1(3.0, 4.2), rect2(5.1, 10.2), rect3(rect2);

  std::cout << "Rectangle 1: ";
  rect1.print();
  std::cout << "Area: " << rect1.get_area() << std::endl;
  std::cout << "Perimeter: " << rect1.get_perimeter() << std::endl << std::endl;

  std::cout << "Rectangle 2: ";
  rect2.print();
  std::cout << "Area: " << rect2.get_area() << std::endl;
  std::cout << "Perimeter: " << rect2.get_perimeter() << std::endl << std::endl;

  std::cout << "Rectangle 3: ";
  rect3.print();
  std::cout << "Area: " << rect3.get_area() << std::endl;
  std::cout << "Perimeter: " << rect3.get_perimeter() << std::endl << std::endl;

  return 0;
}

