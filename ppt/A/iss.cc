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
  std::string str = "42 3.14 John";
  std::istringstream iss(str);

  int int_value;
  double double_value;
  std::string string_value;
  iss >> int_value >> double_value >> string_value;
  std::cout << "Parsed values: " << int_value
            << ", " << double_value
            << ", " << string_value << std::endl;
  return 0;
}

