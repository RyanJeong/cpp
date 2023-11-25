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
#include <vector>

int main() {
  std::vector<int> vec; // Declare an empty vector of integers
  std::vector<int> vec1(4, 42); // Declare a vector of size 4 with initial values set to 42
  std::vector<int> vec2{1, 2, 3, 4, 5}; // Declare a vector and initialize it with values from 1 to 5
  std::vector<int> other_vec = vec2; // Declare a vector and initialize it with another vector

  std::cout << "Size of vec2: " << vec2.size() << std::endl; // Check the size of the vector
  std::cout << "Max size of vec2: " << vec2.max_size() << std::endl; // Check the maximum size a vector can hold
  vec2.resize(7, 0); // Resize the vector to hold 7 elements, filling with zeros
  std::cout << (vec2.empty() ? "vec2 is empty" : "vec2 is not empty") << std::endl; // Check if the vector is empty
  std::cout << "Capacity of vec2: " << vec2.capacity() << std::endl; // Check the capacity of the vector
  vec2.reserve(10); // Reserve space for 10 elements in the vector
  // Access the first and last elements of the vector
  std::cout << "First element of vec2: " << vec2.front() << std::endl;
  std::cout << "Last element of vec2: " << vec2.back() << std::endl;
  // Access elements using index and at() method
  int i = 2;
  std::cout << "Element at index " << i << ": " << vec2[i] << std::endl;
  std::cout << "Element at index " << i << " (using at): " << vec2.at(i) << std::endl;

  // Declare iterators for vector
  std::vector<int>::iterator iter;
  std::vector<int>::reverse_iterator riter;
  // Iterate through the vector using iterators
  for (iter = vec2.begin(); iter != vec2.end(); ++iter) std::cout << *iter << " ";
  std::cout << std::endl;
  // Reverse iterate through the vector
  for (riter = vec2.rbegin(); riter != vec2.rend(); ++riter) std::cout << *riter << " ";
  std::cout << std::endl;
  vec2.push_back(10); // Push an element to the back of the vector
  // Insert an element at a specific position
  std::vector<int>::iterator pos = vec2.begin() + 3;
  vec2.insert(pos, 99);
  // Remove the last element
  vec2.pop_back();
  // Erase an element at a specific position
  vec2.erase(vec2.begin() + 2);
  // Clear the vector (remove all elements)
  vec2.clear();
  // 2D vector examples
  // Declare a 2D vector of integers with 'rows' elements, all initialized to 'value'
  int rows = 3;
  int cols = 4;
  int value = 42;
  std::vector<std::vector<int>> table(rows, std::vector<int>(cols, value));
  // Access and modify elements of the 2D vector
  table[1][2] = 99;
  // Output elements of the 2D vector
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) std::cout << table[i][j] << " ";
    std::cout << std::endl;
  }
  return 0;
}

