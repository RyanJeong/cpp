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
#include <cassert>
#include <string>
#include <cstring>

Student::Student(int id, const std::string& name, double gpa)
    : id_(id), gpa_(gpa) {
  std::strcpy(name_, name.c_str());
  if (id_ < 1 || id_ > 99) {
    std::cerr << "Identity is out of range. Program aborted.";
    assert(false);
  }
  if (gpa_ < 0.0 || gpa_ > 4.0) {
    std::cerr << "The gpa value is out of range. Program aborted.";
    assert(false);
  }
}

int Student::id() const { return id_; }

std::string Student::name() const { return name_; }

double Student::gpa() const { return gpa_; }

