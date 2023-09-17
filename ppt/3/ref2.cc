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

void swap(int& first, int& second);  // Prototype

int main() {
  // Definition of two variables
  int x = 10;
  int y = 20;
  // Printing the value of x and y before swapping
  std::cout << "Values of x and y before swapping." << std::endl;
  std::cout << "x: " << x << " " << "y: " << y << std::endl;
  // Calling swap function to swap the values of x and y
  swap(x, y);
  // Printing the value of x and y after swapping
  std::cout << "Values of x and y after swapping." << std::endl;
  std::cout << "x: " << x << " " << "y: " << y;
  return 0;
}

void swap(int& r_x, int& r_y) {
  int temp = r_x;
  r_x = r_y;
  r_y = temp;
}

