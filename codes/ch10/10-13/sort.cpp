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

int main() {
  std::vector<int> v;
  // v.reserve(5);
  std::cout << "5개의 정수를 입력하세요>> ";
  for (int i = 0; i < 5; ++i) {
    int n;
    std::cin >> n;
    v.push_back(n);

    /*
    std::cout << "v's size: " << v.size() << ' ' 
              << "v's capacity: " << v.capacity() << std::endl;
    */
  }
  sort(v.begin(), v.end());

  std::vector<int>::iterator it;
  for (it = v.begin(); it != v.end(); ++it)
    std::cout << *it <<' ';
  std::cout << std::endl;

  /*
  sort(v.begin(), v.end(), std::greater<int>());
  for (const auto& i : v)
    std::cout << i << ' ';
  std::cout << std::endl;
  */

  return 0;
}
