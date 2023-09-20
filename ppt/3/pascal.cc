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
#include <iomanip>

int main() {
  // Declaration
  int n, max_power = 10;
  // Input validation
  do {
    std::cout << "Enter the power of binomial : ";
    std::cin >> n;
  } while (n < 0 || n > max_power);
  // Allocate memory from heap
  int** pascal = new int*[n+1];
  for (int i = 0; i <= n; ++i)
    pascal[i] = new int[i+1];
  // Formation of the coefficient
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= i; j++)
      pascal[i][j] = j == 0 || i == j ? 1 : pascal[i-1][j-1] + pascal[i-1][j];
  }
  // Print coefficients
  std::cout << std::endl;
  std::cout << "Coefficients for (x + y)^" << n << " are:";
  for (int i = 0; i <= n; i++)
    std::cout << std::setw(5) << pascal[n][i];
  std::cout << std::endl;
  // Delete allocated memory
  for (int i = 0; i <= n; i++)
    delete[] pascal[i];
  delete[] pascal;
  return 0;
}

