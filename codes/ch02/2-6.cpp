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

int main() {
  std::cout << "주소를 입력하세요>>";
  char address[100];
  std::cin.getline(address, 100, '\n');

  // 컴퓨터시 프로그램구 c++동 스트링 1-1
  std::cout << "주소는 " << address << "입니다\n";

  return 0;
}
