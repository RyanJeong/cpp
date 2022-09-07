/*
    Copyright 2022 Munseong Jeong <ryan.m.jeong@hotmail.com>
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

/**************************************************************
 * 이름, 이니셜, 성을 입력받고                               *
 * 결합해서 출력하는 프로그램                                 *
 **************************************************************/
#include <iostream>
#include <string>       // string 클래스를 사용하려면 읽어 들여야 함

using std::cin;
using std::cout;

using std::string;

int main() {
  // 변수 선언
  const string space = " ";
  const string dot = ".";

  // 이름, 이니셜, 성 입력받기
  cout << "이름(first name) 입력하기: ";
  string first;
  cin >> first;

  cout << "이니셜(initial) 입력하기: ";
  string initial;
  cin >> initial;

  cout << "성(last name) 입력하기: ";
  string last;
  cin >> last;

  // 결합 연산자를 사용해서 문자열 연결
  string fullName = first + space + initial + dot + space + last;

  // 전체 이름 출력
  cout << "전체 이름(full name): " << fullName;

  return 0;
}
