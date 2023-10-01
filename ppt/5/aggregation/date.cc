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

#include "date.hpp"  // [NOLINT]

#include <iostream>
#include <cassert>

Date::Date(int m, int d, int y) : month_(m), day_(d), year_(y) {
  if (month_ < 1 || month_ > 12) {
    std::cerr << "Month is out of range!";
    assert(false);
  }

  static int day_in_month[13] = {0,  // 1-based
      31, 28, 31, 30, 31, 30,
      31, 31, 30, 31, 30, 31};
  if (day_ < 1 || day_ > day_in_month[month_]) {
    std::cout << "Day out of range!";
    assert(false);
  }

  if (year_ < 1900 || year_ > 2099) {
    std::cout << "Year out of range!";
    assert(false);
  }
}

void Date::print() const {
  std::cout << month_ << "/" << day_ << "/" << year_ << std::endl;
}

