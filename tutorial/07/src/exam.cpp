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
#include <string.h>

class Test {
 public:
  explicit Test(char* name);
  ~Test();
 private:
  char* name_;
};

Test::Test(char* name) {
  name_ = new char[strlen(name) + 1];
  strcpy(name_, name);
  std::cout << name_ << " 생성자 호출" << std::endl;
}

Test::~Test() {
  if (name_ != NULL) {
    std::cout << name_ << " 소멸자 호출" << std::endl;
    delete[] name_;
  }
}

void foo();

int main() {
  Test test((char*) "main()");
  foo();

  return 0;
}

void foo(void) {
  Test test((char*) "foo()");
}
