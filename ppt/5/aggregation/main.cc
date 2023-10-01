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

int main() {
  // Here's the instantiation part
  // Notice that the lifetime of the aggregatee is INDEPENDENT of the lifetime
  // of the aggregator.
  Date date1(5, 6, 1980);
  Person person1(123456789L, date1);
  Date date2(4, 23, 1978);
  Person person2(987654321L, date2);

  person1.print();
  person2.print();
  return 0;
}

