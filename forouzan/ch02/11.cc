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
 * 불 변수와 값을 사용하는 프로그램                          *
 *************************************************************/
#include <iostream>

using std::cout;
using std::endl;

int main() {
  // 변수 선언
  bool x = 123;
  bool y = -8;
  bool z = 0;
  bool t = -0;
  bool u = true;
  bool v = false;

  // 값 출력
  cout << "x의 값: " << x << endl;
  cout << "y의 값: " << y << endl;
  cout << "z의 값: " << z << endl;
  cout << "t의 값: " << t << endl;
  cout << "u의 값: " << u << endl;
  cout << "v의 값: " << v << endl;

  return 0;
}
