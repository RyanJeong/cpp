# C++ Tutorial
## 09 - 클래스의 `const`, `static`
###### [뒤로가기](/tutorial/#index)
---
### `const` 변수
* 클래스 내 멤버변수 중에서 값이 변하지 않는 변수
* `const` 변수는 레퍼런스 변수와 마찬가지로 생성과 동시에 초기화가 이루어져야 하므로, 초기화 리스트를 이용한 생성자를 통해 초기화해야 함
    ```cpp
    #include <iostream>

    class Coord {
    public:
        Coord() = default;
        Coord(int x, int y);
        ~Coord() = default;
        void print_coord(void);
    private:
        const int x_, y_;
    };

    Coord::Coord(int x, int y) : x_{x}, y_{y} {}

    void Coord::print_coord(void)
    {
        std::cout << x_ << ' ' << y_ << std::endl;

        return;
    }

    int main(void)
    {
        Coord c1{3,4};
        Coord c2{5,6};

        c1.print_coord();
        c2.print_coord();

        return 0;
    }
    ```

### `const` 함수
* 멤버변수의 값을 바꾸지 않고 읽기만 하는 함수
* `const` 함수는 상수 함수로 간주해 사용할 수 있음
    ```cpp
    #include <iostream>

    class Coord {
    public:
        Coord() = default;
        Coord(int x, int y);
        ~Coord() = default;
        int get_x(void) const;
        int get_y(void) const;
    private:
        const int x_, y_;
    };

    Coord::Coord(int x, int y) : x_{x}, y_{y} {}

    int Coord::get_x(void) const { return x_; } // 인스턴스 변수 읽기만 가능
    int Coord::get_y(void) const { return y_; } // 인스턴스 변수 읽기만 가능

    int main(void)
    {
        Coord c1{3,4};
        Coord c2{5,6};

        std::cout << c1.get_x() << ' ' << c1.get_y() << '\n';
        std::cout << c2.get_x() << ' ' << c2.get_y() << '\n';

        return 0;
    }
    ```
    * 상수함수에서 다른 함수를 호출하고자 할 때 상수함수만 호출 가능

### `static` 변수
* 클래스 내에서 전역변수 역할을 수행
* 인스턴스가 소멸될 때 사라지는 것이 아닌, 프로그램 종료 시 소멸
* 각각의 인스턴스는 인스턴스에 속한 멤버 변수를 갖게 되지만, `static` 변수는 클래스에 속해 있으면서 동시에 모든 인스턴스가 접근해 사용할 수 있는 변수
    ```c++
    #include <iostream>

    class Coord {
    public:
        Coord();
        Coord(int x, int y);
        ~Coord();
        void print_total_num(void);
    private:
        const int x_, y_;
        static int total_num;
    };

    int Coord::total_num = 0; // Explicit init.

    Coord::Coord() : x_{0}, y_{0} { ++total_num; }
    Coord::Coord(int x, int y) : x_{x}, y_{y} { ++total_num; }
    Coord::~Coord() { --total_num; }

    void Coord::print_total_num(void)
    {
        std::cout << total_num << '\n';

        return;
    }

    void foo(void);
    void bar(void);

    int main(void)
    {
        Coord c1{3,4};
        c1.print_total_num();
        foo();
        c1.print_total_num();

        return 0;
    }

    void foo(void)
    {
        Coord c2{5,6};
        c2.print_total_num();
        bar();
        c2.print_total_num();

        return;
    }

    void bar(void)
    {
        Coord c3{7,8};
        c3.print_total_num();

        return;
    }
    ```

### `static` 함수
* 메소드는 인스턴스를 통해 호출 가능
* 인스턴스에 종속되는 메소드와는 달리, `static` 함수는 클래스에 속해있는 하나의 함수
* 인스턴스가 있어야 메소드를 호출할 수 있는 것과 달리, `static` 함수는 <b>인스턴스 없이 클래스 자체에서 호출 가능</b>
    ```cpp
    #include <iostream>

    class Coord {
    public:
        Coord();
        Coord(int x, int y);
        ~Coord();
        static void print_total_num(void);
    private:
        const int x_, y_;
        static int total_num;
    };

    int Coord::total_num = 0; // Explicit init.

    Coord::Coord() : x_{0}, y_{0} { ++total_num; }
    Coord::Coord(int x, int y) : x_{x}, y_{y} { ++total_num; }
    Coord::~Coord() { --total_num; }

    void Coord::print_total_num(void)
    {
        std::cout << total_num << '\n';

        return;
    }

    void foo(void);
    void bar(void);

    int main(void)
    {
        Coord c1{3,4};
        Coord::print_total_num();
        foo();
        Coord::print_total_num();

        return 0;
    }

    void foo(void)
    {
        Coord c2{5,6};
        Coord::print_total_num();
        bar();
        Coord::print_total_num();

        return;
    }

    void bar(void)
    {
        Coord c3{7,8};
        Coord::print_total_num();

        return;
    }
    ```
    

###### [처음으로](#c-tutorial)
###### [뒤로가기](/tutorial/#index)