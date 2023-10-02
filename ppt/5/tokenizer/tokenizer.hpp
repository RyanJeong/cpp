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

#include <string>

class Tokenizer {
  std::string target_;
  std::string delim_;
  int begin_;
  int end_;

 public:
  Tokenizer(const std::string& target, const std::string& delim);
  ~Tokenizer() = default;
  bool more_token() const;
  std::string next_token();
};
