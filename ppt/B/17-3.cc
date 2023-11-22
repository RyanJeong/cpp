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

int64_t fib(int n) {
  return !n || n == 1 ? n : fib(n - 2) + fib(n - 1);
}

int main() {
  std::cout << "Fibonacci numbers from 0 to 10" << std::endl;
  for (int i = 0; i <= 10; ++i)
    std::cout << "\tfib (" << i << ") = " << fib(i) << std::endl;
  std::cout << "Fibonacci numbers of 35 and 36" << std::endl;
  std::cout << "\tfib(35) = " << fib(35) << std::endl;
  std::cout << "\tfib(36) = " << fib(36) << std::endl;
  return 0;
}

