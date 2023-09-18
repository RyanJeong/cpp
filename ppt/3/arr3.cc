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

int GetSum(const int*, int);  // Prototype

int main() {
  // Array declaration and initialization
  int arr[5] = {10, 11, 12, 13, 14};
  // Function call
  std::cout << "Sum of elements: " << GetSum(arr, 5);
  return 0;
}

int GetSum(const int* p, int size) {
  int sum = 0;
  for (int i = 0; i < size ; i++)
    sum += *(p++);
  return sum;
}
