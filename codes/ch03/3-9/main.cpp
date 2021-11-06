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

class Private_access_error {
 private:
  int a;
  void f(void);
  Private_access_error();
 public:
  int b;
  explicit Private_access_error(int x);
  void g(void);
};

Private_access_error::Private_access_error() : a(1), b(1) { }

Private_access_error::Private_access_error(int x) : a(x), b(x) { }

void Private_access_error::f(void) {
  a = 5;
  b = 5;
}

void Private_access_error::g(void) {
  a = 6;
  b = 6;
}

int main() {
  Private_access_error objA;       // (1)
  Private_access_error objB(100);  // (2)
  objB.a = 10;  // (3)
  objB.b = 20;  // (4)
  objB.f();  // (5)
  objB.g();  // (6)

  return 0;
}
