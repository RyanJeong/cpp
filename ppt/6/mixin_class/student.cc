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

#include "student.hpp"  // [NOLINT]

#include <iostream>
#include <iomanip>

Student::Student(const std::string& name, double gp) : Person(name) {
  gpa_ = gp;
}

void Student::print_gpa() const {
  std::cout << "GPA: " << std::fixed << std::setprecision(2) << gpa_
            << std::endl;
}

void Student::print() {
  Person::print();
  print_gpa();
}

