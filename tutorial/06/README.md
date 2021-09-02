# C++ Tutorial
## 06 - 생성자
###### [뒤로가기](/tutorial/#index)
---
### 생성자(constructor)
* 인스턴스 생성 시 자동으로 호출되는 함수
    * 클래스로부터 인스턴스를 생성함과 동시에 초기화하기 위해 사용
* 개발자가 일으킬 수 있는 초기화 누락 문제를 해결할 수 있음
    * 초기화하지 않은 지역 변수는 내부에 쓰레기 값이 들어 있음

    ```c++
    class Date {
    public:
        // 생성자는 객체를 초기화하는 역할만을 수행하므로
        // 별도의 반환값이 없음
        Date(int y, int m, int d) { year_=y; month_=m; day_=d; } 
        void set_date(int y, int m, int d);
        void add_day(int num);
        void add_month(int num);
        void add_year(int num);
        void show_date(void);
    private:
        bool is_leap_year(void);
        int year_;
        int month_;
        int day_;
    };

    ...

        Date day(2021,9,2);        // 암시적 방법, implicit
        Date day = Date(2021,9,2); // 명시적 방법, explicit
    ```

#### 디폴트 생성자 (default constructor)
* 생성자 중에서 전달인자를 사용하지 않는 생성자
    1. defined with an empty parameter list
    2. with default arguments provided for every parameter
* 클래스에서 사용자가 어떠한 생성자도 명시적으로 정의하지 않았다면 컴파일러가 자동으로 생성함
    * 이 경우에서의 디폴트 생성자는 빈 매개변수 목록을 갖는 형태
    ```cpp
        Date day;
    ```

* 다음과 같이 직접 디폴트 생성자를 정의할 수 있음:
    ```cpp
    class Date {
    public:
        Date() { year_=2021; month_=7; day_=12; }
        void set_date(int y, int m, int d);
        void add_day(int num);
        void add_month(int num);
        void add_year(int num);
        void show_date(void);
    private:
        bool is_leap_year(void);
        int year_;
        int month_;
        int day_;
    };

    ...
    
        Date date;          // implicit
        Date date = Date(); // explicit
    ```

* 클래스에 생성자가 표현되어 있지 않을 때, 개발자가 생성자를 실수로 누락한 것인지, 컴파일러가 만들어 주는 디폴트 생성자를 사용하기 위해 고의로 생략한 것인지 작성자의 의도를 알기에 모호함
* `default` 키워드를 사용하면 <b>명시적으로 디폴트 생성자를 사용하겠다는 의미</b>
    ```cpp
    class Foo {
    public:
        Foo() = default;
    };
    ```
* 사용자가 정의한 생성자(user-declared constructor)가 있는 경우 디폴트 생성자는 생성되지 않으며, 이때 `default` 키워드를 사용하면 디폴트 생성자를 생성할 수 있음

#### 생성자 오버로딩
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
    void show_date(void);
private:
    bool is_leap_year(void);
    int year_;
    int month_;
    int day_;
};

Date::Date() : year_{2021}, month_{9}, day_{2} {}
Date::Date(int y, int m, int d) : year_{y}, month_{m}, day_{d} {}

void Date::set_date(int y, int m, int d)
{
    if (y<0 || m<0 || d<0) {
        year_=0;
        month_=0;
        day_=0;
    }
    else {
        year_=y;
        month_=m;
        day_=d;
    }

    return;
}

void Date::add_day(int num)
    {
    const char daytab_[2][13] = { 
        {0,31,28,31,30,31,30,31,31,30,31,30,31},
        {0,31,29,31,30,31,30,31,31,30,31,30,31}
    };
    while (1) {
        int leap = is_leap_year();
        int month_day = daytab_[leap][month_];
        if (day_+num<=month_day) {
            day_+=num;
            break;
        }
        else {
            num-=month_day-day_+1;
            day_=1;
            add_month(1);
        }
    }

    return;
}

void Date::add_month(int num)
{
    if (num<0) {

        return;
    }
    add_year((month_+num-1)/12);
    month_+=num%12;
    month_=((month_==12) ? 12 : month_%12);

    return;
}

void Date::add_year(int num)
{
    if (num<0) {

        return;
    }
    year_+=num;

    return;
}

void Date::show_date(void)
{
    std::cout << "Year: " << year_ 
              << ", Month: " << month_ 
              << ", Day: " << day_ << std::endl;

    return;
}

bool Date::is_leap_year(void) 
{ 
    
    return (year_%4==0 && year_%100!=0) || (year_%400==0); 
}

int main(void)
{
    Date date1; // Date()
    date1.show_date();

    Date date2(2021,7,1); // Date(int y, int m, int d)
    date2.show_date();

    Date date;
    date.set_date(2011,3,1);
    date.show_date();
    date.add_day(30);
    date.show_date();
    date.add_day(2000);
    date.show_date();
    date.set_date(2012,1,31); // leapyear
    date.add_day(29);
    date.show_date();
    date.set_date(2012,8,4); 
    date.add_day(2500);
    date.show_date();

    return 0;
}
```

#### `malloc()` vs. `new`
* `malloc()`은 메모리를 동적으로 할당 후 해당 위치 주소 반환
* `new`는 메모리 동적 할당 후 <b>생성자를 자동 호출</b>

###### [처음으로](#c-tutorial)
###### [뒤로가기](/tutorial/#index)
---
