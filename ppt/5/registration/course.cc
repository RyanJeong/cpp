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

#include "course.hpp"  // [NOLINT]

#include <iostream>

Course::Course(const std::string& nm, int ut) : name_(nm), units_(ut) {
  roster_ = new CourseRoster;
}

std::string Course::get_name() const { return name_; }

void Course::add_student(const std::string& name) {
  roster_->add_student(name);
}

CourseRoster* Course::get_roster() const { return roster_; }

void Course::print() const {
  std::cout << "Course Name: " << name_ << std::endl;
  std::cout << "Number of Units: " << units_ << std::endl;
  roster_->print();
}

