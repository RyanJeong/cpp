#include "MyBaseArray.h"

class MyDerivedQueue : MyBaseArray {
  int length;
 public:
  explicit MyDerivedQueue(int n = 100) : MyBaseArray(n) { }
  void Enqueue(int n);
  int Dequeue();
  int GetQueueCapacity();
  int GetQueueLength() {
    return this->length;
  }
};