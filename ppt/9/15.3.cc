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

// Definition of template function
template <typename T>
void exchange(T* op1, T* op2) {
  T temp = *op1;
  *op1 = *op2;
  *op2 = temp;
}

int main() {
  // Swapping two int types
  int i1 = 5;
  int i2 = 70;
  exchange(&i1, &i2);
  std::cout << "After swapping 5 and 70: " << i1 << " " << i2 << std::endl;
  // Swapping two double types
  double d1 = 1.2;
  double d2 = 3.4;
  exchange(&d1, &d2);
  std::cout << "After swapping 1.2 and 3.4: " << d1 << " " << d2 << std::endl;
  return 0;
}

