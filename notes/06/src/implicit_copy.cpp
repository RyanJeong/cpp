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
#include <cstring>

class Person {
  char* name;
  int id;

 public:
  Person(int id, const char* name);
  Person(const Person& person);
  ~Person();
  void changeName(const char *name);
  void show() { std::cout << id << ',' << name << std::endl; }
};

inline Person::Person(int id, const char* name) {
  this->id = id;
  int len = strlen(name);
  this->name = new char[len+1];
  strcpy(this->name, name); // [NOLINT]
}

inline Person::Person(const Person& person)
    : Person(person.id, person.name) {
  std::cout << "복사 생성자 실행. 원본 객체의 이름 "
            << this->name << std::endl;
}

inline Person::~Person() {
  if (name) {
    delete [] name;
  }
}

inline void Person::changeName(const char* name) {
  if (strlen(name) <= strlen(this->name)) {
    strcpy(this->name, name); // [NOLINT]
  }
}

inline void f(Person person) { person.changeName("dummy"); }

inline Person g() {
  Person mother(2, "Jane");

  return mother;
}

int main() {
  Person father(1, "Kitae");
  std::cout << "Person son = father;" << std::endl;
  // 복사 생성자 호출
  Person son = father;
  std::cout << "f(father);" << std::endl;

  // 복사 생성자 호출
  f(father);
  std::cout << "g();" << std::endl;

  // 복사 생성자 호출
  // copy elision
  // "-fno-elide-constructors"
  g();

  return 0;
}
