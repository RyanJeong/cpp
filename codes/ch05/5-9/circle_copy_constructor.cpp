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
 private:
  int radius;
 public:
  Circle();
  explicit Circle(int r);
  explicit Circle(const Circle& c);
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

inline Circle::Circle(const Circle& c) {
  this->radius = c.radius;
  std::cout << "복사 생성자 실행 radius = " << radius << std::endl;
}

inline Circle::~Circle() {
  std::cout << "소멸자 실행, radius = " << radius << std::endl;
}

int main() {
  // src 객체의  보통 생성자 호출
  Circle src(30);

  // dest 객체의 복사 생성자 호출
  Circle dest(src);

  std::cout << "원본의 면적 = " << src.getArea() << std::endl;
  std::cout << "사본의 면적 = " << dest.getArea() << std::endl;

  return 0;
}
