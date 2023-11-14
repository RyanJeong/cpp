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
  std::ofstream ofstr;  // 1. Instantiation of an ofstream object
  // 2. Creation of a file and connecting it to the ofstream object
  ofstr.open("file_ex1.txt");
  if (!ofstr.is_open()) {  // opt. Testing opening success
    std::cerr << "file_ex1.txt cannot be opened!";
    assert(false);
  }
  // 3. Writing to the file using overloaded insertion operator
  for (int i = 1; i <= 10; ++i)
    ofstr << i * 10 << " ";
  ofstr.close();  // 4. Closing the file
  // 5. The ofstream object is destroyed after return statement
  return 0;
}

