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

// Copy 7-1
#include <iostream>

// Forward declaration
class Rect;

class RectManager {
 public:
  bool IsEqual(Rect r, Rect s);
  void copy(const Rect& src, Rect* dest);
};

class Rect {
  int width, height;
 public:
  Rect(int width, int height) : width(width), height(height) { }
  friend RectManager;
};

bool RectManager::IsEqual(Rect r, Rect s) {
  return (r.width == s.width) && (r.height == s.height);
}

void RectManager::copy(const Rect& src, Rect* dest) {
  dest->width = src.width;
  dest->height = src.height;
}

int main() {
  Rect a(3, 4), b(4, 5);
  RectManager man;

  man.copy(a, &b);
  std::cout << ((man.IsEqual(a, b)) ? "Equal" : "Not equal") << std::endl;

  return 0;
}

