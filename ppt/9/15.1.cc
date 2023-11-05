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

// Function to find the smaller between two characters
char smaller(char op1, char op2) { return op1 < op2 ? op1 : op2; }

// Function to find the smaller between two integers
int smaller(int op1, int op2) { return op1 < op2 ? op1 : op2; }

// Function to find the smaller between two doubles
double smaller(double op1, double op2) { return op1 < op2 ? op1 : op2; }

int main() {
  std::cout << "Smaller of 'a' and 'b': " << smaller('a', 'b') << std::endl;
  std::cout << "Smaller of 12 and 15: " << smaller(12, 15) << std::endl;
  std::cout << "Smaller of 44.2 and 33.1: " << smaller(44.2, 33.1) << std::endl;
  return 0;
}

