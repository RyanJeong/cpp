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
#include <string>

void star(int a = 5);
void msg(int id, std::string text = "");

int main() {
  star();  // star(5);
  star(10);

  msg(10);  // star(10, "");
  msg(10, "Hello");

  return 0;
}

void star(int a) {
  for (int i = 0; i < a; i++) {
    std::cout << '*';
  }
  std::cout << std::endl;
}

void msg(int id, std::string text) {
  std::cout << id << ' ' << text << std::endl;
}
