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

void swap_ptr(int*, int*);
void swap_ref(int&, int&);

int main() {
  int a = 3;
  int b = 4;
  int x = 3;
  int y = 4;

  // swap via pointer
  std::cout << "Before: " << '\n'
            << "a: " << a << ", b: " << b << '\n'
            << "[main]address of variable 'a': " << &a << '\n'
            << "[main]address of variable 'b': " << &b << '\n';
  swap_ptr(&a, &b);
  std::cout << "After : " << '\n'
            << "a: " << a << ", b: " << b << '\n';

  // swap via reference
  std::cout << "Before: " << '\n'
            << "x: " << x << ", y: " << y << '\n'
            << "[main]address of variable 'x': " << &x << '\n'
            << "[main]address of variable 'y': " << &y << '\n';
  swap_ref(x, y);
  std::cout << "After : " << '\n'
            << "x: " << x << ", y: " << y << '\n';

  return 0;
}

void swap_ptr(int* a, int* b) {
  int tmp;

  tmp = *a;
  *a = *b;
  *b = tmp;
  std::cout << "[swap]address of variable 'a': " << &a << '\n'
            << "[swap]address of variable 'b': " << &b << '\n';
}

void swap_ref(int& x, int& y) {
  int tmp;

  tmp = x;
  x = y;
  y = tmp;
  std::cout << "[swap]address of variable 'x': " << &x << '\n'
            << "[swap]address of variable 'y': " << &y << '\n';
}
