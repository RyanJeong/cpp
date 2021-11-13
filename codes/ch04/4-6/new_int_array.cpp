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
  std::cout << "입력할 정수의 개수는?";
  int n;
  std::cin >> n;

  if (n <= 0) {
    return 0;
  }

  int *p = new int[n];
  if (!p) {
    std::cout << "메모리를 할당할 수 없습니다.";

    return 0;
  }

  for (int i = 0; i < n; ++i) {
    std::cout << i + 1 << "번째 정수: ";
    std::cin >> p[i];
  }

  int sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += p[i];
  }
  std::cout << "평균 = " << sum/n << std::endl;
  delete []p;

  return 0;
}
