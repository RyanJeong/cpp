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

bool palindrome(const std::string& str) {
  if (str.length() <= 1)
    return true;
  if (str[0] != str[str.length()-1])
    return false;
  return palindrome(str.substr(1, str.length() - 2));
}

int main() {
  std::string s1("hello");
  std::string s2("rotor");
  std::cout << std::boolalpha;
  std::cout << "Is " << s1 << " a palindrome? " << palindrome(s1) << std::endl;
  std::cout << "Is " << s2 << " a palindrome? " << palindrome(s2) << std::endl;
  return 0;
}

