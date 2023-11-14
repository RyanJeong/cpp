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
#include <fstream>
#include <cassert>

int main() {
  std::fstream fstr("integer.txt", std::ios::in | std::ios::out);
  if (!fstr.is_open()) {
    std::cerr << "integer.txt cannot be opened!";
    assert(false);
  }
  int num, sum = 0;
  while (fstr >> num)
    sum += num;
  // when the loop terminates the eofbit is set and we cannot use the stream
  fstr.clear();
  fstr << "\nThe sum of the numbers is: " << sum;
  fstr.close();
  return 0;
}

