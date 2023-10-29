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

int quotient(int numer, int denom) {
  if (!denom)
    throw 0;
  return numer / denom;
}

int main() {
  int numer, denom, result;
  for (int i = 0; i < 5; ++i) {
    std::cout << "Enter an integer: ";
    std::cin >> numer;
    std::cout << "Enter another integer: ";
    std::cin >> denom;
    try {
      std::cout << "Result: " << quotient(numer, denom) << std::endl;
    } catch (int e) {
      std::cerr << "Division by zero cannot be performed." << std::endl;
    }
  }
  return 0;
}

