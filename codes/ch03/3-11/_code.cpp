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

#ifdef BLOCK
#include <iostream>

class Adder {
  int op1, op2;
 public:
  Adder(int a, int b);
  int process(void);
};

Adder::Adder(int a, int b) : op1(a), op2(b) { }

int Adder::process(void) { return op1 + op2; }

class Calculator {
 public:
  void run(void);
};

void Calculator::run(void) {
  std::cout << "두 개의 수를 입력하세요>>";
  int a, b;
  std::cin >> a >> b;
  Adder adder(a, b);
  std::cout << adder.process();

  return;
}

int main() {
  Calculator calc;
  calc.run();

  return 0;
}
#endif
