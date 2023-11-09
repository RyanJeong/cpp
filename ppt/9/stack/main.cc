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

#include "stack.hpp"

int main() {
  Stack<int> stack(10);
  stack.push(5);
  stack.push(6);
  stack.push(7);
  stack.push(3);
  std::cout << stack.pop() << std::endl;
  std::cout << stack.pop() << std::endl;
  return 0;
}

