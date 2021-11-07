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

class MyVector{
  int *p;
  int size;
 public:
  explicit MyVector(int n = 100) {
    p = new int[n];
    size = n;
  }
  ~MyVector() { delete[] p; }
  int GetSize() { return this->size; }
};

int main() {
  MyVector *v1, *v2;
  v1 = new MyVector();
  v2 = new MyVector(1024);

  std::cout << v1->GetSize() << std::endl;
  std::cout << v2->GetSize() << std::endl;

  delete v1;
  delete v2;
}
