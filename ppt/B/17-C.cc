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
#include <cmath>

bool prime(int div, int num) {
  if (!(num % div)) return false;
  return div >= std::floor(std::sqrt(num)) ? true : prime(div + 1, num);
}

bool prime(int num) {
  return num <= 1 ? false : num == 2 ? true : prime(2, num);
}

int main() {
  std::cout << std::boolalpha;
  std::cout << "Is 1 prime? " << prime(1) << std::endl;
  std::cout << "Is 2 prime? " << prime(2) << std::endl;
  std::cout << "Is 7 prime? " << prime(7) << std::endl;
  std::cout << "Is 21 prime? " << prime(21) << std::endl;
  std::cout << "Is 59 prime? " << prime(59) << std::endl;
  std::cout << "Is 97 prime? " << prime(97) << std::endl;
  std::cout << "Is 301 prime? " << prime(301) << std::endl;
  return 0;
}

