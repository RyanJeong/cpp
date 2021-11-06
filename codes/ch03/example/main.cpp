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

class A {
 public:
  int x, y;
  A();
};
A::A() {
  x = 1;
  y = 2;
  std::cout << "A.x: " << x << ", A.y: " << y << std::endl;
}

class B {
 public:
  int x, y;
  B();
};

B::B() : x(3), y(4) {
  std::cout << "B.x: " << x << ", B.y: " << y << std::endl;
}

class C {
 public:
  const int x, y;
  C();
};

C::C() : x(5), y(6) {
  std::cout << "C.x: " << x << ", C.y: " << y << std::endl;
}

int main() {
  A a;
  B b;
  C c;

  return 0;
}
