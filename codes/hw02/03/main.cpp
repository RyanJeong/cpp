#include <iostream>

#include "MyStack.h"

int main() {
  MyStack s(20);
  s << 20 << 30 << 40;
  while (true) {
    if (!s) {
      break;
    }
    int tmp;
    s >> tmp;
    std::cout << tmp << ' ';
  }

  return 0;
}