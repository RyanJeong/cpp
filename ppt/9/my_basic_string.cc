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
#include <cctype>
#include <string>

struct my_char_traits : public std::char_traits<char> {
  static int my_rank(char c) { return c + (std::isupper(c) ? 256 : 0); }

  static bool lt(char c1, char c2) { return my_rank(c1) < my_rank(c2); }

  static int compare(const char* s1, const char* s2, size_t n) {
    while (n--) {
      if (my_rank(*s1) < my_rank(*s2))
        return -1;
      if (my_rank(*s1) > my_rank(*s2))
        return 1;
      ++s1;
      ++s2;
    }
    return 0;
  }
};

int main() {
  std::basic_string<char, my_char_traits> my_s1 = "ABcd";
  std::basic_string<char, my_char_traits> my_s2 = "abCD";
  std::cout << "my_char_traits: " << std::boolalpha
            << (my_s1 < my_s2) << std::endl;
  std::string s1 = "ABcd";
  std::string s2 = "abCD";
  std::cout << "C++ string: " << std::boolalpha
            << (s1 < s2) << std::endl;
  return 0;
}
