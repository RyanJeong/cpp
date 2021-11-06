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

double area(int r);
double area(int r) { return 3.14 * r * r; }

int main() {
  int n = 3;
  char c = '#';

  std::cout << c << 5.5 << '-' << n << "hello" << true << std::endl;
  std::cout << "n + 5 = " << n + 5 << '\n';
  std::cout << "면적은 " << area(n);

  return 0;
}
