/*
    Copyright 2021 Munseong Jeong <msjeong@daejin.ac.kr>

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

class Ram {
  char mem[100*1024];
  int size;
 public:
  Ram();
  ~Ram();
  char read(int address);
  void write(int address, char value);
};

int main() {
  Ram ram;
  ram.write(100, 20);
  ram.write(101, 30);
  char res = ram.read(100) + ram.read(101);
  ram.write(102, res);

  std::cout << "102 번지의 값 = "
            << static_cast<int>(ram.read(102)) << std::endl;

  return 0;
}
