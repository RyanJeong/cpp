#include <iostream>

#include "MyStack.h"

int main() {
  MyStack s(20);
  s.Push(34);
  s.Push(56);
  MyStack t = s;
  t.Push(12);

  int n;
  s.Pop(&n);
  std::cout << "the popped value of stack s: " << n << std::endl;
  t.Pop(&n);
  std::cout << "the popped value of stack t: " << n << std::endl;

  return 0;
}