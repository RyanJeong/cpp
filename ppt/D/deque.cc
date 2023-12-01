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
#include <deque>

int main() {
  std::deque<int> deq;  // Declare an empty deque of integers
  // Adding elements to the front and back of the deque
  deq.push_back(42);    // Add 42 to the back of the deque
  deq.push_front(99);   // Add 99 to the front of the deque
  // Access the first and last elements of the deque
  std::cout << "First element of deq: " << deq.front() << std::endl;
  std::cout << "Last element of deq: " << deq.back() << std::endl;
  // Remove elements from the front and back of the deque
  deq.pop_back();      // Remove the last element
  deq.pop_front();     // Remove the first element
  // Iterate through the deque
  for (int i : deq) std::cout << i << " ";
  std::cout << std::endl;
  return 0;
}

