#include <iostream>
#include <cstdlib>  // std::srand
#include <ctime>    // std::time

#include "MyRandom.h"

int main() {
  MyRandom::Seed();
  std::cout << MyRandom::NextChar() << std::endl;

  return 0;
}