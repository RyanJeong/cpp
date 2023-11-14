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
  std::ifstream ifstr("data.txt" , std::ios::in);
  if (!ifstr.is_open()) {
    std::cerr << "The file data.txt cannot be opened for reading!";
    assert(false);
  }

  for (char ch; ifstr.get(ch); ) {
    if (std::isdigit(ch)) {
      ifstr.unget();
      int n;
      ifstr >> n;
      std::cout << n << " ";
    }
  }
  ifstr.close();
  return 0;
}

