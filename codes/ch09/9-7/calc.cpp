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

class Calculator {
  void input() {
    std::cout << "정수 2 개를 입력하세요>> ";
    std::cin >> a >> b;
  }
 protected:
  int a, b;
  virtual int calc(int a, int b) = 0;
 public:
  void run() {
    input();
    std::cout << "계산된 값은 " << calc(a, b) << std::endl;
  }
};

class Adder : public Calculator {
 protected:
  int calc(int a, int b) { return a + b; }
};

class Subtractor : public Calculator {
 protected:
  int calc(int a, int b) { return a - b; }
};

int main() {
  Adder adder;
  Subtractor subtractor;

  adder.run();
  subtractor.run();

  return 0;
}
