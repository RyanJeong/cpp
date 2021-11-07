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
  static int numOfCircles;
  int radius;
 public:
  explicit Circle(int r = 1);
  ~Circle() { --numOfCircles; }
  double getArea() { return radius * radius * 3.14; }
  static int getNumOfCircles() { return numOfCircles; }
};

Circle::Circle(int r) {
  radius = r;
  ++numOfCircles;
}

int Circle::numOfCircles = 0;

int main() {
  Circle *p = new Circle[10];
  std::cout << "생존하고 있는 원의 개수 = "
            << Circle::getNumOfCircles() << std::endl;

  delete[] p;
  std::cout << "생존하고 있는 원의 개수 = "
            << Circle::getNumOfCircles() << std::endl;

  Circle a;
  std::cout << "생존하고 있는 원의 개수 = "
            << Circle::getNumOfCircles() << std::endl;

  Circle b;
  std::cout << "생존하고 있는 원의 개수 = "
            << Circle::getNumOfCircles() << std::endl;

  return 0;
}
