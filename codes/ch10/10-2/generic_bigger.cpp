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
T bigger(T a, T b) { return ((a > b) ? a : b); }

int main() {
  int a = 20, b = 50;
  std::cout << "bigger(20, 50)의 결과는 " << bigger(a, b) << std::endl;
  char c = 'a', d = 'z';
  std::cout << "bigger('a', 'z')의 결과는 " << bigger(c, d) << std::endl;

  return 0;
}
