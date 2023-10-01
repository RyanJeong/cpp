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

#include "name.hpp"  // [NOLINT]

#include <iostream>
#include <cassert>

Name::Name(const std::string& fst,
           const std::string& i,
           const std::string& lst) : first_(fst), init_(i), last_(lst) {
  assert(init_.size() == 1);
  std::toupper(first_[0]);
  std::toupper(init_[0]);
  std::toupper(last_[0]);
}

// Print member function
void Name::print() const {
  std::cout << "Emplyee name: " << first_ << " " << init_ << ". ";
  std::cout << last_ << std::endl;
}

