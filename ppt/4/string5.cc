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
  std::string str1("Hello, World!");
  std::string str2("Hello");

  // Comparing two strings
  // return value:
  //    0 They compare equal
  //   <0 Either the value of the first character that does not match is lower
  //      in the compared string, or all compared characters match but the
  //      compared string is shorter.
  //   >0 Either the value of the first character that does not match is greater
  //      in the compared string, or all compared characters match but the
  //      compared string is longer.
  int cmp = str1.compare(0, 5, str2);  // cmp: 0 (equal)

  // Logical comparison
  bool is_equal = str1 == str2;   // not equal, is_equal: false
  bool is_less = str1 < str2;     // not less, is_less: false
  bool is_greater = str1 > str2;  // greater, is_greater : true

  // Modifying
  str1.append(" How are you?");  // str1: "Hello, World! How are you?"
  str1.insert(0, "Hey! ");       // str1: "Hey! Hello, World! How are you?"
  str1.replace(0, 3, "Hi");      // str1: "Hi! Hello, World! How are you?"
  str2.assign(str1, 4, 5);       // str2: "Hello"

  // Clearing and erasing
  str1.erase(4, 14);  // str1: "Hi! How are you?"
  str1.clear();       // str1: ""

  return 0;
}

