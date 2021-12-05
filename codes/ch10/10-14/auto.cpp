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
#include <vector>

int square(int x) { return x * x; }

int main() {
  auto c = 'a';
  auto pi = 3.14;
  auto ten = 10;
  auto* p = &ten;
  std::cout << c << ' ' << pi << ' ' << ten << ' ' << *p << std::endl;

  auto ret = square(3);
  std::cout << ret << std::endl;

  std::vector<int> v = { 1, 2, 3, 4, 5 };
  for (const auto& i : v)
    std::cout << i << ' ';
  std::cout << std::endl;

  return 0;
}
