/*
    Copyright 2022 Munseong Jeong <ryan.m.jeong@hotmail.com>

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
#include <string.h>  // [NOLINT]

class MyString {
 public:
  MyString(const MyString& m_str);  // [NOLINT]
  MyString(const char* str);        // [NOLINT]
  MyString(char c);                 // [NOLINT]
  ~MyString(void);

  int compare(const MyString& m_str) const;
  bool operator==(const MyString& m_str) const;

 private:
  char* content_;
  int length_;
  int capacity_;
};

MyString::MyString(const MyString& m_str) {
  length_ = m_str.length_;
  capacity_ = length_;
  content_ = new char[length_];

  // strcpy(content_,m_str.content_); not terminated with 'null' character
  for (int i = 0; i < length_; ++i)
    content_[i] = m_str.content_[i];
}

MyString::MyString(const char* str) {
  length_ = strlen(str);
  capacity_ = length_;
  content_ = new char[length_];
  strcpy(content_, str);  // [NOLINT]
}

MyString::MyString(char c) {
  length_ = 1;
  capacity_ = length_;
  content_ = new char[length_];
  *content_ = c;
}

MyString::~MyString(void) {
  delete[] content_;
}

int MyString::compare(const MyString& m_str) const {
  if (length_ != m_str.length_) {
    return ((length_ > m_str.length_) ? 1 : -1);
  } else {  // length_ == m_str.length_
    for (int i = 0; i < length_; ++i) {
      if (content_[i] != m_str.content_[i]) {
        return ((content_[i] > m_str.content_[i]) ? 1 : -1);
      }
    }
  }

  return 0;
}

bool MyString::operator==(const MyString& m_str) const {
  return !compare(m_str);
}

int main() {
  MyString str1 = "Hello";
  MyString str2 = "Hello";
  std::cout << ((str1 == str2) ? "Same!" : "Not same!") << std::endl;  // Same!

  return 0;
}
