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
  // 빈 문자열을 가진 스트링 객체 생성
  std::string str;

  // 생성자
  std::string address("경기도 포천시 호국로 1007");

  // address의 문자열을 복사한 스트링 객체 생성
  std::string copyAddress(address);

  // C-스트링
  char text[] = {
      'L', 'o', 'v', 'e', ' ', 'C', '+', '+', '\0'};
  // "Love C++" 문자열을 가진 스트링 객체 생성
  std::string title(text);

  // 스트링 출력
  std::cout << str << std::endl;
  std::cout << address << std::endl;
  std::cout << copyAddress << std::endl;
  std::cout << title << std::endl;

  return 0;
}
