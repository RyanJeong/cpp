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

#include "professor.hpp"  // [NOLINT]

#include <iostream>

Professor::Professor(const std::string& nm, double sal)
    : Person(nm), salary_(sal) {}

void Professor::print() const {
  std::cout << "Professor " << std::endl;
  std::cout << "Name: " << name_ << " ";
  std::cout << "Salary: " << salary_ << std::endl << std::endl;
}

