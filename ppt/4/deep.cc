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

class DeepString {
 public:
  explicit DeepString(const char* s) {
    data_ = new char[strlen(s)+1];
    strncpy(data_, s, strlen(s));
  }
  // Copy constructor (deep copy)
  DeepString(const DeepString& str) {
    data_ = new char[strlen(str.data_)+1];
    strncpy(data_, str.data_, strlen(str.data_));
  }
  ~DeepString() { delete[] data_; }

 private:
  char* data_;
};

int main() {
  DeepString str1("Hello");
  DeepString str2 = str1;  // deep copy occurs here
  DeepString str3 = str1;  // another deep copy
  return 0;
  // Each object has independent memory, so memory is safely deallocated
}

