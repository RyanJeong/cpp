/*
    Copyright 2023 Munseong Jeong <munseong.jeong@daejin.ac.kr>

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
#include <cstring>

// Shallow copy copies only a pointer so that the two pointers now refer to the
// same object. That’s what pointers and references do.
class ShallowString {
 public:
  explicit ShallowString(const char* s) {
    data_ = new char[std::strlen(s)+1];
    std::strncpy(data_, s, std::strlen(s));
  }
  // Copy constructor (shallow copy)
  // NOTICE: Group 2(Copy constructor) is missing,
  // so the system will create a default copy constructor
  ~ShallowString() { delete[] data_; }

 private:
  char* data_;
};

int main() {
  ShallowString str1("Hello");
  ShallowString str2 = str1;  // shallow copy occurs here
  ShallowString str3 = str1;  // another shallow copy
  return 0;
  // str2 and str3 share the same memory with str1, so delete[] gets called
  // multiple times (it leads to memory issues)
}

