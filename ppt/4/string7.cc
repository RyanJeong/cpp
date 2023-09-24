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
  // Since C++11, both std::string's data() and c_str() return the same pointer,
  // with the returned string being null-terminated.

  // Conversion to a character array
  const char* cstr1 = str.data();   // cstr1: 0x7fff7bde7ea0

  // Conversion to a C-string
  const char* cstr2 = str.c_str();  // cstr2: 0x7fff7bde7ea0

  // => The pointer variables cstr1 and cstr2 have the same address

  // Size and capacity related operations
  size_t size = str.size();          // size: 13
  size_t max_size = str.max_size();  // max_size: 9223372036854775807(2^63 - 1)
  str.resize(5);                     // str: "Hello", size: 5
  size_t cap = str.capacity();       // cap: 15
  // Notice that the capacity value is calculated based on SSO
  // (Small String Optimization) and is always guaranteed to be greater than or
  // equal to the size of the string.
  str.reserve(50);  // str.capacity(): 50
  // str.reserve(3);
  // -> the capacity is lower then the str's size; this request will be ignored
  bool is_empty = str.empty();  // is_empty: false

  return 0;
}

