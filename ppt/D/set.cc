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
#include <set>

int main() {
  std::set<int> set;
  set.insert(10);
  set.insert(20);
  set.insert(30);
  std::cout << "Size: " << set.size() << std::endl;
  std::cout << "Is empty: " << (set.empty() ? "Yes" : "No") << std::endl;

  std::cout << "Elements in the set:";
  for (const int& element : set) std::cout << " " << element;
  std::cout << std::endl;

  std::cout << "20 is " << (set.find(20) == set.end() ? "not " : "")
            << "in the set." << std::endl;
  std::cout << "40 is " << (set.find(40) == set.end() ? "not " : "")
            << "in the set." << std::endl;

  std::cout << "Erased " << set.erase(10)
            << " element(s) with key 10"<< std::endl;
  std::cout << "Erased " << set.erase(5)
            << " element(s) with key 5" << std::endl;

  std::set<int> temp_set = {100, 200, 300};
  set.swap(temp_set);
  if (set == temp_set) std::cout << "Sets are equal." << std::endl;

  set.clear();
  std::cout << "Size after clear: " << set.size() << std::endl;
  return 0;
}

