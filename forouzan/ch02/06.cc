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
 * 3가지 정수 자료형의 크기를 확인하는 프로그램              *
 *************************************************************/
#include <iostream>

using std::cout;
using std::endl;

int main() {
  cout << "short int의 크기는 " << sizeof(short int) << "바이트입니다." << endl;  // NOLINT
  cout << "int의 크기는 " << sizeof(int) << "바이트입니다." << endl;
  cout << "long int의 크기는 " << sizeof(long int) << "바이트입니다." << endl;  // NOLINT
  cout << "int64_t의 크기는 " << sizeof(int64_t) << "바이트입니다." << endl;

  return 0;
}
