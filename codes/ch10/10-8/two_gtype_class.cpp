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

template <typename T1, typename T2>
class GClass {
  T1 data1;
  T2 data2;
 public:
  GClass() : data1(0), data2(0) { }
  void set(const T1& a, const T2& b);
  void get(T1* a, T2* b);
};

template <typename T1, typename T2>
void GClass<T1, T2>::set(const T1& a, const T2& b) {
  this->data1 = a;
  this->data2 = b;
}

template <typename T1, typename T2>
void GClass<T1, T2>::get(T1* a, T2* b) {
  *a = this->data1;
  *b = this->data2;
}

int main() {
  int a;
  double b;
  GClass<int, double> x;
  x.set(2, 0.5);
  x.get(&a, &b);
  std::cout << "a: " << a << ", " << "b: " << b << std::endl;

  char c;
  float d;
  GClass<char, float> y;
  y.set('m', 12.5);
  y.get(&c, &d);
  std::cout << "c: " << c << ", " << "d: " << d << std::endl;

  return 0;
}
