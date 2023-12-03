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
#include <list>
#include <algorithm>

// Define a predicate function for remove_if (even numbers)
struct IsEven {
  bool operator()(int x) const { return x % 2 == 0; }
};

int main() {
  // Declare a list of integers and initialize it
  std::list<int> my_list = {9, 1, 2, 3, 4, 3, 5, 6, 7, 3, 8};
  // Remove all occurrences of a specific value (e.g., 3)
  my_list.remove(3);
  // Output the list after removing elements
  std::cout << "After removing 3: ";
  for (const auto& num : my_list) std::cout << num << " ";
  std::cout << std::endl;
  // Remove elements that satisfy a certain condition (e.g., even numbers)
  my_list.remove_if(IsEven());
  // Output the list after removing even elements
  std::cout << "After removing even elements: ";
  for (const auto& num : my_list) std::cout << num << " ";
  std::cout << std::endl;
  // Sort the list
  my_list.sort();
  // Output the sorted list
  std::cout << "Sorted list: ";
  for (const auto& num : my_list) std::cout << num << " ";
  std::cout << std::endl;
  // Create another list to demonstrate splice and merge
  std::list<int> other_list = {10, 20, 30, 40};
  // Splice elements from other_list into my_list at a specific position
  auto pos = my_list.begin();
  // iterators for list is bidirectional, so they can only use ++ or --
  // pos += 2; error!
  ++pos;
  ++pos;
  my_list.splice(pos, other_list);
  // Output my_list after splicing
  std::cout << "After splicing other_list into my_list: ";
  for (const auto& num : my_list) std::cout << num << " ";
  std::cout << std::endl;
  // Merge two sorted lists (my_list and other_list should be sorted)
  my_list.merge(other_list);
  // Output the merged list
  std::cout << "Merged list: ";
  for (const auto& num : my_list) std::cout << num << " ";
  std::cout << std::endl;
  return 0;
}

