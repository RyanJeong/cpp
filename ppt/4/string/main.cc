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

#include "mystring.hpp"  // [NOLINT]

int main() {
  MyString str1("Hello C++ strings!");
  str1.println();

  // The following statement is equivalent to the next statement.
  // (automatically converted by the compiler)
  MyString str2 = str1;  // '=' symbol is invoking the copy constructor of the
                         // MyString and the compiler will treat this sentence
                         // as MyString str2(str1);
  str2.println();
  MyString str3 = "implicit conversion example";
  str3.println();
  MyString str4(10);  // MyString str4 = 10; is forbidden
  str4.insert(0, "Hello, World!").insert(0, "C++! ");
  str4.println();
  std::cout << str4.length() << ' ' << str4.capacity();
  return 0;
}

