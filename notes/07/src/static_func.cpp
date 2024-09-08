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
  Coord();
  Coord(int x, int y);
  ~Coord();
  static void print_total_num();
 private:
  const int x_, y_;
  static int total_num;
};

int Coord::total_num = 0;  // Explicit init.

Coord::Coord() : x_{0}, y_{0} { ++total_num; }
Coord::Coord(int x, int y) : x_{x}, y_{y} { ++total_num; }
Coord::~Coord() { --total_num; }

void Coord::print_total_num() {
  std::cout << total_num << '\n';
}

void foo();
void bar();

int main() {
  Coord c1{3, 4};
  Coord::print_total_num();
  foo();
  Coord::print_total_num();

  return 0;
}

void foo() {
  Coord c2{5, 6};
  Coord::print_total_num();
  bar();
  Coord::print_total_num();
}

void bar() {
  Coord c3{7, 8};
  Coord::print_total_num();
}
