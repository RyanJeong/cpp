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
 * 변수를 초기화할 때 리터럴을 사용하는 프로그램            *
 *************************************************************/
#include <iostream>

using std::cout;
using std::endl;

int main() {
  // 변수 선언과 초기화
  int x = -1245;
  cout << x << endl;

  unsigned int y = 1245;
  cout << y << endl;

  unsigned int z = -2367;
  cout << z << endl;

  unsigned int t = 14.56;
  cout << t;

  return 0;
}
