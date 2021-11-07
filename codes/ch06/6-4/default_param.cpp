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

void f(char c = ' ', int line = 1) {
// void f(char c, int line) {
  for (int i = 0; i < line; ++i) {
    for (int j = 0; j < 10; j++) {
      std::cout << c;
    }
    std::cout << std::endl;
  }
}

int main() {
  f();
  f('%');
  f('@', 5);

  return 0;
}
