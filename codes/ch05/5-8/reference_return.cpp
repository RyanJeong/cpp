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

// 배열 s의 index 원소 공간에 대한 참조 리턴하는 함수
char& find(char s[], int index) { return s[index]; }

int main() {
  char name[] = "Mike";
  std::cout << name << std::endl;

  // name[0]='S'로 변경
  find(name, 0) = 'S';
  std::cout << name << std::endl;

  // name = "Site"
  char& ref = find(name, 2);
  ref = 't';
  std::cout << name << std::endl;

  return 0;
}
