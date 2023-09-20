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

int first = 20;           // Global variable in static memory
static int second = 30;   // Static variable created in static memory

int main() {
  static int third = 50;  // Static variable in static memory

  std::cout << "Value of global variable: " << first << std::endl;
  std::cout << "Value of global static variable: " << second << std::endl;
  std::cout << "Value of local static variable: " << third;
  return 0;
}

