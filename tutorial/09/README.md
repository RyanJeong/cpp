# C++ Tutorial
## 09 - 연산자 오버로딩 1
###### [뒤로가기](/tutorial/#index)
---
### 연산자 오버로딩
* C++에서는 연산자 오버로딩을 통해 사용자 정의 연산자를 사용할 수 있음:
  * 산술 연산자(`+`, `-`, `*`, ...)
  * 축약형 연산자(`+=`, `-=`, ...)
  * 비교 연산자(`>=`, `==`, ...)
  * 논리 연산자(`&&`, `||`, ...)
  * 멤버 선택 연산자(`->`, `*`(dereference operator), ...)
  * 증감 연산자(`++`, `--`)
  * 배열 연산자(`[]`)
  * 함수 호출 연산자(`()`)
* <b>The operators `::`(scope resolution), `.`(member access), `.*`(member access through pointer to member), and `?:`(ternary conditional) cannot be overloaded.</b>
  * `.*`:
    ```cpp
    my_chair.color->printColor();
    (*(my_chair.color)).printColor(); //same thing
    ```

### `==` 연산자 오버로딩
* `==` 연산자의 반환형은 `bool`:
  ```cpp
  #include <iostream>
  #include <string.h>  // [NOLINT]

  class MyString {
  public:
    MyString(const MyString& m_str);  // [NOLINT]
    MyString(const char* str);        // [NOLINT]
    MyString(char c);                 // [NOLINT]
    ~MyString(void);

    int compare(const MyString& m_str) const;
    bool operator==(const MyString& m_str) const;

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

  int MyString::compare(const MyString& m_str) const {
    if (length_ != m_str.length_) {
      return ((length_ > m_str.length_) ? 1 : -1);
    } else {  // length_ == m_str.length_
      for (int i = 0; i < length_; ++i) {
        if (content_[i] != m_str.content_[i]) {
          return ((content_[i] > m_str.content_[i]) ? 1 : -1);
        }
      }
    }

    return 0;
  }

  bool MyString::operator==(const MyString& m_str) const {
    return !compare(m_str);
  }

  int main() {
    MyString str1 = "Hello";
    MyString str2 = "Hello";
    std::cout << ((str1 == str2) ? "Same!" : "Not same!") << std::endl;  // Same!

    return 0;
  }

  ```

### 산술 연산자 오버로딩
* 반환형은 클래스의 레퍼런스가 아닌 <b>클래스</b>를 반환해야 함:
  ```cpp
  #include <iostream>

  class Complex {
  private:
    double real_, img_;

  public:
    Complex(const double& real, const double& img) : real_(real), img_(img) {}
    Complex(const Complex& c) { real_ = c.real_, img_ = c.img_; }

    Complex operator+(const Complex& c) const;
    Complex operator-(const Complex& c) const;
    Complex operator*(const Complex& c) const;
    Complex operator/(const Complex& c) const;

    void println();
  };

  Complex Complex::operator+(const Complex& c) const {
    Complex temp(real_ + c.real_, img_ + c.img_);
    return temp;
  }
  Complex Complex::operator-(const Complex& c) const {
    Complex temp(real_ - c.real_, img_ - c.img_);
    return temp;
  }
  Complex Complex::operator*(const Complex& c) const {
    Complex temp(real_ * c.real_ - img_ * c.img_,
        real_ * c.img_ + img_ * c.real_);
    return temp;
  }
  Complex Complex::operator/(const Complex& c) const {
    Complex temp(
        (real_ * c.real_ + img_ * c.img_) /
        (c.real_ * c.real_ + c.img_ * c.img_),
        (img_ * c.real_ - real_ * c.img_) /
        (c.real_ * c.real_ + c.img_ * c.img_));
    return temp;
  }

  void Complex::println() {
    std::cout << "( " << real_ << " , " << img_ << " ) " << std::endl;
  }

  int main() {
    Complex a(1.0, 2.0);
    Complex b(3.0, -2.0);

    Complex c = a * b;  // The compiler converts it to `a.operator*(b)`
    c.println();

    return 0;
  }

  ```
* 산술 연산자 오버로딩 시 레퍼런스를 사용하지 않는 이유:
  ```cpp
  Complex& operator+(const Complex& c) {
    real += c.real;
    img += c.img;
    return *this;
  }

  // .... (생략) ....

  Complex a = b + c + b;  // 계산 결과 기대값은 `a = 2b + c`

  ```
  * 위 계산식은 `(b.operator+(c)).operator+(b)`와 같으며, `operator+`의 반환형이 레퍼런스라면 `b.operator+(c)`를 처리한 결과의 `b`의 값은 `b + c`로 <b>갱신</b>
  * `b`의 값이 새로 갱신된 후에 `.operator+(b)`를 다시 하게 된다면, `(b + c) + (b + c)`가 됨
  * <b>이러한 계산 오류를 예방하기 위해, 산술 연산자 오버로딩의 경우 반드시 값을 반환해야 함</b>

### 대입 연산자 오버로딩
* 클래스 대입 연산자가 정의되어 있지 않다면, 컴파일러는 암시적으로 디폴트 대입 연산자(default assignment operator)를 클래스 내에 생성
  * 디폴트 복사 생성자처럼 얕은 복사 수행
  * <b>깊은 복사가 필요한 클래스라면, 대입 연산 시 깊은 복사를 수행할 수 있도록 반드시 대입 연사자 함수를 직접 정의해야 함</b>
* 반환형은 클래스가 아닌 <b>클래스의 레퍼런스</b>를 반환:
  ```cpp
  Complex& operator=(const Complex& c);

  Complex& Complex::operator=(const Complex& c) {
    real_ = c.real_;
    img_ = c.img_;
    return *this;
  }
  ```
  * 레퍼런스를 반환해야 하는 이유는 다음 문장이 올바르게 처리되어야 하기 때문:
    ```cpp
    Complex a(1.0, 2.0);
    Complex b(3.0, -2.0);
    Complex c(0.0, 0.0);
    a = b = c;
    ```
    * `b = c`의 결과가 `b`가 되어야 `a = b`의 결과가 올바르게 처리됨
  * 레퍼런스를 반환하지 않으면, 매 연산마다 불필요한 복사 연산(임시 객체 생성)이 수행됨

* 대입 사칙연산(`+=`, `-=`, ...)들도 레퍼런스를 반환해야 함:
  ```cpp
  Complex& operator+=(const Complex& c);
  Complex& operator-=(const Complex& c);
  Complex& operator*=(const Complex& c);
  Complex& operator/=(const Complex& c);

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
  ```

* 연산자 오버로딩을 활용한 복소수 클래스:
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

    Complex operator+(const Complex& c) const;
    Complex operator-(const Complex& c) const;
    Complex operator*(const Complex& c) const;
    Complex operator/(const Complex& c) const;

    Complex& operator+=(const Complex& c);
    Complex& operator-=(const Complex& c);
    Complex& operator*=(const Complex& c);
    Complex& operator/=(const Complex& c);

    Complex& operator=(const Complex& c);

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

    if (pos_i >= 1 && str[pos_i - 1] == '-')
      img_ *= -1.0;
  }
  double Complex::get_number(const char* str, int from, int to) const {
    bool minus = false;
    if (from > to)
      return 0;

    if (str[from] == '-')
      minus = true;
    if (str[from] == '-' || str[from] == '+')
      from++;

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

    if (minus)
      num *= -1.0;

    return num;
  }
  Complex Complex::operator+(const Complex& c) const {
    Complex temp(real_ + c.real_, img_ + c.img_);
    return temp;
  }
  Complex Complex::operator-(const Complex& c) const {
    Complex temp(real_ - c.real_, img_ - c.img_);
    return temp;
  }
  Complex Complex::operator*(const Complex& c) const {
    Complex temp(real_ * c.real_ - img_ * c.img_,
        real_ * c.img_ + img_ * c.real_);
    return temp;
  }
  Complex Complex::operator/(const Complex& c) const {
    Complex temp(
        (real_ * c.real_ + img_ * c.img_) /
        (c.real_ * c.real_ + c.img_ * c.img_),
        (img_ * c.real_ - real_ * c.img_) /
        (c.real_ * c.real_ + c.img_ * c.img_));
    return temp;
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

  int main() {
    Complex a(0, 0);
    // a + "-1.1 + i3.923"
    // a.operator+("-1.1 + i3.923");
    // 이때, operator+ 함수의 매개변수는 const Complex& 형
    // 컴파일러는 오버로딩된 다른 생성자를 찾음:
    //    Complex(const char* str);
    // 따라서, a.operator+(Complex("-1.1 + i3.923"))로 처리:
    //    "-1.1 + i3.923"은 literal이기 때문에, const char* 매개변수에
    //    전달할 수 있음
    a = a + "-1.1 + i3.923";
    a.println();
    a = a - "1.2 -i1.823";
    a.println();
    a = a * "2.3+i22";
    a.println();
    a = a / "-12+i55";
    a.println();
  }
  ```

###### [처음으로](#c-tutorial)
###### [뒤로가기](/tutorial/#index)
---