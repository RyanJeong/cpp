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

#include <iomanip>
#include <cmath>

Course::Course(int num, const char* ifn) : n_stds_(num), in_file_name_(ifn) {
  in_file_.open(in_file_name_);
  student_ = new Student[n_stds_];
  get_input();
  set_grade();
  set_average();
  set_deviation();
  print();
}

Course::~Course() {
  delete[] student_;
  in_file_.close();
}

void Course::get_input() {
  for (int i = 0; i < n_stds_; ++i) {
    in_file_ >> student_[i].id;
    in_file_ >> student_[i].score;
  }
}

void Course::set_grade() {
  char grade[] = {'F', 'F', 'F', 'F', 'F', 'F', 'D', 'C', 'B', 'A', 'A'};
  for (int i = 0; i < n_stds_; ++i) {
    int index = student_[i].score / 10;
    student_[i].grade = grade[index];
  }
}

void Course::set_average() {
  int sum = 0;
  for (int i = 0; i < n_stds_; ++i)
    sum += student_[i].score;
  average_ = static_cast<double>(sum) / n_stds_;
}

void Course::set_deviation() {
  deviation_ = 0.0;
  for (int i = 0; i < n_stds_; ++i) {
    student_[i].deviation = student_[i].score - average_;
    deviation_ += std::pow(student_[i].deviation, 2);
  }
  deviation_ = std::sqrt(deviation_) / n_stds_;
}

void Course::print() const {
  std::cout << std::endl;
  std::cout << "Identity Score Grade Deviation" << std::endl;
  std::cout << "-------- ----- ----- ---------" << std::endl;
  std::cout << std::right << std::fixed;
  for (int i = 0; i < n_stds_ ; ++i) {
    std::cout << std::setw(4)
              << student_[i].id;
    std::cout << std::setw(14)
              << student_[i].score;
    std::cout << std::setw(10)
              << student_[i].grade;
    std::cout << std::setprecision(2)
              << std::setw(20)
              << std::showpoint
              << std::showpos
              << student_[i].deviation << std::endl;
    std::cout << std::noshowpoint << std::noshowpos;
  }
  std::cout << "Average score: " << std::setw(4) << std::setprecision(2);
  std::cout  << average_ << std::endl;
  std::cout << "Standard Deviation: " << std::setw(4) << std::setprecision(2);
  std::cout << deviation_;
}

