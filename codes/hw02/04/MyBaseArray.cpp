#include "MyBaseArray.h"

MyBaseArray::MyBaseArray(int cap) {
  this->capacity = cap;
  this->p_memory = new int[cap];
}

MyBaseArray::~MyBaseArray() {
  delete[] this->p_memory;
}

void MyBaseArray::Put(int index, int value) {
  this->p_memory[index] = value;
}

int MyBaseArray::Get(int index) {
  return this->p_memory[index];
}

int MyBaseArray::GetCapacity() {
  return this->capacity;
}
