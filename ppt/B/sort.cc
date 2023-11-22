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
#include <algorithm>  // to use std::sort()

int main() {
  int array[] = {27, 22, 11, 94, 83, 14, 30, 19, 46, 33};
  int length = sizeof(array) / sizeof(*array);

  std::cout << "Original array: " << std::endl;
  for (int i = 0; i < length; ++i)
    std::cout << array[i] << " ";
  std::cout << std::endl;

  std::sort(std::begin(array), std::end(array));

  std::cout << "Sorted array: " << std::endl;
  for (int i = 0; i < length; ++i)
    std::cout << array[i] << " ";
  std::cout << std::endl;

  return 0;
}

