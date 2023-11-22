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

int binarysearch(const int arr[], int low, int high, int value) {
  int mid = (low + high) / 2;
  if (low > high) return -1;
  if (value < arr[mid])
    return binarysearch(arr, low, mid - 1, value);
  else if (value > arr[mid])
    return binarysearch(arr, mid + 1, high, value);
  else
    return mid;
}

int binarysearch(const int arr[], int size, int value) {
  int low = 0;
  int high = size - 1;
  return binarysearch(arr, low, high, value);
}

int main() {
  int arr[] = {11, 14, 19, 22, 27, 30, 33, 46, 63, 94};
  const int size = sizeof(arr) / sizeof(*arr);
  int value;
  std::cout << "Enter the value to be found: ";
  std::cin >> value;
  int result = binarysearch(arr, size, value);
  if (result == -1)
    std::cout << "The value is not in the array!";
  else
    std::cout << "The value was found at index: " << result;
  return 0;
}

