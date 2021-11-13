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
  /*
  It's now or never, come hold me tight. Kiss me my darling, be mine tonight
  Tomorrow will be too late. It's now or never, my love won't wait&
  */
  std::cout << "여러 줄의 문자열을 입력하세요. "
            << "입력의 끝은 &문자입니다." << std::endl;
  std::string s;
  getline(std::cin, s, '&');
  // '&' 뒤에 따라 오는 <Enter> 키를 제거하기 위한 코드
  std::cin.ignore();

  std::cout << std::endl << "find: ";
  std::string f;
  getline(std::cin, f, '\n');

  std::cout << "replace: ";
  std::string r;
  getline(std::cin, r, '\n');

  int startIndex = 0;
  while (true) {
    // startIndex부터 문자열 f 검색
    int fIndex = s.find(f, startIndex);
    if (fIndex == -1) {
      break;
    }
    // fIndex부터 문자열 f의 길이만큼 문자열 r로 변경
    s.replace(fIndex, f.length(), r);
    startIndex = fIndex + r.length();
  }
  std::cout << s << std::endl;

  return 0;
}
