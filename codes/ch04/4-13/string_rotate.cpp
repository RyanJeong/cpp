/*
    Copyright 2021 Munseong Jeong <msjeong@daejin.ac.kr>

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
  std::cout << "아래에 문자열을 입력하세요. "
            << "빈 칸이 있어도 됩니다.(한글 안됨) " << std::endl;
  std::string s;
  getline(std::cin, s, '\n');
  int len = s.length();

  // Hello, World!
  for (int i = 0; i < len; ++i) {
    std::string first = s.substr(0, 1);
    std::string sub = s.substr(1, len - 1);
    s = sub + first;
    std::cout << s << std::endl;
  }

  return 0;
}
