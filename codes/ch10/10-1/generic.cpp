/*
    Copyright 2021 Munseong Jeong <msjeong@daejin.ac.kr>

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

class Circle {
  int radius;
 public:
  explicit Circle(int radius = 1) { this->radius = radius; }
  int getRadius() { return radius;}
};

template <typename T>
void myswap(T& a, T& b) {
  T tmp;
  tmp = a;
  a = b;
  b = tmp;
}

int main() {
  int a = 4, b = 5;
  myswap(a, b);
  std::cout << "a=" << a << ", " << "b=" << b << std::endl;

  double c = 0.3, d = 12.5;
  myswap(c, d);
  std::cout << "c=" << c << ", " << "d=" << d << std::endl;

  Circle donut(5), pizza(20);
  myswap(donut, pizza);
  std::cout << "donut 반지름=" << donut.getRadius() << ", ";
  std::cout << "pizza 반지름=" << pizza.getRadius()<< std::endl;

  return 0;
}
