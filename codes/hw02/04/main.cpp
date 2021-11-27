#include <iostream>

#include "MyDerivedQueue.h"

int main() {
  MyDerivedQueue q(20);

  std::cout << "Enter 5 integers to insert into the queue." << std::endl;
  for (int i = 0; i < 5; ++i) {
    int n;
    std::cin >> n;
    q.Enqueue(n); // insert an item to the queue
  }
  std::cout << "The capacity of the queue is " << q.GetQueueCapacity()
            << ", and the size of the queue is " << q.GetQueueLength()
            << std::endl;
  std::cout << "Removes all elements stored in the queue." << std::endl;
  while (!q.GetQueueLength()) {
    std::cout << q.Dequeue() << ' '; // remove an item from the queue and print it
  }

  return 0;
}