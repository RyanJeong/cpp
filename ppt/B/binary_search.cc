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
#include <algorithm>  // to use std::binary_search()

int main() {
  int arr[] = {11, 14, 19, 22, 27, 30, 33, 46, 63, 94};
  const int size = sizeof(arr) / sizeof(*arr);
  int value;
  std::cout << "Enter the value to be found: ";
  std::cin >> value;
  bool result = std::binary_search(arr, arr + size, value);
  std::cout << "The value is " << (!result ? "not " : "") << "in the array";
  return 0;
}

