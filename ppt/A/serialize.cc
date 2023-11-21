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
#include <fstream>

void serialize(const std::string& str, std::ostream& out) {
  size_t length = str.size();
  out.write(reinterpret_cast<const char*>(&length), sizeof(length));
  out.write(str.data(), length);
}

std::string deserialize(std::istream& in) {
  size_t length;
  in.read(reinterpret_cast<char*>(&length), sizeof(length));

  std::string str;
  str.resize(length);
  in.read(&str[0], length);

  return str;
}

int main() {
  std::string str = "Hello, World!";

  std::ofstream ofstr("serialize.bin", std::ios::binary);
  serialize(str, ofstr);
  ofstr.close();

  std::ifstream ifstr("serialize.bin", std::ios::binary);
  std::string result = deserialize(ifstr);
  ifstr.close();

  std::cout << "Deserialized String: " << result << std::endl;
  return 0;
}

