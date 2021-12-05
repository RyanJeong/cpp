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
#include <map>

int main() {
  std::map<std::string, std::string> dic;
  dic.insert(std::make_pair("love", "사랑"));
  dic.insert({"apple", "사과"});
  dic["cherry"] = "체리";
  std::cout << "저장된 단어 개수 :" << dic.size() << std::endl;

  std::string eng;
  while (true) {
    std::cout << "찾고 싶은 단어>> ";
    getline(std::cin, eng);
    if (eng == "exit")
      break;

    std::cout << ((dic.find(eng) == dic.end()) ? "없음" : dic[eng])
              << std::endl;
  }

  return 0;
}
