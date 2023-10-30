#include <iostream>

class MyData {
 public:
  MyData(int value) : data(new int(value)) {}

  MyData& operator=(const MyData& rhs) {
    // 1. Release any resources held by this instance
    delete data;
    // 2. Copy the resources from rhs
    data = new int(*rhs.data);
    // 3. Return *this
    return *this;
  }
  int get_value() const { return *data; }

 private:
  int* data;
};

int main() {
  MyData mc1(42);
  mc1 = mc1;
  // accessing mc1 after self-assignment may result in UB
  std::cout << "mc1's value: "
            << mc1.get_value() << std::endl;

  return 0;
}

