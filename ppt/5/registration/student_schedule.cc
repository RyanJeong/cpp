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

#include "student_schedule.hpp"  // [NOLINT]

#include <iostream>

StudentSchedule::StudentSchedule() :size_(0) {
  course_name_ = new std::string[5];
}

StudentSchedule::~StudentSchedule() { delete[] course_name_; }

void StudentSchedule::add_course(const std::string& name) {
  course_name_[size_++] = name;
}

void StudentSchedule::print() const {
  std::cout << "List of Courses" << std::endl;
  for (int i = 0; i < size_; ++i)
    std::cout << course_name_[i] << std::endl;
  std::cout << std::endl;
}

