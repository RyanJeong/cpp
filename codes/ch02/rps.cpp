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
  std::cout << "가위 바위 보 게임을 합니다. "
            << "가위, 바위, 보 중에서 입력하세요." << endl;

  char s[10];
  std::cout << "로미오>>";
  std::cin >> s;

  char t[10];
  std::cout << "줄리엣>>";
  std::cin >> t;

  if (strcmp(s, "가위") != 0
    && strcmp(s, "바위") != 0
    && strcmp(s, "보") !=0) {
    std::cout << "로미오의 입력이 틀렸습니다." << std::endl;

    return 0;
  }
  if (strcmp(t, "가위") != 0
    && strcmp(t, "바위") != 0
    && strcmp(t, "보") !=0) {
    std::cout << "줄리엣의 입력이 틀렸습니다." << std::endl;

    return 0;
  }

  if (strcmp(s, "가위") == 0 && strcmp(t, "보") == 0) {
    std::cout << "로미오가 이겼습니다." << std::endl;
  } else if (strcmp(s, "가위") == 0 && strcmp(t, "바위") == 0) {
    std::cout << "줄리엣이 이겼습니다." << std::endl;
  } else if (strcmp(s, "바위") == 0 && strcmp(t, "가위") == 0) {
    std::cout << "로미오가 이겼습니다." << std::endl;
  } else if (strcmp(s, "바위") == 0 && strcmp(t, "보") == 0) {
    std::cout << "줄리엣이 이겼습니다." << std::endl;
  } else if (strcmp(s, "보") == 0 && strcmp(t, "바위") == 0) {
    std::cout << "로미오가 이겼습니다." << std::endl;
  } else if (strcmp(s, "보") == 0 && strcmp(t, "가위") == 0) {
    std::cout << "줄리엣이 이겼습니다." << std::endl;
  } else {
    std::cout << "비겼습니다." << std::endl;
  }

  return 0;
}
