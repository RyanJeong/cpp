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
#include <string>
#include <vector>

int main() {
  std::vector<std::string> sv;
  std::string name;

  std::cout << "이름을 5개 입력하라" << std::endl;
  for (int i = 0; i < 5; ++i) {
    std::cout << i+1 << ">>";
    getline(std::cin, name);
    sv.push_back(name);
  }

  name = sv.at(0);
  for (int i = 1; i < sv.size(); ++i) {
    if (name < sv[i])
      name = sv[i];
  }
  std::cout << "사전에서 가장 뒤에 나오는 이름은 " << name << std::endl;

  return 0;
}
