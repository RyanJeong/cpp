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

class Point {
  int x, y;
 public:
  Point();
  Point(int a, int b);
  void show(void) { std::cout << "(" << x << ", " << y << ")" << std::endl; }
};

Point::Point() : Point(0, 0) { }

Point::Point(int a, int b) : x(a), y(b) { }

int main() {
  Point origin;
  Point target(10, 20);
  origin.show();
  target.show();

  return 0;
}
