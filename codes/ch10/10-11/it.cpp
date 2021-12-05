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

int main() {
  std::vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);

  std::vector<int>::iterator it;

/*
  for (it = v.begin(); it != v.end(); ++it) {
    int n = *it;
    n *= 2;
    *it = n;
  }

  for (it=v.begin(); it != v.end(); ++it)
    std::cout << *it << ' ';
  std::cout << std::endl;
*/
  for (int& i : v)
    i *= 2;
  for (const int& i : v)
    std::cout << i << ' ';
  std::cout << std::endl;

  return 0;
}
