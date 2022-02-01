# C++ Tutorial
## 05 - 객체지향프로그래밍 2
### 오버로딩(<i>overloading</i>)
* 같은 이름의 함수를 여러 개 정의해 사용하는 것(overload):
  ```cpp
  #include <iostream>

  void print(int x) { std::cout << "int: " << x << std::endl; }
  void print(char x) { std::cout << "char: " << x << std::endl; }
  void print(double x) { std::cout << "double: " << x << std::endl; }

  int main() {
    int a = 5;
    char b = 'a';
    double c = 3.14;

    print(a);  // int: 5
    print(b);  // char: 'a'
    print(c);  // double: 3.14

    return 0;
  }
  ```
  * <b>컴파일러가 전달인자의 형태를 보고 적합한 형태의 함수를 찾아 호출</b>

### [오버로딩 과정(The argument matching sequence)](https://www.learncpp.com/cpp-tutorial/function-overload-resolution-and-ambiguous-matches/):
1. 호출 시 전달인자와 함수의 매개변수가 정확히 일치하는 함수를 찾는다.
2. 1번 단계에서 함수를 찾지 못했다면, 승격(promotion)을 통해 일치하는 함수를 찾는다:<br>
    1. `signed char` or `signed short` can be converted to `int`<br>
    2. `unsigned char` or `unsigned short` can be converted to `int` if it can hold its entire value range, and `unsigned int` otherwise<br>
    (<b>IP16L32</b>에서는 `int`형으로 `unsigned short`를 수용하지 못할 수 있음)<br>
    3. `float` can be converted to `double`<br>
    4. an unscoped enumeration type whose underlying type is not fixed can be converted to the <b>first type from the following list able to hold their entire value range</b>: `int`, `unsigned int`, `long`, `unsigned long`, `long long`, or `unsigned long long`, extended integer types with higher conversion rank (in rank order, signed given preference over unsigned)<br>
3. 승격을 통해서도 함수를 찾지 못했다면, 표준 변환(standard conversion)을 통해 일치하는 함수를 찾는다.<br>
    * 기존의 숫자 형은 다른 숫자 형으로 변환 (ex. `double` -> `char`, `short`, ...)<br>
    * 열거형 또한 다른 숫자 형으로 변환 (ex. `enum` -> `int`, `int` -> `float`, `double`, ...)<br>
    * 0은 포인터 형 및 숫자 형과 일치하도록 변환 (ex. 0 -> `char*` or `float`)<br>
    * 포인터는 `void` 형 포인터와 일치하도록 변환<br>
4. 표준 변환을 통해서도 함수를 찾지 못했다면, 사용자 정의 변환(user-defined conversion)을 통해 일치하는 함수를 찾는다.
5. 위 과정을 통해 컴파일러가 적절한 함수를 찾지 못한다면, 오류 발생(ambiguous)

* 승격을 통해 함수 호출:
  ```cpp
  #include <iostream>

  void print(int x) { std::cout << "int: " << x << std::endl; }
  void print(double x) { std::cout << "double: " << x << std::endl; }

  int main() {
    int a = 5;
    char b = 'a';
    double c = 3.14;

    print(a);  // call print(int x)
    print(b);  // call print(int x); char can be converted to int
    print(c);  // call print(double x)

    return 0;
  }
  ```

* 표준 변환을 통해 함수를 호출할 경우 발생할 수 있는 모호성:
  ```cpp
  #include <iostream>

  void print(int x) { std::cout << "int: " << x << std::endl; }
  void print(char x) { std::cout << "char: " << x << std::endl; }

  int main() {
    int a = 5;
    char b = 'a';
    double c = 3.14;

    print(a);  // call print(int x)
    print(b);  // call print(char x)
    print(c);  // ERROR; ambiguous call to overloaded function

    return 0;
  }
  ```
  * 오버로드된 함수 중 `double` 형을 매개변수로 받는 함수가 없기 때문에 적절한 함수를 결정해야 함
  * 승격을 시도했으나, `double` 형에 대한 승격 내용은 없으므로 표준 변환 단계로 이동
  * 표준 변환을 시도하여 `double`을 다른 숫자 형으로의 변환
    * 표준 변환을 통해 `double`은 `int`, `char` 둘 다 변환될 수 있음
    * 어떠한 함수를 호출해야 하는지 모호한(ambiguous) 상황이므로 오류 발생

### 생성자(constructor)
* 인스턴스 생성 시 <b>자동으로 호출</b>되는 함수
* 클래스로부터 인스턴스를 생성함과 동시에 <b>초기화</b>하기 위해 사용
* `new`를 사용해 객체를 동적으로 생성할 경우 <b>생성자 자동 호출</b>
* 초기화하지 않은 지역 변수는 내부에 쓰레기 값이 들어 있으며, 개발자가 일으킬 수 있는 초기화 누락 문제를 해결할 수 있음:
  ```c++
  class Date {
   public:
    // 생성자는 객체를 초기화하는 역할만을 수행하므로
    // 별도의 반환값이 없음
    Date(int y, int m, int d) { year_ = y; month_ = m; day_ = d; } 
    void set_date(int y, int m, int d);
    void add_day(int num);
    void add_month(int num);
    void add_year(int num);
    void show_date();

   private:
    bool is_leap_year();
    int year_;
    int month_;
    int day_;
  };

  int main() {
    Date day1(2021, 9, 2);         // implicit
    Date day2 = Date(2021, 9, 2);  // explicit

    return 0;
  }

  ```

### 디폴트 생성자 (default constructor)
* 클래스에서 사용자가 어떠한 생성자도 명시적으로 정의하지 않았다면 <b>컴파일러가 자동으로 생성</b>하는 생성자
  * 아무 동작도 하지 않음
* 다음과 같이 직접 디폴트 생성자를 정의할 수 있음:
  ```cpp
  class Date {
   public:
    Date() { year_ = 2021; month_ = 7; day_ = 12; }
    void set_date(int y, int m, int d);
    void add_day(int num);
    void add_month(int num);
    void add_year(int num);
    void show_date();

   private:
    bool is_leap_year();
    int year_;
    int month_;
    int day_;
  };

  int main() {
    Date date1;           // implicit
    Date date2 = Date();  // explicit

    return 0;
  }

  ```
* 클래스에 생성자가 표현되어 있지 않을 때, 개발자가 생성자를 실수로 누락한 것인지 컴파일러가 만들어 주는 디폴트 생성자를 사용하기 위해 고의로 생략한 것인지 작성자의 의도를 알기에 모호함
* `default` 키워드를 사용하면 <b>명시적으로 디폴트 생성자를 사용하겠다는 의미</b>:
  ```cpp
  class Foo {
   public:
    Foo() = default;
  };
  ```
* 사용자가 정의한 생성자(user-declared constructor)가 있는 경우 디폴트 생성자는 생성되지 않으며, 이때 `default` 키워드를 사용하면 디폴트 생성자를 생성할 수 있음

### 생성자 오버로딩
* 생성자는 함수와 마찬가지이며, 따라서 오버로딩을 적용할 수 있음:
  ```cpp
  #include <iostream>

  class Date {
  public:
    Date();
    Date(int y, int m, int d);
    void set_date(int y, int m, int d);
    void add_day(int num);
    void add_month(int num);
    void add_year(int num);
    void show_date();
  private:
    bool is_leap_year();
    int year_;
    int month_;
    int day_;
  };

  Date::Date() : year_{2021}, month_{9}, day_{2} {}
  Date::Date(int y, int m, int d) : year_{y}, month_{m}, day_{d} {}

  void Date::set_date(int y, int m, int d) {
    if (y < 0 || m < 0 || d < 0) {
      year_ = 0;
      month_ = 0;
      day_ = 0;
    } else {
      year_ = y;
      month_ = m;
      day_ = d;
    }
  }

  void Date::add_day(int num) {
    const char daytab_[2][13] = { 
      {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
      {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
    };
    while (true) {
      int leap = is_leap_year();
      int month_day = daytab_[leap][month_];
      if (day_ + num <= month_day) {
        day_ += num;
        break;
      } else {
        num -= month_day-day_ + 1;
        day_ = 1;
        add_month(1);
      }
    }
  }

  void Date::add_month(int num) {
    if (num < 0)
      return;

    add_year((month_ + num - 1) / 12);
    month_ += num % 12;
    month_ = (month_ == 12) ? 12 : month_ % 12;
  }

  void Date::add_year(int num) {
    if (num < 0)
      return;

    year_ += num;
  }

  void Date::show_date() {
    std::cout << "Year: " << year_ 
              << ", Month: " << month_ 
              << ", Day: " << day_ << std::endl;
  }

  bool Date::is_leap_year() { 
    return (year_ % 4 == 0 && year_ % 100 != 0) ||
          (year_ % 400 == 0); 
  }

  int main() {
    Date date1;  // Date()
    date1.show_date();

    Date date2(2021, 7, 1);  // Date(int y, int m, int d)
    date2.show_date();

    Date date;
    date.set_date(2011, 3, 1);
    date.show_date();
    date.add_day(30);
    date.show_date();
    date.add_day(2000);
    date.show_date();
    date.set_date(2012, 1, 31);  // leapyear
    date.add_day(29);
    date.show_date();
    date.set_date(2012, 8, 4); 
    date.add_day(2500);
    date.show_date();

    return 0;
  }

  ```
###### [뒤로가기](/tutorial/#index)
---
### SUBTITLE

###### [처음으로](#c-tutorial)
###### [뒤로가기](/tutorial/#index)
---