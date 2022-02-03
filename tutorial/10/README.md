# C++ Tutorial
## 10 - 연산자 오버로딩 2
###### [뒤로가기](/tutorial/#index)
---
### `friend` 키워드
#### `friend` 남용은 구현 디테일은 최대한 숨기는 캡슐화의 원칙과 충돌하므로, 최대한 사용을 지양할 것
* `friend` 키워드로 정의된 클래스 또는 외부 함수는 해당 클래스의 `private` 멤버 변수나 메서드에 접근 가능:
  ```cpp
  class A {
   private:
    void private_func() {}
    int private_num;

    // B 는 A 의 친구!
    friend class B;

    // func 은 A 의 친구!
    friend void func();
  };

  class B {
   public:
    void b() {
      A a;

      // 비록 private 함수의 필드들이지만 `친구`이기 때문에 접근 가능
      a.private_func();
      a.private_num = 2;
    }
  };

  void func() {
    A a;

    // 비록 private 함수의 필드들이지만 `친구`이기 때문에 접근 가능
    a.private_func();
    a.private_num = 2;
  }

  int main() {}
  ```

* `friend`를 이항 연산자 오버로딩에 활용할 수 있음:
  ```cpp
  a = a + "-1.1 + i3.923";  // 1 
  a = "-1.1 + i3.923" + a;  // 2 
  ```
  * `1` 같은 경우, 컴파일러가 `a.operator+("-1.1 + i3.923")`와 같이 처리할 수 있음
  * `2` 같은 경우, 컴파일러가 올바르게 처리할 수 없음
  * 이항 연산자 오버로딩 시 다음과 같은 두 경우를 모두 처리할 수 있어야 함
  * 컴파일러는 어떤 임의의 이항 연산자 `@`에 대해, `a @ b`는 다음 두 방식으로 해석:
  ```cpp
  a.operator@(b);   // 1
  operator@(a, b);  // 2
  ```
  * `1` 같은 경우, `a`의 멤버함수를 호출
  * `2` 같은 경우, 외부에 정의되어 있는 일반 함수 호출
  * `friend` 키워드를 사용하면 `2` 같은 경우도 컴파일러가 올바르게 처리할 수 있음

* <b>이항 연산자 구현 시 중요 규칙</b>:
  * 자기 자신을 반환하지 않는 이항 연산(`+`, `-`, ...)은 <b>`friend` 키워드를 사용해 외부함수로 구현</b>
  * 자기 자신을 반환하는 이항 연산(`+=`, `-=`, ...)은 <b>멤버함수로 구현</b>

* `friend` 키워드를 사용해 이항 연산자를 구현한 예:
  ```cpp
  #include <iostream>
  #include <cstring>

  class Complex {
  private:
    double real_, img_;

    double get_number(const char* str, int from, int to) const;

  public:
    Complex(double real, double img) : real_(real), img_(img) {}
    Complex(const Complex& c) { real_ = c.real_, img_ = c.img_; }
    Complex(const char* str);  // [NOLINT]

    // .... (생략) ....

    friend Complex operator+(const Complex& a, const Complex& b);
    friend Complex operator-(const Complex& a, const Complex& b);
    friend Complex operator*(const Complex& a, const Complex& b);
    friend Complex operator/(const Complex& a, const Complex& b);

    void println() {
      std::cout << "( " << real_ << " , " << img_ << " ) " << std::endl;
    }
  };

  Complex::Complex(const char* str) {
    // 입력 받은 문자열을 분석하여 real 부분과 img 부분을 찾아야 한다.
    // 문자열의 꼴은 다음과 같습니다 "[부호](실수부)(부호)i(허수부)"
    // 이 때 맨 앞의 부호는 생략 가능합니다. (생략시 + 라 가정)

    int begin = 0, end = strlen(str);
    img_ = 0.0;
    real_ = 0.0;

    // 먼저 가장 기준이 되는 'i' 의 위치를 찾는다.
    int pos_i = -1;
    for (int i = 0; i != end; i++) {
      if (str[i] == 'i') {
        pos_i = i;
        break;
      }
    }

    // 만일 'i' 가 없다면 이 수는 실수 뿐이다.
    if (pos_i == -1) {
      real_ = get_number(str, begin, end - 1);
      return;
    }

    // 만일 'i' 가 있다면,  실수부와 허수부를 나누어서 처리하면 된다.
    real_ = get_number(str, begin, pos_i - 1);
    img_ = get_number(str, pos_i + 1, end - 1);

    if (pos_i >= 1 && str[pos_i - 1] == '-') img_ *= -1.0;
  }
  double Complex::get_number(const char* str, int from, int to) const {
    bool minus = false;
    if (from > to) return 0;

    if (str[from] == '-') minus = true;
    if (str[from] == '-' || str[from] == '+') from++;

    double num = 0.0;
    double decimal = 1.0;

    bool integer_part = true;
    for (int i = from; i <= to; i++) {
      if (isdigit(str[i]) && integer_part) {
        num *= 10.0;
        num += (str[i] - '0');
      } else if (str[i] == '.') {
        integer_part = false;
      } else if (isdigit(str[i]) && !integer_part) {
        decimal /= 10.0;
        num += ((str[i] - '0') * decimal);
      } else {
        break;  // 그 이외의 이상한 문자들이 올 경우
      }
    }

    if (minus) num *= -1.0;

    return num;
  }

  Complex operator+(const Complex& a, const Complex& b) {
    Complex temp(a.real_ + b.real_, a.img_ + b.img_);
    return temp;
  }

  Complex operator-(const Complex& a, const Complex& b) {
    Complex temp(a.real_ - b.real_, a.img_ - b.img_);
    return temp;
  }

  Complex operator*(const Complex& a, const Complex& b) {
    Complex temp(a.real_ * b.real_ - a.img_ * b.img_,
        a.real_ * b.img_ + a.img_ * b.real_);
    return temp;
  }

  Complex operator/(const Complex& a, const Complex& b) {
    Complex temp(
        (a.real_ * b.real_ + a.img_ * b.img_) /
        (b.real_ * b.real_ + b.img_ * b.img_),
        (a.img_ * b.real_ - a.real_ * b.img_) /
        (b.real_ * b.real_ + b.img_ * b.img_));
    return temp;
  }

  int main() {
    Complex a(0, 0);
    a = "-1.1 + i3.923" + a;
    a = a + a;

    Complex b(1, 2);
    b = a + b;

    b.println();
  }
  ```

### 입출력 연산자 오버로딩
* `std::cout << a;` 문장은 정확히 아래와 일치:
  ```cpp
  std::cout.operator<<(a);
  ```
* `std::cout`을 사용해 여러 형을 대상으로 출력할 수 있었던 이유는, `iostream` 헤더 파일 내에 아래와 같이 여러 형을 대상으로 연산자 오버로딩이 선언되어 있기 때문:
  ```cpp
  ostream& operator<<(bool val);
  ostream& operator<<(short val);
  ostream& operator<<(unsigned short val);
  ostream& operator<<(int val);
  ostream& operator<<(unsigned int val);
  ostream& operator<<(long val);
  ostream& operator<<(unsigned long val);
  ostream& operator<<(float val);
  ostream& operator<<(double val);
  ostream& operator<<(long double val);
  ostream& operator<<(void* val);
  ```
* 입출력 연산자 오버로딩은 레퍼런스를 반환해야 하며, 이유는 다음과 같은 문장을 올바르게 처리하기 위함:
  ```cpp
  std::cout << "a 의 값은 : " << a << " 이다. " << std::endl;
  ```

* `friend`를 사용한 입출력 연산자 오버로딩:
  ```cpp
  #include <iostream>
  #include <cstring>

  class Complex {
  private:
    double real_, img_;

    double get_number(const char* str, int from, int to) const;

  public:
    Complex(double real, double img) : real_(real), img_(img) {}
    Complex(const Complex& c) { real_ = c.real_, img_ = c.img_; }
    Complex(const char* str);  // [NOLINT]

    Complex& operator+=(const Complex& c);
    Complex& operator-=(const Complex& c);
    Complex& operator*=(const Complex& c);
    Complex& operator/=(const Complex& c);

    Complex& operator=(const Complex& c);

    friend Complex operator+(const Complex& a, const Complex& b);
    friend Complex operator-(const Complex& a, const Complex& b);
    friend Complex operator*(const Complex& a, const Complex& b);
    friend Complex operator/(const Complex& a, const Complex& b);
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
    friend std::istream& operator>>(std::istream& is, Complex& c);
  };

  Complex::Complex(const char* str) {
    // 입력 받은 문자열을 분석하여 real 부분과 img 부분을 찾아야 한다.
    // 문자열의 꼴은 다음과 같습니다 "[부호](실수부)(부호)i(허수부)"
    // 이 때 맨 앞의 부호는 생략 가능합니다. (생략시 + 라 가정)

    int begin = 0, end = strlen(str);
    img_ = 0.0;
    real_ = 0.0;

    // 먼저 가장 기준이 되는 'i' 의 위치를 찾는다.
    int pos_i = -1;
    for (int i = 0; i != end; i++) {
      if (str[i] == 'i') {
        pos_i = i;
        break;
      }
    }

    // 만일 'i' 가 없다면 이 수는 실수 뿐이다.
    if (pos_i == -1) {
      real_ = get_number(str, begin, end - 1);
      return;
    }

    // 만일 'i' 가 있다면,  실수부와 허수부를 나누어서 처리하면 된다.
    real_ = get_number(str, begin, pos_i - 1);
    img_ = get_number(str, pos_i + 1, end - 1);

    if (pos_i >= 1 && str[pos_i - 1] == '-') img_ *= -1.0;
  }
  double Complex::get_number(const char* str, int from, int to) const {
    bool minus = false;
    if (from > to) return 0;

    if (str[from] == '-') minus = true;
    if (str[from] == '-' || str[from] == '+') from++;

    double num = 0.0;
    double decimal = 1.0;

    bool integer_part = true;
    for (int i = from; i <= to; i++) {
      if (isdigit(str[i]) && integer_part) {
        num *= 10.0;
        num += (str[i] - '0');
      } else if (str[i] == '.') {
        integer_part = false;
      } else if (isdigit(str[i]) && !integer_part) {
        decimal /= 10.0;
        num += ((str[i] - '0') * decimal);
      } else {
        break;  // 그 이외의 이상한 문자들이 올 경우
      }
    }

    if (minus) num *= -1.0;

    return num;
  }

  Complex& Complex::operator+=(const Complex& c) {
    (*this) = (*this) + c;
    return *this;
  }

  Complex& Complex::operator-=(const Complex& c) {
    (*this) = (*this) - c;
    return *this;
  }

  Complex& Complex::operator*=(const Complex& c) {
    (*this) = (*this) * c;
    return *this;
  }

  Complex& Complex::operator/=(const Complex& c) {
    (*this) = (*this) / c;
    return *this;
  }

  Complex& Complex::operator=(const Complex& c) {
    real_ = c.real_;
    img_ = c.img_;
    return *this;
  }

  Complex operator+(const Complex& a, const Complex& b) {
    Complex temp(a.real_ + b.real_, a.img_ + b.img_);
    return temp;
  }

  Complex operator-(const Complex& a, const Complex& b) {
    Complex temp(a.real_ - b.real_, a.img_ - b.img_);
    return temp;
  }

  Complex operator*(const Complex& a, const Complex& b) {
    Complex temp(a.real_ * b.real_ - a.img_ * b.img_,
        a.real_ * b.img_ + a.img_ * b.real_);
    return temp;
  }

  Complex operator/(const Complex& a, const Complex& b) {
    Complex temp(
        (a.real_ * b.real_ + a.img_ * b.img_) /
        (b.real_ * b.real_ + b.img_ * b.img_),
        (a.img_ * b.real_ - a.real_ * b.img_) /
        (b.real_ * b.real_ + b.img_ * b.img_));
    return temp;
  }

  std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << "( " << c.real_ << " , " << c.img_ << " ) ";
    return os;
  }

  std::istream& operator>>(std::istream& is, Complex& c) {
    is >> c.real_ >> c.img_;
    return is;
  }

  int main() {
    Complex a(0, 0);
    std::cin >> a;
    a += a;

    Complex b(1, 2);
    b = a + b;
    std::cout << b << std::endl;

    return 0;
  }

  ```
* `friend` 키워드를 사용하지 않는 방법:
  ```cpp
  #include <iostream>
  #include <cstring>

  class Complex {
  private:
    double real_, img_;

    double get_number(const char* str, int from, int to) const;

  public:
    Complex(double real, double img) : real_(real), img_(img) {}
    Complex(const Complex& c) { real_ = c.real_, img_ = c.img_; }
    Complex(const char* str);  // [NOLINT]

    // .... (생략) ....

    std::ostream& print(std::ostream& os) const;
    std::istream& input(std::istream& is);
  };

  // .... (생략) ....

  std::ostream& Complex::print(std::ostream& os) const {
    os << "( " << real_ << " , " << img_ << " ) ";
    return os;
  }
  std::istream& Complex::input(std::istream& is) {
    is >> real_ >> img_;
    return is;
  }

  std::ostream& operator<<(std::ostream& os, const Complex& c) {
    return c.print(os);
  }
  std::istream& operator>>(std::istream& is, Complex& c) {
    return c.input(is);
  }

  ```

### 첨자 연산자 오버로딩
* 매개변수는 인덱스를 표현하기 위해 정수형을 사용하며, 반환형은 레퍼런스임:
* 레퍼런스를 사용하는 이유는, 첨자 연산 결과를 좌측, 우측 양쪽에서 같이 사용할 수 있도록 하기 위함:
  ```cpp
  str[10] = 'c';
  char c = str[5];
  ```

* 문자열의 첨자 연산자 오버로딩:
  ```cpp
  #include <iostream>
  #include <string.h>  // [NOLINT]

  class MyString {
  public:
    MyString(const MyString& m_str);  // [NOLINT]
    MyString(const char* str);        // [NOLINT]
    MyString(char c);                 // [NOLINT]
    ~MyString(void);

    int length(void) const;
    void print(void) const;
    void println(void) const;

    char& operator[](const int index);

  private:
    char* content_;
    int length_;
    int capacity_;
  };

  MyString::MyString(const MyString& m_str) {
    length_ = m_str.length_;
    capacity_ = length_;
    content_ = new char[length_];

    // strcpy(content_,m_str.content_); not terminated with 'null' character
    for (int i = 0; i < length_; ++i)
      content_[i] = m_str.content_[i];
  }

  MyString::MyString(const char* str) {
    length_ = strlen(str);
    capacity_ = length_;
    content_ = new char[length_];
    strcpy(content_, str);  // [NOLINT]
  }

  MyString::MyString(char c) {
    length_ = 1;
    capacity_ = length_;
    content_ = new char[length_];
    *content_ = c;
  }

  MyString::~MyString(void) {
    delete[] content_;
  }

  int MyString::length(void) const {
    return length_;
  }

  void MyString::print(void) const {
    for (int i = 0; i < length_; ++i)
      std::cout << content_[i];
  }

  void MyString::println(void) const {
    print();
    std::cout << std::endl;
  }

  char& MyString::operator[](const int index) { 
    return content_[index];
  }

  int main() {
    MyString str{"Hello, world!"};
    str[7] = 'W';
    str.println();

    return 0;
  }

  ```

### 타입 변환 연산자 오버로딩
* 기본 자료형을 객체로써 사용해야 할 경우, 이를 클래스로 포장해서 각각의 자료형을 객체로 사용해야 함
* 기본 자료형을 객체로써 사용할 수 있도록 하는 클래스를 wrapper 클래스라 함:
  ```cpp
  class Int
  {
    int data_;
    // some other data

   public:
    Int(int data) : data_(data) {}
    Int(const Int& i) : data_(i.data) {}
  };

  ```
  * `Int`를 `int`처럼 사용하려면 연산자 오버로딩을 <b>직접, 일일이</b> 구현해야 할까?

* 타입 변환 연산자는 다음과 같이 정의:
  ```cpp
  operator (TYPE)()
  ```
  * 생성자 혹은 소멸자처럼 반환형을 사용하지 않음

  ```cpp
  operator (int)()
  ```
  * 객체를 `int` 형으로써 간주

  ```cpp
  operator int() { return data; }
  ```
  * 객체를 대상으로 `읽는` 연산을 할 경우, `data`를 `int`형으로 변환 후 반환
  * 객체를 대상으로 `댕립` 연산을 할 경우, 디폴트 대입 연산자가 타입 변환 연산자를 참고해 적절히 변환 후 처리

* `Int` wrapper 클래스에 타입 변환 연산자를 사용:
  ```cpp
  #include <iostream>

  class Int {
    int data;
    // some other data

  public:
    Int(int data) : data(data) {}
    Int(const Int& i) : data(i.data) {}

    operator int() { return data; }
  };
  int main() {
    Int x = 3;
    int a = x + 4;

    x = a * 2 + x + 4;
    std::cout << x << std::endl;
  }
  ```

* 여러 개의 타입 변환 연산자:
  ```cpp
  #include <iostream>

  class Test {
  private:
    char c_;
    int i_;
    double d_;

  public:
    Test(char c, int i, double d) : c_(c), i_(i), d_(d) { }
    operator char() const;
    operator int() const;
    operator double() const;
  };

  Test::operator char() const {
    std::cout << "operator char()" << std::endl;
    return c_;
  }

  Test::operator int() const {
    std::cout << "operator int()" << std::endl;
    return i_;
  }

  Test::operator double() const {
    std::cout << "operator double()" << std::endl;
    return d_;
  }

  int main() {
    Test test('x', 16, 3.14);
    char c = test;
    int i = test;
    double d = test;

    std::cout << c << ' ' << i << ' ' << d << std::endl;

    return 0;
  }

  ```

### 증감 연산자 오버로딩
* 전위 증감 연산자와 후위 증감 연산자는 매개변수 형태에 따라 구분:
  ```cpp
  operator++();       // 전위 증가
  operator--();       // 전위 감소
  operator++(int x);  // 후위 증가
  operator--(int x);  // 후위 감소
  ```
* <b>전위 증감 연산자의 반환형은 자기 자신의 레퍼런스, 후위 증감 연산자의 반환형은 값이 바뀌기 전의 객체를 반환해야 함</b>:
  ```cpp
  #include <iostream>

  class Test {
    int data_;

  public:
    Test(int data) : data_(data) {}  // [NOLINT]
    Test(const Test& t) : data_(t.data_) {}

    Test& operator++() {
      data_++;
      std::cout << "전위 증감 연산자" << std::endl;
      return *this;
    }

    // 전위 증감과 후위 증감에 차이를 두기 위해 후위 증감의 경우 인자로 int 를
    // 받지만 실제로는 아무것도 전달되지 않는다.
    Test operator++(int) {
      Test temp(*this);
      data_++;
      std::cout << "후위 증감 연산자" << std::endl;
      return temp;
    }

    int get_x() const {
      return data_;
    }
  };

  void func(const Test& t) {
    std::cout << "x : " << t.get_x() << std::endl;
  }

  int main() {
    Test t(3);

    func(++t);  // 4
    func(t++);  // 4 가 출력됨
    std::cout << "x : " << t.get_x() << std::endl;
  }

  ```

### [What are the basic rules and idioms for operator overloading?](https://stackoverflow.com/questions/4421706/what-are-the-basic-rules-and-idioms-for-operator-overloading)

###### [처음으로](#c-tutorial)
###### [뒤로가기](/tutorial/#index)
---