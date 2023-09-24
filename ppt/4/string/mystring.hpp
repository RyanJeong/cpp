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

#pragma once

class MyString {
  char* string_;
  int length_;
  int capacity_;

 public:
  explicit MyString(int cap);
  MyString(const char* str);  // [NOLINT]
  MyString(const MyString& str);
  ~MyString();

  int length() const;
  int capacity() const;
  void reserve(int size);
  void println() const;
  MyString& insert(int pos, const MyString& str);
  MyString& insert(int pos, const char* str);
  MyString& insert(int pos, char c);
  MyString& erase(int pos, int num);
};

