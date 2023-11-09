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

#include "fun.hpp"  // [NOLINT]

int main() {
  // Instantiation of four classes each with different data type
  Fun<int> fun1(23);
  Fun<double> fun2(12.7);
  Fun<char> fun3('A');
  Fun<std::string> fun4("Hello");
  // Displaying the data values for each class
  std::cout << "fun1: " << fun1.get() << std::endl;
  std::cout << "fun2: " << fun2.get() << std::endl;
  std::cout << "fun3: " << fun3.get() << std::endl;
  std::cout << "fun4: " << fun4.get() << std::endl;
  // Setting the data values in two classes
  fun1.set(47);
  fun3.set('B');
  // Displaying values for newly set data
  std::cout << "fun1 after set: " << fun1.get() << std::endl;
  std::cout << "fun3 after set: " << fun3.get() << std::endl;
  return 0;
}
