#include <iostream>

// tail recursive factorial
int tail_recursive(int n, int result = 1) {
  return !n ? result : tail_recursive(n - 1, n * result);
}

// not tail recursive factorial
int not_tail_recursive(int n) {
  return !n ? 1 : n * not_tail_recursive(n - 1);
}

int main() {
  int n;
  std::cin >> n;

  std::cout << tail_recursive(n) << std::endl;
  std::cout << not_tail_recursive(n) << std::endl;

  return 0;
}

