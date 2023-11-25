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

#include "queue.hpp"  // [NOLINT]

int main() {
  Queue<std::string> queue;
  queue.push("Henry");
  queue.push("William");
  queue.push("Tara");
  queue.push("Richard");
  std::cout << "Checking front and back elements";
  std::cout << "after four push operations:" << std::endl;
  std::cout << "Element at the front: " << queue.front() << std::endl;
  std::cout << "Element at the back: " << queue.back() << std::endl
            << std::endl;
  queue.pop();
  queue.pop();
  std::cout << "Checking front and back elements";
  std::cout << "after two pop operations:" << std::endl;
  std::cout << "Element at the front: " << queue.front() << std::endl;
  std::cout << "Element at the back: " << queue.back() << std::endl;
  return 0;
}

