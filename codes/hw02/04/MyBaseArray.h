#ifndef HW02_04_MY_BASE_ARRAY
#define HW02_04_MY_BASE_ARRAY

class MyBaseArray {
 private:
  int capacity;   // a size of the array
  int* p_memory;  // a pointer that points to memory stores array values
 protected:
  explicit MyBaseArray(int cap = 100);
  ~MyBaseArray();
  void Put(int index, int value);
  int Get(int index);
  int GetCapacity();
};

#endif  // HW02_01_MY_BASE_ARRAY
