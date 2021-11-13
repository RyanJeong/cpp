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
  Circle() : radius(1) { }
  explicit Circle(int r) : radius(r) { }
  void setRadius(int r);
  double getArea();
};

inline void Circle::setRadius(int r) { radius = r; }

inline double Circle::getArea() { return radius * radius * 3.14; }

int main() {
  Circle circleArray[3];

  circleArray[0].setRadius(10);
  circleArray[1].setRadius(20);
  circleArray[2].setRadius(30);

  for (int i = 0; i < 3; ++i) {
    std::cout << "Circle " << i << "의 면적은 "
              << circleArray[i].getArea() << std::endl;
  }

  Circle *p;
  p = circleArray;
  for (int i = 0; i < 3; ++i) {
    std::cout << "Circle " << i << "의 면적은 "
              << p->getArea() << std::endl;
    ++p;
  }

  return 0;
}
