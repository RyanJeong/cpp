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

class Box {
  int width, height;
  char fill;
 public:
  Box(int w, int h);
  void setFill(char f) { fill = f; }
  void setSize(int w, int h);
  void draw(void);
};

Box::Box(int w, int h) {
  setSize(w, h);
  fill = '*';
}

void Box::setSize(int w, int h) {
  width = w;
  height = h;
}

void Box::draw(void) {
  for (int n = 0; n < height; ++n) {
    for (int m = 0; m < width; ++m) {
      std::cout << fill;
    }
    std::cout << std::endl;
  }
}

int main() {
  Box b(10, 2);
  b.draw();

  b.setSize(7, 4);
  b.setFill('^');
  b.draw();

  return 0;
}
