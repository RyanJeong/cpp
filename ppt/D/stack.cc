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
#include <stack>

int main() {
  std::stack<int> stack;
  stack.push(1);
  stack.push(2);
  stack.push(3);

  if (!stack.empty()) {
    std::cout << "Stack size: " << stack.size() << std::endl;
    std::cout << "Top element: " << stack.top() << std::endl;
    stack.pop();
    std::cout << "Popped one element." << std::endl;
    std::cout << "Top element after pop: " << stack.top() << std::endl;
  }
  return 0;
}

