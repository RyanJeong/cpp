/*
    Copyright 2022 Munseong Jeong <msjeong@daejin.ac.kr>

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

class Coord {
 public:
  Coord() = default;
  Coord(int x, int y);
  ~Coord() = default;
  int get_x() const;
  int get_y() const;

 private:
  const int x_, y_;
};

Coord::Coord(int x, int y) : x_{x}, y_{y} {}

int Coord::get_x() const { return x_; }
int Coord::get_y() const { return y_; }

int main() {
  Coord c1{3, 4};
  Coord c2{5, 6};

  std::cout << c1.get_x() << ' ' << c1.get_y() << '\n';
  std::cout << c2.get_x() << ' ' << c2.get_y() << '\n';

  return 0;
}
