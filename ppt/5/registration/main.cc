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

#include "registrar.hpp" // [NOLINT]

int main() {
  Registrar registrar;
  Student student1("John");
  Student student2("Mary");
  Student student3("Ann");
  Course course1("CIS101", 4);
  Course course2("CIS102", 3);
  Course course3("CIS103", 3);

  registrar.enroll(student1, course1);
  registrar.enroll(student1, course2);
  registrar.enroll(student2, course1);
  registrar.enroll(student2, course3);
  registrar.enroll(student3, course1);
  student1.print();
  student2.print();
  student3.print();
  course1.print();
  course2.print();
  course3.print();
  return 0;
}

