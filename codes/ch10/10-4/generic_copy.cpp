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

template <typename T1, typename T2>
void mcopy(T1 src[], T2 dest[], int n) {
  for (int i = 0; i < n; ++i) {
    dest[i] = (T2) src[i];
  }
}

int main() {
  int src1[] = { 1, 2, 3, 4, 5 };
  double dst1[5];
  char src2[] = { 'H', 'e', 'l', 'l', 'o' };
  char dst2[5];

  mcopy(src1, dst1, 5);
  mcopy(src2, dst2, 5);

  for (int i = 0; i < 5; ++i) {
    std::cout << dst1[i] << ' ';
  }
  std::cout << std::endl;
  for (int i = 0; i < 5; ++i) {
    std::cout << dst2[i] << ' ';
  }

  return 0;
}
