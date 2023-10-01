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

#include "person.hpp"  // [NOLINT]

#include <iostream>
#include <cassert>

Person::Person(int64_t id, Date bd) : id_(id), birth_date_(bd) {
  assert(id_ >= 1e8 && id_ < 1e9);
}

void Person::print() const {
  std::cout << "Person Identity: " << id_ << std::endl;
  std::cout << "Person date of birth: ";
  birth_date_.print();
  std::cout << std::endl << std::endl;
}

