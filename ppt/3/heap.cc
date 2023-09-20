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
  // Declaration of array size and the pointer in the stack
  int size;
  // Validation of the size to be greater than zero
  do {
    std::cout << "Enter the array size (larger than zero): ";
    std::cin >> size;
  } while (size <= 0);
  // Creation of array in the heap
  int* p_array = new int[size];
  // Inputting the values of array
  for (int i = 0; i < size; ++i) {
    std::cout << "Enter the value for element " << i << ": ";
    std::cin >> *(p_array + i);  // or std::cin >> p_array[i];
  }
  // Outputting the values of the array
  std::cout << "The elements in the array are: " << std::endl;
  for (int i = 0; i < size; ++i)
    std::cout << *(p_array + i) << ' ';  // or std::cout << p_array[i] << ' ';
  // Deleting the array in the heap
  delete[] p_array;
  return 0;
}

