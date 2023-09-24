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

  // Using the assignment operator
  str2 = str1;          // str2: "Hello, World!"
  str2 = "New string";  // str2: "New string"
  str2 = 'X';           // str2: "X" ('X' will convert to "X")

  // Pushing a character
  str2.push_back('Y');  // str2: "XY"

  // Using the compound assignment
  str2 += str1;               // str2: "XYHello, World!"
  str2 += " Another string";  // str2: "XYHello, World! Another string"
  str2 += '!';                // str2: "XYHello, World! Another string!"

  // Using the addition operator
  str1 = "Hello";
  str2 = "World";
  std::string str3 = str1 + ", " + str2;  // str3: "Hello, World"
  std::string str4 = str1 + " C++";       // str4: "Hello C++"
  std::string str5 = "C++ " + str1;       // str5: "C++ Hello"
  return 0;
}

