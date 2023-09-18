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

int main() {
  // Declaration and initialization of an array
  int numbers[5] = {10, 11, 12, 13, 14};
  // Accessing elements through the indexes
  std::cout << "Accessing elements through indexes" << std::endl;
  for (int i = 0; i < 5; ++i)
    std::cout << numbers[i] << " ";
  std::cout << std::endl;
  // Accessing elements through the pointers
  std::cout << "Accessing elements through pointers" << std::endl;
  for (int i = 0; i < 5; ++i)
    std::cout << *(numbers + i) << " ";
  return 0;
}
