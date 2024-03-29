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

#include "employee.hpp"  // [NOLINT]

#include <iostream>
#include <cassert>

Employee::Employee(const std::string& fst,
                   const std::string& i,
                   const std::string& lst,
                   double sal) : name_(fst, i, lst), salary_(sal) {
  assert(salary_ > 0.0 && salary_ < 100000.0);
}

void Employee::print() const {
  name_.print();
  std::cout << "Salary: " << salary_ << std::endl << std::endl;
}

