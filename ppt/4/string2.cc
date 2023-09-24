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
#include <string>

int main() {
  std::string str;

  // Input and output
  std::cout << "Enter a string: ";
  std::cin >> str;              // you can input a word here
  std::cout << "The word you entered is: " << str << std::endl;
  std::cin.ignore();            // consume a '\n' stored in the input buffer
  std::getline(std::cin, str);  // you can input a sentence here
  std::cout << "The sentence you entered is: " << str << std::endl;

  return 0;
}

