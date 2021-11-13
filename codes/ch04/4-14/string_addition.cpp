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
  std::cout << "7+23+5+100+25와 같이 덧셈 문자열을 입력하세요."
            << std::endl;
  std::string s;
  getline(std::cin, s, '\n');

  int sum = 0;
  while (true) {
    // s의 처음부터 찾는다.
    // int idx = s.find('+');

    // s의 0번째 문자부터 찾는다.
    int idx = s.find('+', 0);
    if (idx == -1) {
      if (!s.empty()) {
        std::cout << s << std::endl;
        sum+=stoi(s);
      }
      break;
    }

    int cnt = idx;
    // idx부터 문자열 끝까지
    // std::string tmp = s.substr(idx);

    // 0부터 cnt개
    std::string tmp = s.substr(0, cnt);
    std::cout << tmp << std::endl;
    sum+=stoi(tmp);
    // pos 문자 삭제
    // s.erase(pos);

    // 0부터 cnt+1개
    s.erase(0, cnt+1);
  }
  std::cout << "숫자들의 합은 " << sum << std::endl;

  return 0;
}
