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
  int int1 = 12325;
  double double1 = 45.78;
  std::ofstream ofstr("Sample", std::ios::out | std::ios::binary);
  if (!ofstr.is_open()) {
    std::cerr << "The file Sample cannot be opened for writing!";
    assert(false);
  }
  ofstr.write(reinterpret_cast<char*>(&int1), sizeof(int));
  ofstr.write(reinterpret_cast<char*>(&double1), sizeof(double));
  ofstr.close();

  int int2;
  double double2;
  std::ifstream ifstr("Sample", std::ios::in | std::ios::binary);
  if (!ifstr.is_open()) {
    std::cerr << "The file Sample cannot be opened for reading!";
    assert(false);
  }
  ifstr.read(reinterpret_cast<char*>(&int2), sizeof(int));
  ifstr.read(reinterpret_cast<char*>(&double2), sizeof(double));
  ifstr.close();

  std::cout << "Value of int2: " << int2 << std::endl;
  std::cout << "Value of double2: " << double2 << std::endl;
  return 0;
}

