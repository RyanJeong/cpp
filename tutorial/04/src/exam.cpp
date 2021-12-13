/*
    Copyright 2021 Munseong Jeong <msjeong@daejin.ac.kr>

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

class Animal {
 public:
  void set_animal(int food, int weight);
  void increase_food(int num);
  void view_state();
 private:
  int food_;
  int weight_;
};  // semocolon!

void Animal::set_animal(int food, int weight) {
  food_ = food;
  weight_ = weight;
}

void Animal::increase_food(int num) {
  food_ += num;
  weight_ += num / 7;
}

void Animal::view_state() {
  std::cout << "The animal's food: " << food_ << std::endl;
  std::cout << "The animal's weight: " << weight_ << std::endl;
}

int main() {
  Animal cat;
  cat.set_animal(100, 10);
  cat.increase_food(10);
  cat.view_state();

  return 0;
}
