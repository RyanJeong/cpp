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

// copy 7-4
#include <iostream>

class Power {
  int kick;
  int punch;
 public:
  explicit Power(int kick = 0, int punch = 0) : kick(kick), punch(punch) { }
  void show();
  Power operator+(const Power& op2);
  bool operator==(const Power& op2);
};

void Power::show() {
  std::cout << "kick = " << kick << ", " << "punch = " << punch << std::endl;
}

Power Power::operator+(const Power& op2) {
  Power tmp;
  tmp.kick = this->kick + op2.kick;
  tmp.punch = this->punch + op2.punch;

  return tmp;
}

bool Power::operator==(const Power& op2) {
  return (this->kick == op2.kick && this->punch == op2.punch);
}

int main() {
  Power a(3, 5), b(3, 5);
  a.show();
  b.show();
  std::cout << ((a == b) ? "Two power are same!" : "Two power are not same!");

  return 0;
}
