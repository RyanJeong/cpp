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

// copy 8-1
#include <iostream>
#include <string>

class Point {
 protected:
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
  bool equals(ColorPoint p);
};

void ColorPoint::showColorPoint() {
  std::cout << color << ": ";
  showPoint();  // Point의 showPoint() 호출
}

bool ColorPoint::equals(ColorPoint p) {
  return (this->x == p.x &&
          this->y == p.y &&
          this->color == p.color);
}

int main() {
  Point p;
  p.set(2, 3);
  p.x = 5;
  p.y = 5;
  p.showPoint();

  ColorPoint cp;
  cp.x = 10;
  cp.y = 10;
  cp.set(3, 4);
  cp.setColor("Red");

  ColorPoint cp2;
  cp2.set(3, 4);
  cp2.setColor("Red");
  std::cout << ((cp.equals(cp2)) ? "true" : "false");

  return 0;
}
