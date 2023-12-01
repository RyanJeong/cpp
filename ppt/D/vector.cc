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
  std::vector<int> vec;
  std::vector<int> vec1(4, 42);
  std::vector<int> vec2{1, 2, 3, 4, 5};
  std::vector<int> other_vec = vec2;

  std::cout << "Size of vec2: " << vec2.size() << std::endl;
  std::cout << "Max size of vec2: " << vec2.max_size() << std::endl;
  vec2.resize(7, 0);
  std::cout << (vec2.empty() ? "vec2 is empty" : "vec2 is not empty")
            << std::endl;
  std::cout << "Capacity of vec2: " << vec2.capacity() << std::endl;
  vec2.reserve(10);
  std::cout << "First element of vec2: " << vec2.front() << std::endl;
  std::cout << "Last element of vec2: " << vec2.back() << std::endl;
  int i = 2;
  std::cout << "Element at index " << i << ": " << vec2[i] << std::endl;
  std::cout << "Element at index " << i << " (using at): " << vec2.at(i)
            << std::endl;

  std::vector<int>::iterator iter;
  std::vector<int>::reverse_iterator riter;
  for (iter = vec2.begin(); iter != vec2.end(); ++iter)
    std::cout << *iter << " ";
  std::cout << std::endl;
  for (riter = vec2.rbegin(); riter != vec2.rend(); ++riter)
    std::cout << *riter << " ";
  std::cout << std::endl;
  vec2.push_back(10);
  std::vector<int>::iterator pos = vec2.begin() + 3;
  vec2.insert(pos, 99);
  vec2.pop_back();
  vec2.erase(vec2.begin() + 2);
  vec2.clear();

  int rows = 3;
  int cols = 4;
  int value = 42;
  std::vector<std::vector<int>> table(rows, std::vector<int>(cols, value));
  table[1][2] = 99;
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) std::cout << table[i][j] << " ";
    std::cout << std::endl;
  }
  return 0;
}

