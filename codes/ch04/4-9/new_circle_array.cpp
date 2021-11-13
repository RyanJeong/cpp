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

// copy 4-7
#include <iostream>

class Circle {
  int radius;
 public:
  Circle();
  explicit Circle(int r);
  ~Circle();
  void setRadius(int r);
  double getArea();
};

inline Circle::Circle() {
  radius = 1;
  std::cout << "생성자 실행, radius = " << radius << std::endl;
}

inline Circle::Circle(int r) {
  radius = r;
  std::cout << "생성자 실행, radius = " << radius << std::endl;
}

inline Circle::~Circle() {
  std::cout << "소멸자 실행, radius = " << radius << std::endl;
}

inline void Circle::setRadius(int r) { radius = r; }

inline double Circle::getArea() { return radius * radius * 3.14; }

int main() {
  Circle* pArray = new Circle[3];

  pArray[0].setRadius(10);
  pArray[1].setRadius(20);
  pArray[2].setRadius(30);

  std::cout << "인덱스:" << std::endl;
  for (int i = 0; i < 3; ++i) {
    std::cout << pArray[i].getArea() << std::endl;
  }

  Circle* p = pArray;
  std::cout << "포인터:" << std::endl;
  for (int i = 0; i < 3; ++i) {
    std::cout << p->getArea() << std::endl;
    ++p;
  }
  delete[] pArray;

  return 0;
}
