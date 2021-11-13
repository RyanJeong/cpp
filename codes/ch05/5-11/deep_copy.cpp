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

// copy 5-10
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

int main() {
  Person father(1, "Kitae");
  Person daughter(father);

  std::cout << "daughter 객체 생성 직후 ----" << std::endl;
  father.show();
  daughter.show();

  daughter.changeName("Grace");
  std::cout << "daughter 이름을 Grace로 변경한 후 ----" << std::endl;
  father.show();
  daughter.show();

  return 0;
}
