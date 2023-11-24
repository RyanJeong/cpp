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

void swap(int* x, int* y) { int temp = *x; *x = *y; *y = temp; }

int partition(int arr[], int beg, int end) {
  int pivot = arr[beg];  // Pivot element (choose first element as pivot)
  int i = beg + 1;
  int j = end;
  while (true) {
    while (i <= j && arr[i] <= pivot) ++i;
    while (i <= j && arr[j] >= pivot) --j;
    if (i > j) break;
    swap(&arr[i++], &arr[j--]);
  }
  // Swap pivot element with the rightmost element less than or equal to pivot
  swap(&arr[beg], &arr[j]);
  return j;  // Return the position of the pivot element
}

void quicksort(int arr[], int beg, int end) {
  if (beg < end) {
    int pivot = partition(arr, beg, end);
    quicksort(arr, beg, pivot - 1);
    quicksort(arr, pivot + 1, end);
  }
}

int main() {
  int array[] = {27, 22, 11, 94, 83, 14, 30, 19, 46, 33};
  int length = sizeof(array) / sizeof(*array);

  std::cout << "Original array: " << std::endl;
  for (int i = 0; i < length; ++i)
    std::cout << array[i] << " ";
  std::cout << std::endl;

  quicksort(array, 0, length - 1);

  std::cout << "Sorted array: " << std::endl;
  for (int i = 0; i < length; ++i)
    std::cout << array[i] << " ";
  std::cout << std::endl;

  return 0;
}

