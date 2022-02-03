#include <iostream>

int func(int* ptr) {
  return *ptr + 5;
}

int main() {
  double d = 3.14;
  int x = static_cast<int>(d);
  std::cout << x << std::endl;  // 3

  const int val = 10;
  const int* ptr1 = &val;
  // argument of type "const int *" is incompatible with parameter of type
  // "int *"
  // std::cout << func(ptr1);
  int* ptr2 = const_cast<int*>(ptr1);
  std::cout << func(ptr2) << std::endl;  // 15

  int data = 100;
  int* ptr = reinterpret_cast<int*>(data);

  return 0;
}
