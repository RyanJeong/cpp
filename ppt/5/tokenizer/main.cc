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

#include "tokenizer.hpp"

int main() {
  // The target string that needs to be tokenized
  std::string target("This is the string to be tokenized.\n");
  // The delimit string defines the set of separators
  std::string delimit(" \n"); // Delimiter made of ' ' and '\n'
  // Instantiation of tokenizer object 
  Tokenizer tokenizer(target, delimit); 
  // Traversing the target string to find tokens 
  while (tokenizer.more_token())
    std::cout << tokenizer.next_token() << std::endl;
  return 0;
}

