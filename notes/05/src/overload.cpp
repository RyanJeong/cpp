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

void print(int x) { std::cout << "int: " << x << std::endl; }
void print(char x) { std::cout << "char: " << x << std::endl; }
void print(double x) { std::cout << "double: " << x << std::endl; }

int main() {
  int a = 5;
  char b = 'a';
  double c = 3.14;

  print(a);
  print(b);
  print(c);

  return 0;
}