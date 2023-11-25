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
#include <string>

#include "stack.hpp"  // [NOLINT]

int main() {
  Stack<std::string> stack;
  stack.push("Henry");
  stack.push("William");
  stack.push("Tara");
  stack.push("Richard");
  std::cout << "Stack size: " << stack.size() << std::endl;
  while (stack.size() > 0) {
    std::cout << "Node value at the top: " << stack.top() << std::endl;
    stack.pop();
  }
  std::cout<< "Stack size: "<< stack.size();
  return 0;
}
