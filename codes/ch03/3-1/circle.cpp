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
 public:
  int radius;
  double getArea(void);
};

double Circle::getArea(void) { return 3.14 * radius * radius; }

int main() {
  Circle donut;
  donut.radius = 1;
  double area = donut.getArea();
  std::cout << "donut 면적은 " << area << std::endl;

  Circle pizza;
  pizza.radius = 30;
  area = pizza.getArea();
  std::cout << "pizza 면적은 " << area << std::endl;

  return 0;
}
