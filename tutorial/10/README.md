# C++ Tutorial
## 10 - `this`
###### [뒤로가기](/tutorial/#index)
---
### `this`
* 인스턴스 자신을 가리키는 포인터
    ```cpp
    #include <iostream>

    class Test {
    public:
        Test() = default;
        void set_val(int x, int y);
        Test& get_t(void);
    private:
        int _x, _y;
    };

    void Test::set_val(int x, int y)
    {
        this->_x=x;
        this->_y=y; // 인스턴스에 속한 멤버변수 참조

        return;
    }

    Test& Test::get_t(void)
    {

        return *this; // 자기 자신 반환(인스턴스)
    }
    ```

### 리퍼런스를 반환하는 함수
* 
    ```cpp
    #include <iostream>

    class Test {
    public:
        Test(int x);
        int& access_x(void);
        void print_x(void);
    private:
        int x_;
    };

    Test::Test(int x) : x_{x} {}

    int& Test::access_x(void)
    {

        return this->x_;
    }
    void Test::print_x(void)
    {
        std::cout << x_ << '\n';

        return;
    }

    int main(void)
    {
        Test t{5};
        t.print_x(); // 5

        int& i = t.access_x();
        i=3;
        t.print_x(); // 3

        int j = t.access_x();
        j=4;
        t.print_x(); // 3

        t.access_x()=7;
        t.print_x(); // 7

        return 0;
    }
    ```

###### [처음으로](#c-tutorial)
###### [뒤로가기](/tutorial/#index)
---