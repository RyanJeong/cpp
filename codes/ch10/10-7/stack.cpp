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

// copy 10-6
#include <iostream>
#include <string>

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

class Point {
  int x, y;
 public:
  Point(int x = 0, int y = 0) : x(x), y(y) { }  // [NOLINT]
  void show() { std::cout << '(' << x << ',' << y << ')' << std::endl; }
};

int main() {
  MyStack<int*> ipStack;
  int* p = new int[3];
  for (int i = 0; i < 3; ++i)
    p[i] = i * 10;
  ipStack.push(p);

  int* q = ipStack.pop();
  for (int i = 0; i < 3; ++i)
    std::cout << q[i] << ' ';
  std::cout << std::endl;
  delete[] p;

  MyStack<Point> pointStack;
  Point a(2, 3), b;
  pointStack.push(a);
  b = pointStack.pop();
  b.show();

  MyStack<Point*> pStack;
  pStack.push(new Point(10, 20));
  Point* pPoint = pStack.pop();
  pPoint->show();

  MyStack<std::string> stringStack;
  std::string s = "c++";
  stringStack.push(s);
  stringStack.push("java");
  std::cout << stringStack.pop() << ' '
            << stringStack.pop() << std::endl;

  return 0;
}
