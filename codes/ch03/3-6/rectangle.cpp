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

class Rectangle {
 public:
  int width, height;
  Rectangle();
  Rectangle(int w, int h);
  explicit Rectangle(int length);
  bool isSquare(void);
};

Rectangle::Rectangle() : Rectangle(1) { }

Rectangle::Rectangle(int w, int h) {
  width = w;
  height = h;
}

Rectangle::Rectangle(int length) { width = height = length; }

bool Rectangle::isSquare(void) { return (width == height) ? true : false; }

int main() {
  Rectangle rect1;
  Rectangle rect2(3, 5);
  Rectangle rect3(3);

  if (rect1.isSquare()) {
    std::cout << "rect1은 정사각형이다." << std::endl;
  }
  if (rect2.isSquare()) {
    std::cout << "rect2는 정사각형이다." << std::endl;
  }
  if (rect3.isSquare()) {
    std::cout << "rect3은 정사각형이다." << std::endl;
  }

  return 0;
}
