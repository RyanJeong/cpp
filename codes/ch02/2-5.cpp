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
#include <cstring>

int main() {
  std::cout << "프로그램을 종료하려면 암호를 입력하세요." << std::endl;
  while (true) {
    std::cout << "암호>>";
    char password[11];
    std::cin >> password;

    if (strcmp(password, "C++") == 0) {
      std::cout << "프로그램을 정상 종료합니다." << std::endl;
      break;
    }
    std::cout << "암호가 틀립니다." << std::endl;
  }

  return 0;
}
