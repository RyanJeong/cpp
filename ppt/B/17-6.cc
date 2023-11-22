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

int sum(int n, int result) { return !n ? result : sum(n - 1, n + result); }
int sum(int n) { return sum(n, 0); }

int main() {
  int arr[] = {3, 7, 9};
  for (int i = 0; i < sizeof(arr) / sizeof(*arr); ++i)
    std::cout << "sum(" << arr[i] << ") = " << sum(arr[i]) << std::endl;
  return 0;
}

