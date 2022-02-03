  #include <iostream>

  class Int {
    int data_;
    // some other data

   public:
    Int(int data) : data_(data) {}  // [NOLINT]
    Int(const Int& i) : data_(i.data_) {}

    operator int() { return data_; }
  };
  int main() {
    Int x = 3;
    int a = x + 4;

    x = a * 2 + x + 4;
    std::cout << x << std::endl;
  }
