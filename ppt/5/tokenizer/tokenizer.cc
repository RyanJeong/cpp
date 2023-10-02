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

#include "tokenizer.hpp"  // [NOLINT]

Tokenizer::Tokenizer(const std::string& tar, const std::string& del)
    : target_(tar), delim_(del) {
  begin_ = target_.find_first_not_of(delim_, 0);
  end_ = target_.find_first_of(delim_, begin_);
}

bool Tokenizer::more_token() const { return (begin_ != std::string::npos); }

std::string Tokenizer::next_token() {
  std::string token = target_.substr(begin_, end_ - begin_);
  begin_ = target_.find_first_not_of(delim_, end_);
  end_ = target_.find_first_of(delim_, begin_);
  return token;
}

