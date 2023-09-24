/*
    Copyright 2023 Munseong Jeong <munseong.jeong@daejin.ac.kr>

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
  std::string str("Hello, World!");

  // Finding
  size_t pos1 = str.find('W');   // Found, pos1: 7
  size_t pos2 = str.rfind('l');  // Found, pos2: 10

  // Finding the position of a character
  size_t pos3 = str.find_first_of("aeiou");  // 'e' found at idx 1, pos3: 1
  size_t pos4 = str.find_last_of("aeiou");   // 'o' found at idx 8, pos4: 8

  // Finding the position of a character not in a set
  size_t pos5 = str.find_first_not_of("aeiou");  // Not found, pos5: 0
  size_t pos6 = str.find_last_not_of("aeiou");   // Not found, pos6: 12
  return 0;
}

