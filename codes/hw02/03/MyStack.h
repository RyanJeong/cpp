#ifndef HW02_01_MY_STACK
#define HW02_01_MY_STACK

class MyStack {
  int *p;       // a pointer that points to memory stores stack values
  int max_size; // max size of the stack
  int top_idx;  // an index that indecates the top element in the stack
 public:
  explicit MyStack(int max_size);
  MyStack(const MyStack& my_stack);
  ~MyStack();
  /**
   * \brief: push n into the stack
   *         return false if the stack is full, otherwise true
   */
  bool Push(const int& n);

  /**
   * \brief: pop the top element and store the popped value to n
   *         return false if the stack is empty, otherwise true
   */
  bool Pop(int* n);
  
  MyStack& operator<<(const int& n);
  void operator>>(int& tmp);
  bool operator!(void);
};

#endif  // HW02_01_MY_STACK