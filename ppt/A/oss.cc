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
#include <sstream>

int main() {
  std::ostringstream oss;

  int int_value = 42;
  double double_value = 3.14;
  std::string string_value = "John";
  oss << "Value 1: " << int_value
      << ", Value 2: " << double_value
      << ", Name: " << string_value;

  std::string result = oss.str();
  std::cout << "Generated string: " << result << std::endl;

  return 0;
}

