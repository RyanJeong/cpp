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
#include <string>  // string class

int main() {
  // string song("Falling in love with you"); // 문자열 song
  std::string song = "Falling in love with you";
  std::cout << song + "를 부른 가수는";

  // string elvis("Elvis Presley"); // 문자열 elvis
  std::string elvis = "Elvis Presley";
  std::cout << "(힌트 : 첫글자는 " << elvis[0] << ")?";

  std::string singer;
  std::getline(std::cin, singer);
  if (singer == elvis) {
    std::cout << "맞았습니다.";
  } else {
    std::cout << "틀렸습니다. "+ elvis + "입니다." << std::endl;
  }

  return 0;
}
