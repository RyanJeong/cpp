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
  // Creation of reference relations
  int score = 92;
  int& r_score = score;

  // Using data variable
  std::cout << "Accessing value through data variable." << std::endl;
  std::cout << "score: " << score << std::endl;

  // Using reference variable
  std::cout << "Accessing value through reference variable." << std::endl;
  std::cout << "r_score: " << r_score;

  return 0;
}

