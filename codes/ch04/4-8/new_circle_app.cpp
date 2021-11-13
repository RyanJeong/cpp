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
  while (true) {
    std::cout << "정수 반지름 입력(음수이면 종료)>> ";
    int radius;
    std::cin >> radius;
    if (radius < 0) {
      break;
    }

    Circle* p = new Circle(radius);
    std::cout << "원의 면적은 "
              << p->getArea() << std::endl;

    delete p;
  }

  return 0;
}
