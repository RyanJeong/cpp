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

template <typename T>
void print(T array[], int n) {
  for (int i = 0; i < n; ++i) {
    std::cout << array[i] << '\t';
  }
  std::cout << std::endl;
}

void print(char array[], int n) {
  for (int i = 0; i < n; ++i) {
    std::cout << static_cast<int>(array[i]) << '\t';
  }
  std::cout << std::endl;
}

int main() {
  int x[] = { 1, 2, 3, 4, 5 };
  double d[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
  print(x, 5);
  print(d, 5);

  char c[5] = { 1, 2, 3, 4, 5 };
  print(c, 5);

  return 0;
}
