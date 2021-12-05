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

  for (int i = 0; i < v.size(); ++i)
    std::cout << v[i] << ' ';
  std::cout << std::endl;

  v[0] = 10;
  v[1] = v[2];
  v.at(2) = 5;

  /*
  for (int i = 0; i < v.size(); ++i)
    std::cout << v[i] << " ";
    */
  for (int i : v)
    std::cout << i << ' ';
  std::cout << std::endl;

  return 0;
}
