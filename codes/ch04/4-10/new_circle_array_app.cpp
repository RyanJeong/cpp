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
  std::cout << "생성하고자 하는 원의 개수?";
  int n;
  std::cin >> n;
  if (n <= 0) {
    return 0;
  }

  Circle* pArray = new Circle[n];
  for (int i = 0; i < n; ++i) {
    std::cout << "원" << i + 1 << ">>";
    int radius;
    std::cin >> radius;
    pArray[i].setRadius(radius);
  }

  int count = 0;
  Circle* p = pArray;
  for (int i = 0; i < n; ++i) {
    std::cout << p->getArea() << ((n - 1 == i) ? "" : ", ");
    if (p->getArea() >= 100 && p->getArea() <= 200) {
      ++count;
    }
    ++p;
  }

  std::cout << std::endl
            << "면적이 100에서 200 사이인 원의 개수는 "
            << count << std::endl;
  delete[] pArray;

  return 0;
}
