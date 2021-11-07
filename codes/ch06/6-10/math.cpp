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

class Math {
 public:
  static int abs(int a) { return ((a > 0) ? a : -a); }
  static int max(int a, int b) { return ((a > b) ? a : b); }
  static int min(int a, int b) { return ((a > b) ? b : a); }
};

int main() {
  std::cout << Math::abs(-5) << std::endl;
  std::cout << Math::max(10, 8) << std::endl;
  std::cout << Math::min(-3, -8) << std::endl;

  return 0;
}
