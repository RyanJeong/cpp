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

#include "student.hpp"  // [NOLINT]

int main() {
  Person* ptr[4];
  ptr[0] = new Student("Joe", 3.7);
  ptr[1] = new Student("John", 3.9);
  ptr[2] = new Person("Bruce");
  ptr[3] = new Person("Sue");
  for (int i = 0; i < 4; ++i) {
    ptr[i]->print();
    std::cout << std::endl;
  }
  for (int i = 0; i < 4; ++i)
    delete ptr[i];
  return 0;
}

