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

// copy 5-6
#include <iostream>

class Circle {
 private:
  int radius;
 public:
  Circle();
  explicit Circle(int r);
  ~Circle();
  double getArea() { return radius * radius * 3.14; }
  int getRadius() { return radius; }
  void setRadius(int radius) { this->radius = radius; }
};

inline Circle::Circle() : Circle(1) { }

inline Circle::Circle(int radius) {
  this->radius = radius;
  std::cout << "생성자 실행 radius = " << radius << std::endl;
}

inline Circle::~Circle() {
  std::cout << "소멸자 실행, radius = " << radius << std::endl;
}

/* not recommended
void readRadius(Circle& c) {
  int r;
  std::cout << "정수 값으로 반지름을 입력하세요>>";
  std::cin>>r;
  c.setRadius(r);
}
*/

void readRadius(Circle* c) {
  int r;
  std::cout << "정수 값으로 반지름을 입력하세요>>";
  std::cin >> r;
  c->setRadius(r);
}

int main() {
  Circle donut;
  readRadius(&donut);
  std::cout << "donut의 면적 = " << donut.getArea() << std::endl;

  return 0;
}
