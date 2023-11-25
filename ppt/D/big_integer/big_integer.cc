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

#include "big_integer.hpp"  // [NOLINT]

#include <string>
#include <list>

BigInteger::BigInteger(const std::string& str) : list_(std::list<int>()) {
  for (const auto& c : str) list_.push_back(static_cast<int>(c - '0'));
}

std::string BigInteger::to_string() const {
  std::string str;
  std::list<int>::const_iterator iter = list_.begin();  // bidirectional
  while (iter != list_.end()) str += *iter++ + '0';
  return str;
}

BigInteger operator+(const BigInteger& first, const BigInteger& second) {
  std::list<int>::const_reverse_iterator iter1 = first.list_.rbegin();
  std::list<int>::const_reverse_iterator iter2 = second.list_.rbegin();
  BigInteger result;
  int num1, num2, sum;
  int carry = 0;
  while ((iter1 != first.list_.rend()) && iter2 != second.list_.rend()) {
    num1 = *iter1++;
    num2 = *iter2++;
    sum = (num1 + num2 + carry) % 10;
    carry = (num1 + num2 + carry) / 10;
    result.list_.push_front(sum);
  }
  while (iter1 != first.list_.rend()) {
    num1 = *iter1++;
    sum = (num1 + carry) % 10;
    carry = (num1 + carry) / 10;
    result.list_.push_front(sum);
  }
  while (iter2 != second.list_.rend()) {
    num2 = *iter2++;
    sum = (num2 + carry) % 10;
    carry = (num2 + carry) / 10;
    result.list_.push_front(sum);
  }
  if (carry == 1) result.list_.push_front(carry);
  return result;
}
