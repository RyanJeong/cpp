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
#include <iomanip>

#include "student.hpp"  // [NOLINT]

int main() {
  std::fstream ofstr;
  ofstr.open("File.dat", std::ios::binary | std::ios::out);
  if (!ofstr.is_open()) {
    std::cerr << "File.dat cannot be opened for writing!";
    assert(false);
  }
  Student std1("John", 3.91);
  Student std2("Mary", 3.82);
  Student std3("Lucie", 4.00);
  Student std4("Edward", 3.71);
  Student std5("Richard", 3.85);
  ofstr.write(reinterpret_cast<char*>(&std1), sizeof(Student));
  ofstr.write(reinterpret_cast<char*>(&std2), sizeof(Student));
  ofstr.write(reinterpret_cast<char*>(&std3), sizeof(Student));
  ofstr.write(reinterpret_cast<char*>(&std4), sizeof(Student));
  ofstr.write(reinterpret_cast<char*>(&std5), sizeof(Student));
  ofstr.close();

  std::fstream ifstr;
  ifstr.open("File.dat", std::ios::binary | std::ios::in);
  if (!ifstr.is_open()) {
    std::cerr << "File.dat cannot be opened for reading!";
    assert(false);
  } 
  std::cout << std::setw(15) << std::left << "Name" << " "
            << std::setw(4) << "GPA" << std::endl;
  Student std;
  for (int i = 0; i < 5; ++i) {
    ifstr.read(reinterpret_cast<char*>(&std), sizeof(Student));
    std::cout << std::setw(15) << std::left << std.name() << " "
              << std::fixed << std::setw(4) << std::setprecision(2) << std.gpa()
              << std::endl;
  }
  ifstr.close();
  return 0;
}

// TODO(munseong): fix the error:
// Name            GPA
// John            3.91
// Mary            3.82
// Lucie           4.00
// Edward          3.71
// Richard         3.85
// munmap_chunk(): invalid pointer
// Aborted

