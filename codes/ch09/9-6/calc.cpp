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
 public:
  virtual int add(int a, int b) = 0;
  virtual int subtract(int a, int b) = 0;
  virtual double average(int a[], int size) = 0;
  virtual ~Calculator() = default;
};

class GoodCalc : public Calculator {
 public:
  int add(int a, int b) { return a + b; }
  int subtract(int a, int b) { return a - b; }
  double average(int a[], int size) {
    double sum = 0;
    for (int i = 0; i < size; ++i) {
      sum += a[i];
    }

    return sum / size;
  }
};

int main() {
  int a[] = { 1, 2, 3, 4, 5 };
  Calculator* p = new GoodCalc();
  std::cout << p->add(2, 3) << std::endl;
  std::cout << p->subtract(2, 3) << std::endl;
  std::cout << p->average(a, 5) << std::endl;
  delete p;

  return 0;
}
