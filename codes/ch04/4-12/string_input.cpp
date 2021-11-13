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

int main() {
  std::string names[5];

  for (int i = 0; i < 5; ++i) {
    std::cout << "이름 >> ";
    getline(std::cin, names[i], '\n');
  }

  /*
  in name.txt:

  Park Seo-jun 
  Seo Ji-an 
  Wi Ha-joon 
  Jeong Ha-yoon 
  Lee Do-yun

  will return: 
  Wi Ha-joon
  */
  std::string latter = names[0];
  for (int i = 1; i < 5; ++i) {
    if (latter < names[i]) {
      latter = names[i];
    }
  }
  std::cout << "사전에서 가장 뒤에 나오는 문자열은 "
            << latter << std::endl;

  return 0;
}
