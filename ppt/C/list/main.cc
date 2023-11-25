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

#include "list.hpp"  // [NOLINT]

int main() {
  List<std::string> list;
  list.insert(0, "Michael");
  list.insert(1, "Jane");
  list.insert(2, "Sophie");
  list.insert(3, "Thomas");
  list.insert(4, "Rose");
  list.insert(5, "Richard");
  std::cout << "Printing the list" << std::endl;
  list.print();
  std::cout << "Getting data in some nodes" << std::endl;
  std::cout << list.get(0) << std::endl;
  std::cout << list.get(5) << std::endl;
  std::cout << "Erasing some nodes and printing after erasures" << std::endl;
  list.erase(0);
  list.erase(3);
  list.print();
  std::cout << "Checking the list size" << std::endl;
  std::cout << "List size: " << list.size();
  return 0;
}

