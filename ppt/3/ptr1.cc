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

int main() {
  // Declaration of three data variables
  bool flag = true;
  int score = 92;
  double average = 82.56;
  // Printing size, value, and address of the flag variable
  std::cout << "A variable of type bool" << std::endl;
  std::cout << "Size: " << sizeof(flag) << " ";
  std::cout << "Value: " << flag << " ";
  std::cout << "Address: "<< &flag << std::endl << std::endl;
  // Printing size, value, and address of the score variable
  std::cout << "A variable of type int" << std::endl;
  std::cout << "Size: " << sizeof(score) << " ";
  std::cout << "Value: " << score << " ";
  std::cout << "Address: "<< &score << std::endl << std::endl;
  // Printing size, value, and address of the average variable
  std::cout << "A variable of type double" << std::endl;
  std::cout << "Size: " << sizeof(average) << " ";
  std::cout << "Value: " << average << " ";
  std::cout << "Address: "<< &average << std::endl;
  return 0;
}

