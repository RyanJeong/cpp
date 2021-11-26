#include <iostream>

#include "MyStack.h"

int main() {
  MyStack s(20);
  s << 20 << 30 << 40;  // the order of push is 20, 30, 40.
  while (true) {
    if (!s) {  // check if the stack is empty
      break;
    }
    int tmp;
    s >> tmp;  // pop the top element and store the popped value to tmp
    std::cout << tmp << ' ';
  }

  return 0;
}