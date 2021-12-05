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
#include <algorithm>

void print(int n) {
  std::cout << n << ' ';
}

int main() {
  std::vector<int> v = { 1, 2, 3, 4, 5 };

  for_each(v.begin(), v.end(), print);
  for_each(v.begin(), v.end(), [](int n) { std::cout << n << ' ' ; });

  return 0;
}
