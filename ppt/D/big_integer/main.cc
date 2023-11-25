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

#include <iostream>
#include <string>
#include <iomanip>

#include "big_integer.hpp"  // [NOLINT]

int main() {
  std::string strg1, strg2;
  std::cout << "Enter the first big integer: ";
  std::cin >> strg1;
  std::cout << "Enter the second big integer: ";
  std::cin >> strg2;

  BigInteger first(strg1);
  BigInteger second(strg2);
  BigInteger result = first + second;

  strg1 = first.to_string();
  strg2 = second.to_string();
  std::string strg3 = result.to_string();
  std::string dashes(strg3.length(), '-');
  std::cout << "First big integer " << std::setw(strg3.length());
  std::cout << std::right << strg1 << " + " << std::endl;
  std::cout << "Second big integer" << std::setw(strg3.length());
  std::cout << std::right << strg2 << std::endl;
  std::cout << " " << dashes << std::endl;
  std::cout << "Result " << std::setw(strg3.length());
  std::cout << std::right << strg3 << std::endl;
  return 0;
}

