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

// TODO pop => empty, top, pop
template <typename T>
class MyStack {
  int tos;
  T data[100];
 public:
  MyStack() : tos(-1) { }
  void push(T element);
  T pop();
};

template <typename T>
void MyStack<T>::push(T element) {
  if (tos == 99) {
    std::cout << "stack full";

    return;
  }
  data[++tos] = element;
}

template <typename T>
T MyStack<T>::pop() {
  T res;
  if (tos == -1) {
    std::cout << "stack empty";

    return 0;
  }
  res = data[tos--];

  return res;
}

int main() {
  MyStack<int> iStack;
  iStack.push(3);
  std::cout << iStack.pop() << std::endl;

  MyStack<double> dStack;
  dStack.push(3.5);
  std::cout << dStack.pop() << std::endl;

  MyStack<char> *p = new MyStack<char>();
  p->push('a');
  std::cout << p->pop() << std::endl;
  delete p;

  return 0;
}
