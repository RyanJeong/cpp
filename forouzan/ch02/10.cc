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
 * 이스케이프 문자를 사용하는 프로그램                       *
 *************************************************************/
#include <iostream>

using std::cout;
using std::endl;

int main() {
  cout << "Hello\n";
  cout << "Hi\t friends." << endl;
  cout << "Buenos dias  \bamigos." << endl;  // 중간에 2칸 띄어쓰기
  cout << "Hello\rBonjour mes amis." << endl;
  cout << "This is a single quote\'." << endl;
  cout << "This is a double quote\"." << endl;
  cout << "This is how to print a backslash \\.";

  return 0;
}
