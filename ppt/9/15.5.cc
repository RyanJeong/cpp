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
#include <cstring>

// Definition of a template function
template <typename T>
T smaller(const T& op1, const T& op2) { return op1 < op2 ? op1 : op2; }

// Specialization of template function
template <>
const char* smaller(const char* const& op1, const char* const& op2) {
  return std::strcmp(op1, op2) < 0 ? op1 : op2;
}

int main() {
  std::string str1 = "hello";
  std::string str2 = "hi";
  std::cout << smaller(str1, str2) << std::endl;
  const char* s1 = "bye";
  const char* s2 = "bye bye";
  std::cout << smaller(s1, s2) << std::endl;
  return 0;
}

