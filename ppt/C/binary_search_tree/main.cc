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

#include "binary_search_tree.hpp"  // [NOLINT]

int main() {
  BinarySearchTree<std::string> bct;
  bct.insert("Michael");
  bct.insert("Jane");
  bct.insert("Sophie");
  bct.insert("Thomas");
  bct.insert("Rose");
  bct.insert("Richard");
  std::cout << "Using preorder traversal" << std::endl;
  bct.preorder();
  std::cout << std::endl << std::endl;
  std::cout << "Using inorder traversal" << std::endl;
  bct.inorder();
  std::cout << std::endl << std::endl;
  std::cout << "Using postorder traversal" << std::endl;
  bct.postorder();
  std::cout << std::endl << std::endl;
  std::cout << "Searching: " << std::boolalpha << std::endl;
  std::cout << "Is Sophie in the tree? ";
  std::cout << bct.search("Sophie") << std::endl;
  std::cout << "Is Mary in the tree? ";
  std::cout << bct.search("Mary") << std::endl;
  return 0;
}
