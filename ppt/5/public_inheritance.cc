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

/*
assert is a macro and defined in <cassert>. And assert has no std namespace so
when you use assert, use assert only instead of std::assert:

#ifdef NDEBUG
#  define assert(condition) ((void)0)
#else
#  define assert(condition)
#endif
*/

#include <iostream>
#include <cassert>

class Person {
  int64_t id_;

 public:
  void set_id(int64_t id);
  int64_t get_id() const;
};

void Person::set_id(int64_t id) {
  id_ = id;
  assert(id_ >= 1e8 && id_ < 1e9);
}

int64_t Person::get_id() const { return id_; }

class Student : public Person {
  double gpa_;

 public:
  void set_gpa(double gpa);
  double get_gpa() const;
};

void Student::set_gpa(double gpa) {
  gpa_ = gpa;
  assert(gpa_ >=0 && gpa_ <= 4.0);
}

double Student::get_gpa() const { return gpa_; }

int main() {
  Person person;
  person.set_id(123456789L);
  std::cout << "Person Information: " << std::endl;
  std::cout << "Person’s ID: " << person.get_id();
  std::cout << std::endl << std::endl;
  Student student;
  student.set_id(987654321L);
  student.set_gpa(3.9);
  std::cout << "Student Information: " << std::endl;
  std::cout << "Student’s ID: " << student.get_id() << std::endl;
  std::cout << "Student’s GPA: " << student.get_gpa();
  return 0;
}

