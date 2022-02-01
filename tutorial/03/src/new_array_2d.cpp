/*
    Copyright 2021 Munseong Jeong <msjeong@daejin.ac.kr>

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
  const int sz_row = 5;
  const int sz_col = 6;

  int** arr = new int*[sz_row];
  for (int i = 0; i < sz_row; ++i)
    arr[i] = new int[sz_col];

  int cnt = 0;
  for (int i = 0; i < sz_row; ++i)
    for (int j = 0; j < sz_col; ++j)
      arr[i][j] = cnt++;

  for (int i = 0; i < sz_row; ++i) {
    for (int j = 0; j < sz_col; ++j)
      std::cout << arr[i][j] << ' ';
    std::cout << '\n';
  }

  for (int i = 0; i < sz_row; ++i)
    delete[] arr[i];
  delete[] arr;

  return 0;
}
