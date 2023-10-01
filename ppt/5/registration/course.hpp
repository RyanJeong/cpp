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

#pragma once

#include <string>

#include "course_roster.hpp"  // [NOLINT]

class Course {
  std::string name_;
  int units_;
  CourseRoster* roster_;

 public:
  Course(const std::string& name, int units);
  ~Course() = default;
  std::string get_name() const;
  CourseRoster* get_roster() const;
  void add_student(const std::string& name);
  void print() const;
};

