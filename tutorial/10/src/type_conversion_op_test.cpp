/*
    Copyright 2022 Munseong Jeong <ryan.m.jeong@hotmail.com>

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

class Test {
 private:
  char c_;
  int i_;
  double d_;

 public:
  Test(char c, int i, double d) : c_(c), i_(i), d_(d) { }
  operator char() const;
  operator int() const;
  operator double() const;
};

Test::operator char() const {
  std::cout << "operator char()" << std::endl;
  return c_;
}

Test::operator int() const {
  std::cout << "operator int()" << std::endl;
  return i_;
}

Test::operator double() const {
  std::cout << "operator double()" << std::endl;
  return d_;
}

int main() {
  Test test('x', 16, 3.14);
  char c = test;
  int i = test;
  double d = test;

  std::cout << c << ' ' << i << ' ' << d << std::endl;

  return 0;
}
