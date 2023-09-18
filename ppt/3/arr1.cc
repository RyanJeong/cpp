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
  // Declaration of an array of five int
  int arr[5];
  // Printing the addresses through pointers and the & operator
  for (int i = 0; i < 5; ++i) {
    std::cout << "Address of cell " << i << " Using pointer: ";
    std::cout << arr + i << std::endl;
    std::cout << "Address of cell " << i << " Using & operator: ";
    std::cout << &arr[i] << std::endl << std::endl;
  }
  return 0;
}
