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

#include <stack>
#include <string>
#include <iostream>

int main() {
  std::string expr;
  std::cout << "Enter an expression: ";
  std::getline(std::cin, expr);
  std::stack<char> stack;
  bool paired = true;
  for (const auto& c : expr) {
    if (c == '(') {
      stack.push(c);
    } else if (c == ')') {
      if (stack.empty()) {
        paired = false;
        break;
      }
      stack.pop();
    }
  }
  std::cout << "Parentheses are "
            << (!stack.empty() || !paired ? "not " : "")
            << "paired!" << std::endl;
  return 0;
}

