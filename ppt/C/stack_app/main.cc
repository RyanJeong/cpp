/*
    Copyright 2023 Munseong Jeong <munseong.jeong@daejin.ac.kr>

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

#include "stack.hpp"  // [NOLINT]

int main() {
  int decimal;
  do {
    std::cout << "Enter a positive integer: ";
    std::cin >> decimal;
  } while (decimal <= 0);
  std::cout << "The decimal number: " << decimal << std::endl;
  Stack<char> stack;
  for (const char* dec = "0123456789ABCDEF"; decimal; decimal /= 16)
    stack.push(dec[decimal%16]);
  std::cout << "The hexadecimal number: ";
  while (stack.size() > 0) {
    std::cout << stack.top();
    stack.pop();
  }
  return 0;
}

