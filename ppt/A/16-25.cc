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
#include <iomanip>

std::ostream& currency(std::ostream& stream) {
  std::cout << '$';
  stream.precision(2);
  stream.fill('*');
  stream.setf(std::ios::fixed, std::ios::floatfield);
  return stream;
}

int main() {
  std::cout << currency << std::setw(12) << 12325.45 << std::endl;
  std::cout << currency << std::setw(12) << 0.36 << std::endl;
  return 0;
}

