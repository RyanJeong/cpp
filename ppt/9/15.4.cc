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

// Definition of the print template function
template <typename T, int n>
void print (T (&array)[n]) {
  for (int i = 0; i < n; ++i)
    std::cout << array[i] << " ";
  std::cout << std::endl;
}

int main() {
  // Creation of two arrays
  int arr1[4] = {7, 3, 5, 1};
  double arr2[3] = {7.5, 6.1, 4.6};
  // Calling template function
  print(arr1);
  print(arr2);
  return 0;
}

