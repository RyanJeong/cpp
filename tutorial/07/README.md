# C++ Tutorial
## 07 - `const`, `static`
### 생성자 초기화 리스트(initializer list)
* 생성자를 이용한 일반적인 초기화 방법:
  ```cpp
  class Coord {
   public:
    Coord() = default;
    Coord(int x, int y);
    ~Coord() = default;
    void print_coord();

   private:
    const int x_, y_;
  };

  Coord::Coord(int x, int y) {
    x_ = x;
    y_ = y;
  }

  ```
  * 인스턴스의 멤버 변수들을 생성한 뒤에, 값을 대입:
    ```cpp
    int var;
    var = 234;
    ```
  * 만약 인스턴스의 멤버 변수들이 `const` 지시자를 사용한다면, <b>이 방법으로 초기화 불가</b>:
    ```cpp
    const int var;
    var = 234;  // variable var is read-only;
    ```

* 생성자에 생성자 초기화 리스트를 사용한 초기화 방법:
  ```cpp
  class Coord {
   public:
    Coord() = default;
    Coord(int x, int y);
    ~Coord() = default;
    void print_coord();

   private:
    const int x_, y_;
  };

  Coord::Coord(int x, int y) : x_{x}, y_{y} {}
  ```
  * 괄호 외부에는 멤버변수를, 괄호 내부에는 매개변수를 넣어줌
  * 괄회 외부에 있는 멤버변수에 매개변수 값을 대입
  * <b>인스턴스의 멤버변수 생성과 동시에 초기화 수행</b>:
    ```cpp
    int var = 234;
    ```
  * <b>인스턴스 멤버 변수가 `const` 지시자를 사용하더라도 초기화 가능</b>:
    ```cpp
    const int var = 234;  // OK!
    ```

### `static` 멤버변수
> When we declare a static member variable inside a class, we’re telling the compiler about the existence of a static member variable, but not actually defining it (much like a forward declaration). Because static member variables are not part of the individual class objects (they are treated similarly to global variables, and get initialized when the program starts), you must explicitly define the static member outside of the class, in the global scope.

* 클래스 내에 `static` 멤버변수를 선언하는 것은 단지 컴파일러에 해당 클래스의 인스턴스들이 `static` 멤버변수를 사용한다는 것을 선언
* `static` 멤버변수는 클래스에 속한 것이 아닌 일종의 전역변수이며, 해당 전역변수는 컴파일러에 선언만 한 것이기 때문에, 반드시 클래스의 `static` 멤버변수를 <b>전역 영역(global scope)에 다시 명시적으로 정의</b>해야 함
* 클래스 내에서 전역변수 역할을 수행하며, 모든 인스턴스가 접근해 사용할 수 있음
* 인스턴스가 소멸될 때 사라지는 것이 아닌, 프로그램 종료 시 소멸:
  ```cpp
  #include <iostream>

  class Coord {
   public:
    Coord();
    Coord(int x, int y);
    ~Coord();
    void print_total_num();

   private:
    const int x_, y_;
    static int total_num;
  };

  int Coord::total_num = 0; // Explicit init.

  Coord::Coord() : x_{0}, y_{0} { ++total_num; }
  Coord::Coord(int x, int y) : x_{x}, y_{y} { ++total_num; }
  Coord::~Coord() { --total_num; }

  void Coord::print_total_num() {
    std::cout << total_num << '\n';
  }

  void foo();
  void bar();

  int main() {
    Coord c1{3, 4};
    c1.print_total_num();  // 1
    foo();
    c1.print_total_num();  // 1

    return 0;
  }

  void foo() {
    Coord c2{5, 6};
    c2.print_total_num();  // 2
    bar();
    c2.print_total_num();  // 2
  }

  void bar() {
    Coord c3{7, 8};
    c3.print_total_num();  // 3
  }
  ```

### `static` 함수
* 메소드는 인스턴스를 통해 호출 가능
* 인스턴스에 종속되는 메소드와는 달리, `static` 함수는 클래스에 속해있는 유일한 함수
* `static` 멤버 변수만 사용 가능
  * `static` 함수는 인스턴스에 종속되지 않으며, 따라서 일반 멤버변수를 사용할 때 어떤 멤버변수를 사용해야 하는지 알 수 없음
* 인스턴스가 있어야 메소드를 호출할 수 있는 것과 달리, `static` 함수는 <b>인스턴스 없이 클래스 자체에서 호출 가능</b>:
  ```cpp
  #include <iostream>

  class Coord {
   public:
    Coord();
    Coord(int x, int y);
    ~Coord();
    static void print_total_num();  // Only `static` member can be used

   private:
    const int x_, y_;
    static int total_num;
  };

  int Coord::total_num = 0;  // Explicit init.

  Coord::Coord() : x_{0}, y_{0} { ++total_num; }
  Coord::Coord(int x, int y) : x_{x}, y_{y} { ++total_num; }
  Coord::~Coord() { --total_num; }

  void Coord::print_total_num() {
    std::cout << total_num << '\n';
  }

  void foo();
  void bar();

  int main() {
    Coord c1{3, 4};
    Coord::print_total_num();  // 1
    foo();
    Coord::print_total_num();  // 1

    return 0;
  }

  void foo() {
    Coord c2{5, 6};
    Coord::print_total_num();  // 2
    bar();
    Coord::print_total_num();  // 2
  }

  void bar() {
    Coord c3{7, 8};
    Coord::print_total_num();  // 3
  }

  ```

### `this` 포인터
* 멤버 함수를 호출한 객체를 가리키는 포인터:
  ```cpp
  #include <iostream>

  class Test {
   public:
    Test() = default;
    void SetVal(int x, int y);
    Test& GetInst();

   private:
    int _x, _y;
  };

  void Test::SetVal(int x, int y) {
    _x = x;  // _x == this->_x
    _y = y;  // _y == this->_y
  }

  Test& Test::GetInst() {
    return *this;  // 자기 자신 반환(인스턴스)
  }
  ```

* 컴파일러가 내부적으로 추가하는 포인터:
  ```cpp
  class Sample {
   private:
    int a;

   public:
    void SetA(int i) {  // void SetA(Sample* this, int i)
      this->a = i;
    }
  };

  int main() {
    Sample sample;
    sample.SetA(100);  // sample.SetA(&sample, 100);

    return 0;
  }

  ```
  * 컴파일러는 내부적으로 다음과 같이 처리:
    * `void SetA(int i)` -> `void SetA(Sample* this, int i)`
    * `sample.SetA(100)` -> `sample.SetA(&sample, 100)`
  * <b>`static` 함수는 인스턴스에 속해있지 않으므로, `this` 포인터를 사용할 수 없음</b>

### 레퍼런스 반환 함수
* 함수가 레퍼런스를 반환한다면, 해당 함수의 호출 부분을 함수가 반환하는 변수로 치환 가능:
  ```cpp
  #include <iostream>

  class Test {
   public:
    Test(int x);
    int& access_x();
    void print_x();

   private:
    int x_;
  };

  Test::Test(int x) : x_{x} {}

  int& Test::access_x() {
    return this->x_;
  }

  void Test::print_x() {
    std::cout << x_ << std::endl;
  }

  int main() {
    Test t{5};
    t.print_x();  // 5

    int& i = t.access_x();  // t 인스턴스의 멤버변수 x_로 치환, i는 레퍼런스이므로 t 인스턴스의 x_를 가리킴
    i = 3;
    t.print_x();  // 3

    int j = t.access_x();  // t 인스턴스의 멤버변수 x_로 치환, j는 일반 변수이므로 값 복사
    j = 4;
    t.print_x();  // 3

    t.access_x() = 7;  // t 인스턴스의 멤버변수 x_로 치환, x_에 값 대입
    t.print_x();  // 7

    return 0;
  }

  ```
  
###### [뒤로가기](/tutorial/#index)

---
### SUBTITLE

###### [처음으로](#c-tutorial)
###### [뒤로가기](/tutorial/#index)
---