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

// Definition of a template function
template <typename T>
T smallest(const T& op1, const T& op2) { return op1 < op2 ? op1 : op2; }

// Template function with three parameters
// Note that we have defined the second function in terms of the first one.
// That is the reason the second function is shorter.
template <typename T>
T smallest(const T& op1, const T& op2, const T& op3) {
  return smallest(smallest(op1, op2), op3);
}

int main() {
  // Calling the overloaded version with three integers
  std::cout << "Smallest of 17, 12, and 27 is ";
  std::cout << smallest(17, 12, 27) << std::endl;
  return 0;
}

