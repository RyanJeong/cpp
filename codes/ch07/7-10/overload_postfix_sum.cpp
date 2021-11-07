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

// copy 7-9
#include <iostream>

class Power {
  int kick;
  int punch;
 public:
  explicit Power(int kick = 0, int punch = 0) : kick(kick), punch(punch) { }
  void show();
  Power operator+(const Power& op2);
  Power operator+(const int& op2);
  bool operator==(const Power& op2);
  bool operator!();
  Power& operator+=(const Power& op2);
  Power& operator++();
  Power operator++(int x);
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

Power Power::operator+(const int& op2) {
  Power tmp;
  tmp.kick = this->kick + op2;
  tmp.punch = this->punch + op2;

  return tmp;
}

bool Power::operator==(const Power& op2) {
  return (this->kick == op2.kick && this->punch == op2.punch);
}

bool Power::operator!() {
  return (this->kick == 0 && this->punch == 0);
}

Power& Power::operator+=(const Power& op2) {
  this->kick += op2.kick;
  this->punch += op2.punch;

  return *this;
}

Power& Power::operator++() {
  ++this->kick;
  ++this->punch;

  return *this;
}

Power Power::operator++(int x) {
  Power tmp = *this;
  ++this->kick;
  ++this->punch;

  return tmp;
}

int main() {
  Power a(3, 5), b;
  a.show();
  b.show();
  b = a++;
  a.show();
  b.show();

  return 0;
}
