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
  std::ifstream ifstr;  // 1. Instantiation of an ifstream object
  // 2. Connection of the existing file to the ifstream object
  ifstr.open("file_ex1.txt");
  if (!ifstr.is_open()) {  // opt. Testing opening success
    std::cerr << "file_ex1.txt cannot be opened!";
    assert(false);
  }
  // 3. Reading from the ifstream object and writing to the cout object
  for (int i = 1; i <= 10; ++i) {
    int data;
    ifstr >> data;
    std::cout << data << " ";
  }
  // 4. Disconnection of the file_ex1.txt from the ifstream object
  ifstr.close();
  // 5. Destruction of the ifstream object is done after return
  return 0;
}

