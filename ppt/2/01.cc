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

class Circle {
 private:
  double radius_;
  double kPi = 3.141592;

 public:
  double get_radius() const;
  double get_area() const;
  double get_perimeter() const;
  void set_radius(double radius);
};

double Circle::get_radius() const {
  return radius_;
}

double Circle::get_area() const {
  return kPi * radius_ * radius_;
}

double Circle::get_perimeter() const {
  return 2 * kPi * radius_;
}

void Circle::set_radius(double r) {
  radius_ = r;
}

int main() {
  Circle circle1;
  circle1.set_radius(10.0);
  std::cout << "Radius: " << circle1.get_radius() << std::endl;
  std::cout << "Area: " << circle1.get_area() << std::endl;
  std::cout << "Perimeter: " << circle1.get_perimeter() << std::endl;

  Circle circle2;
  circle2.set_radius(20.0);
  std::cout << "Radius: " << circle2.get_radius() << std::endl;
  std::cout << "Area: " << circle2.get_area() << std::endl;
  std::cout << "Perimeter: " << circle2.get_perimeter() << std::endl;
  return 0;
}

