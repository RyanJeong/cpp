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

/*************************************************************
 * char 자료형의 변수를 선언하고 초기화하는 프로그램         *
 *************************************************************/
#include <iostream>

using std::cout;
using std::endl;

int main() {
  // char 자료형의 변수를 선언하고 초기화
  char first = 'A';
  char second = 65;
  char third = 'B';
  char fourth = 66;

  // 값 출력
  cout << "first의 값: " << first << endl;
  cout << "second의 값: " << second << endl;
  cout << "third의 값: " << third << endl;
  cout << "fourth의 값: " << fourth;

  return 0;
}
