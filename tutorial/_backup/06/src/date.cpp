/*
    Copyright 2021 Munseong Jeong <msjeong@daejin.ac.kr>

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

#include <iostream>

class Date {
 public:
  Date();
  Date(int y, int m, int d);
  void set_date(int y, int m, int d);
  void add_day(int num);
  void add_month(int num);
  void add_year(int num);
  void show_date();
 private:
  bool is_leap_year();
  int year_;
  int month_;
  int day_;
};

Date::Date() : year_{2021}, month_{9}, day_{2} {}
Date::Date(int y, int m, int d) : year_{y}, month_{m}, day_{d} {}

void Date::set_date(int y, int m, int d) {
  if (y < 0 || m < 0 || d < 0) {
    year_ = 0;
    month_ = 0;
    day_ = 0;
  } else {
    year_ = y;
    month_ = m;
    day_ = d;
  }
}

void Date::add_day(int num) {
  const char daytab_[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
  };
  while (true) {
    int leap = is_leap_year();
    int month_day = daytab_[leap][month_];
    if (day_ + num <= month_day) {
      day_ += num;
      break;
    } else {
      num -= month_day-day_ + 1;
      day_ = 1;
      add_month(1);
    }
  }
}

void Date::add_month(int num) {
  if (num < 0) {
    return;
  }

  add_year((month_ + num - 1) / 12);
  month_ += num % 12;
  month_ = ((month_ == 12) ? 12 : month_ % 12);
}

void Date::add_year(int num) {
  if (num < 0) {
    return;
  }
  year_ += num;
}

void Date::show_date() {
  std::cout << "Year: " << year_
            << ", Month: " << month_
            << ", Day: " << day_ << std::endl;
}

bool Date::is_leap_year() {
  return (year_ % 4 == 0 && year_ % 100 != 0) ||
         (year_ % 400 == 0);
}

int main() {
  Date date1;  // Date()
  date1.show_date();

  Date date2(2021, 7, 1);  // Date(int y, int m, int d)
  date2.show_date();

  Date date;
  date.set_date(2011, 3, 1);
  date.show_date();
  date.add_day(30);
  date.show_date();
  date.add_day(2000);
  date.show_date();
  date.set_date(2012, 1, 31);  // leapyear
  date.add_day(29);
  date.show_date();
  date.set_date(2012, 8, 4);
  date.add_day(2500);
  date.show_date();

  return 0;
}
