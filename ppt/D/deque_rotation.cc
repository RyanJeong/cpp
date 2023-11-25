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

#include <deque>
#include <string>
#include <iostream>

void print(const std::deque<std::string>& deq) {
  for (const auto& i : deq) std::cout << i << " ";
  std::cout << std::endl;
}

int main() {
  std::deque<std::string> deq{"John", "Mary", "Rich", "Mark", "Tara"};
  print(deq);
  // Rotate the deque clockwise one element
  deq.push_back(deq.front());
  deq.pop_front();
  print(deq);
  // Rotate the deque counter-clockwise one element
  deq.push_front(deq.back());
  deq.pop_back();
  print(deq);
  return 0;
}

