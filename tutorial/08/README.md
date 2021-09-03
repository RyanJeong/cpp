# C++ Tutorial
## 08 - 복사생성자
###### [뒤로가기](/tutorial/#index)
---
### 복사생성자
* 기존에 생성되어 있는 인스턴스 값을 새로 생성할 인스턴스에 복사하는 생성자
* <b>인스턴스 생성 시에만 호출됨에 유의할 것</b>
* 디폴트 생성자와 디폴트 소멸자와 같이, 컴파일러는 디폴트 복사 생성자(default copy constructor)를 지원
    ```cpp
    class Test {
    public:
        Test();
        Test(const Test& t);
        ~Test();
    private:
        int x_;
    };

    ...

    Test::Test(const Test& t)
    {
        x_=t.x;
    }
    ```
    * 디폴트 복사 생성자는 멤버 변수들의 값을 새로 생성될 인스턴스로 그대로 복사함 (얕은 복사, shallow copy)

* 디폴트 복사 생성자는 아래와 같은 상황에서 오류가 발생하게 됨:
    ```cpp
    class Test {
    public:
        Test(char* name);
        Test(const Test& t);
        ~Test(void);
    private:
        char* name_;
    };

    Test::Test(char* name)
    {
        name_ = new char[strlen(name)+1];
        strcpy(name_,name);
        std::cout << name_ << " 생성자 호출" << std::endl;

        return;
    }

    // Shallow copy constructor
    Test::Test(const Test& t)
    {
        std::cout << t.name_ << " 복사생성자 호출" << std::endl;
        name_=t.name_;

        return;
    }

    Test::~Test(void)
    {
        if (name_!=NULL) {
            std::cout << name_ << " 소멸자 호출" << std::endl;
            delete[] name_;
        }

        return;
    }

    void foo(void);

    int main(void)
    {
        Test test((char*) "main()");
        Test t = test; // Test t{test}와 동치 
        foo();

        return 0;
    }

    void foo(void)
    {
        Test test((char*) "foo()");

        return;
    }
    ```
    * `Test t = test` 표현식은 `t`에 `test`의 멤버변수 값을 그대로 복사
    * `t`의 멤버변수 `name_`은 `test`의 멤버변수 `name_`의 주소값만을 복사
    * 소멸자를 통해 소멸하는 과정에서 만약 `test`가 먼저 소멸되었다고 가정한다면, `test`의 `name_` 또한 소멸자에 의해 소멸
    * `t`의 소멸자가 `t`의 `name_`을 소멸하기 위해 메모리에 접근했지만, 해당 영역은 이미 `test`가 소멸될 때 소멸됨
    * 따라서 런타임 오류가 발생하며, 이를 해결하기 위해서는 <b>깊은 복사(deep copy)</b>가 필요

    ```cpp
    #include <iostream>
    #include <string.h>

    class Test {
    public:
        Test(char* name);
        Test(const Test& t);
        ~Test(void);
    private:
        char* name_;
    };

    Test::Test(char* name)
    {
        name_ = new char[strlen(name)+1];
        strcpy(name_,name);
        std::cout << name_ << " 생성자 호출" << std::endl;

        return;
    }

    // Deep copy constructor
    Test::Test(const Test& t)
    {
        std::cout << t.name_ << " 복사생성자 호출" << std::endl;
        name_ = new char[strlen(t.name_)+1];
        strcpy(name_,t.name_);

        return;
    }

    Test::~Test(void)
    {
        if (name_!=NULL) {
            std::cout << name_ << " 소멸자 호출" << std::endl;
            delete[] name_;
        }

        return;
    }

    void foo(void);

    int main(void)
    {
        Test test((char*) "main()");
        Test t = test; // Test t{test}와 동치 
        foo();

        return 0;
    }

    void foo(void)
    {
        Test test((char*) "foo()");

        return;
    }
    ```
    ```text
    main() 생성자 호출
    main() 복사생성자 호출
    foo() 생성자 호출
    foo() 소멸자 호출
    main() 소멸자 호출
    main() 소멸자 호출
    ```

###### [처음으로](#c-tutorial)
###### [뒤로가기](/tutorial/#index)
---
