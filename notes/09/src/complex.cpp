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
