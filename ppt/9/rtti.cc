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
#include <typeinfo>  // type_info, typeid

template <typename T>
class MyClass {};

int main() {
  MyClass<int> obj1;
  const std::type_info& type1 = typeid(obj1);
  MyClass<double> obj2;
  const std::type_info& type2 = typeid(obj2);

  std::cout << "Type of obj1: " << type1.name() << std::endl;
  std::cout << "Type of obj2: " << type2.name() << std::endl;
  if (type1 == type2)
    std::cout << "obj1 and obj2 have the same type." << std::endl;
  else
    std::cout << "obj1 and obj2 have different types." << std::endl;
  return 0;
}

