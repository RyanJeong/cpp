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

class Adder {
 protected:
  int add(int a, int b) { return a + b; }
};

class Subtractor {
 protected:
  int minus(int a, int b)  { return a - b; }
};

class Calculator : public Adder, public Subtractor {
 public:
  int calc(char op, int a, int b);
};

int Calculator::calc(char op, int a, int b) {
  int res = 0;
  switch (op) {
  case '+' :
    res = add(a, b);
    break;
  case '-' :
    res = minus(a, b);
    break;
  default:
    break;
  }

  return res;
}

int main() {
  Calculator handCalculator;
  std::cout << "2 + 4 = "
            << handCalculator.calc('+', 2, 4) << std::endl;
  std::cout << "100 - 8 = "
            << handCalculator.calc('-', 100, 8) << std::endl;

  return 0;
}
