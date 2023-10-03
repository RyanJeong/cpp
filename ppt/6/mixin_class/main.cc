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
#include "professor.hpp"  // [NOLINT]
#include "ta.hpp"  // [NOLINT]

int main() {
  std::cout << "Information about person" << std::endl;
  Person per("John");
  per.print();
  std::cout << std::endl;

  std::cout << "Information about student" << std::endl;
  Student std("Linda", 3.9);
  std.print();
  std::cout << std::endl;

  std::cout << "Information about professor" << std::endl;
  Professor prf("George", 89000);
  prf.print();
  std::cout << std::endl;

  std::cout << "Information about teaching assistance " << std::endl;
  TA ta("Lucien", 3.8, 23000);
  ta.print();
  std::cout << std::endl;

  return 0;
}

