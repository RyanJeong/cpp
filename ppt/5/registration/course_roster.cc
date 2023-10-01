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

#include "course_roster.hpp"  // [NOLINT]

#include <iostream>

CourseRoster::CourseRoster() : size_(0) { student_name_ = new std::string[20]; }

CourseRoster::~CourseRoster() { delete[] student_name_; }

void CourseRoster::add_student(const std::string& name) {
  student_name_[size_++] = name;
}

void CourseRoster::print() const {
  std::cout << "List of Students" << std::endl;
  for (int i = 0; i < size_; ++i)
    std::cout << student_name_[i] << std::endl;
  std::cout << std::endl;
}

