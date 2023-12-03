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
#include <map>

int main() {
  std::map<int, std::string> map;
  map.insert(std::make_pair(1, "Alice"));
  // this expression is more shorter than std::make_pair
  map.insert({2, "Bob"});
  map.insert({3, "Charlie"});
  std::cout << "Size: " << map.size() << std::endl;
  std::cout << "Is empty: " << (map.empty() ? "Yes" : "No") << std::endl;

  std::cout << "Key-value pairs in the map:" << std::endl;
  for (const auto& pair : map)
    std::cout << pair.first << ": " << pair.second << std::endl;

  std::cout << "2 is " << (map.find(2) == map.end() ? "not " : "")
            << "in the map." << std::endl;
  std::cout << "4 is " << (map.find(4) == map.end() ? "not " : "")
            << "in the map." << std::endl;

  std::cout << "Erased " << map.erase(2)
            << " element(s) with key 10"<< std::endl;
  std::cout << "Erased " << map.erase(4)
            << " element(s) with key 5" << std::endl;

  std::map<int, std::string> temp_map = {{100, "David"}, {200, "Eve"}};
  map.swap(temp_map);
  if (map == temp_map) std::cout << "Maps are equal." << std::endl;

  map.clear();
  std::cout << "Size after clear: " << map.size() << std::endl;

  return 0;
}

