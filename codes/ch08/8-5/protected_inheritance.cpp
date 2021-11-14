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

// copy 8-4
#include <iostream>

class Base {
  int a;
 protected:
  void setA(int a) { this->a = a; }
 public:
  void showA() { std::cout << a; }
};

class Derived : protected Base {
  int b;
 protected:
  void setB(int b) { this->b = b; }
 public:
  void showB() { std::cout << b; }
};

int main() {
  Derived x;
  x.a = 5;
  x.setA(10);
  x.showA();
  x.b = 10;
  x.setB(10);
  x.showB();

  return 0;
}
