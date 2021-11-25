#ifndef HW02_02_MY_STACK_
#define HW02_02_MY_STACK_

#include <cstdlib>  // std::srand
#include <ctime>    // std::time

class MyRandom {
 public:
  /**
   * \brief: set seed to intialize random number generator
   */
  static void Seed() { std::srand((unsigned) std::time(0)); }

  /**
   * \brief: return a random integer between 0 and 32,767
   */
  static int NextInt(int min_int = 0, int max_int = 32767);

  /**
   * \brief: return a random alphabet
   */
  static char NextChar();
};

#endif  // HW02_02_MY_STACK_
