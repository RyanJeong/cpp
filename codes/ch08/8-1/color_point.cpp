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
#include <string>

class Point {
  int x, y;
 public:
  void set(int x, int y) { this->x = x; this->y = y; }
  void showPoint() {
    std::cout << "(" << x << ", " << y << ")" << std::endl;
  }
};

class ColorPoint : public Point {
  std::string color;
 public:
  void setColor(std::string color) { this->color = color; }
  void showColorPoint();
};

void ColorPoint::showColorPoint() {
  std::cout << color << ": ";
  showPoint();  // Point의 showPoint() 호출
}

int main() {
  ColorPoint cp;
  cp.set(3, 4);         // 기본 클래스의 멤버 호출
  cp.setColor("Red");   // 파생 클래스의 멤버 호출
  cp.showColorPoint();  // 파생 클래스의 멤버 호출

  return 0;
}
