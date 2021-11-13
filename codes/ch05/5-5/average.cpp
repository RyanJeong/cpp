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

bool average(int a[], int size, double* avg) {
  if (size <= 0) {
    return false;
  }

  double sum = 0;
  for (int i = 0; i < size; ++i) {
    sum += a[i];
  }
  *avg = sum / static_cast<double>(size);

  return true;
}

int main() {
  int x[] = {
      0, 1, 2, 3, 4, 5 };
  double avg;

  if (average(x, 6, &avg)) {
    std::cout << "평균은 " << avg << std::endl;
  } else {
    std::cout << "매개 변수 오류" << std::endl;
  }

  if (average(x, -2, &avg)) {
    std::cout << "평균은 " << avg << std::endl;
  } else {
    std::cout << "매개 변수 오류 " << std::endl;
  }

  return 0;
}
