# C++ Tutorial
## 01 - C++ 소개 및 프로그램 분석
###### [뒤로가기](/tutorial/)
---
### 첫 프로그램
```cpp
#include <iostream>

int main(void)
{
    std::cout << "Hello, World!" << std::endl;

    return 0;
}
```
* `#include <iostream>`
    * C++ 표준 입출력 관련 정보들을 포함
    * `std::cout`, `std::endl`, ...
    * C 언어에서의 `stdio.h`
    * C++ 헤더 파일은 파일명 뒤에 `.h`가 붙지 않음:
        1. <b>프로그래머가 정의한 헤더파일</b> 선언 시 확장자 `.h`를 붙인다.
        2. <b>표준 헤더파일</b> 선언 시 확장자 `.h`를 생략한다. 

* `int main(void) { ... }`
    * 프로그램 시작 시 가장 먼저 실행되는 함수
    * `{ ... }` 부분은 `main` 함수의 몸체

* `std::cout`
    * 화면에 데이터를 출력하는 역할

* `std::endl`
    * 출력 버퍼를 비우는 역할
    * `'\n'`
    * `endl`를 자주 사용하다 보면 속도 저하를 야기할 수 있음

### 이름 공간 (namespace)
* `std`의 의미
    * 사용하고자 하는 대상의 <b>소속</b>을 구분하기 위해 사용
    * 프로그램 규모가 커짐에 따라 중복된 이름을 가진 구현체(함수 등)의 수가 늘어나게 되었고, 이를 효율적으로 구분하여 사용하기 위해 <b>이름 공간</b> 개념을 도입하게 됨
    * `std::cout`은 `std`라는 이름 공간에 속해 있는 `cout`을 사용한다는 의미 

* 이름 공간의 사용 예:
    ```cpp
    // header1
    namespace header1 {
        int foo();
        void bar();
    }
    ```
    ```cpp
    // header2
    namespace header2 {
        double foo();
        int bar();
    }
    ```
    * 함수 `foo(), bar()`은 이름은 같으나 이름 공간에 의해 서로 구분됨

    ```cpp
    #include "header1.h"

    namespace header1 {
        int func(void)
        {

            return foo(); // header1::foo()
        }
    }
    ```
    * 이름 공간 내에서 <i>name</i>(ex. `foo()`)이 사용될 때, 해당 이름 공간에 존재하는 <i>name</i>을 우선 사용

    ```cpp
    #include "header1.h"
    #include "header2.h"

    namespace header1 {
        int func(void)
        {
            header2::bar();

            return foo(); // header1::foo()
        }
    }
    ```
    * 이름 공간에서 다른 이름 공간에 속한 함수를 호출하고자 할 때, `::`를 사용해 사용하고자 하는 <i>name</i>과 연결해 사용할 수 있음

    ```cpp
    #include "header1.h"
    #include "header2.h"

    int func(void)
    {

        header1::foo(); 
    }
    ```
    * 이름 공간이 없다면 직접 `::`를 사용해 연결해 사용해야 함

    ```cpp
    #include "header1.h"

    using header1::foo;

    int func(void)
    {

        return foo(); // header1:foo()
    }
    ```
    * `header` 이름 공간에 속한 `foo()` 함수만 사용하고자 한다면 위와 같이 이름 공간 대신 특정 함수를 지정해 사용할 수 있음  

    ```cpp
    #include "header1.h"

    using namespace header1;

    int func(void)
    {
        bar(); // header1::bar()

        return foo(); // header1:foo()
    }
    ```
    * `header1` 이름 공간에 정의된 <i>name</i>들을 `header1::` 없이 사용하고자 할 때 위와 같이 이름 공간을 명시해야 함

* `using namespace std;`
    * <b>권장하지 않음</b>
    * `std` 이름 공간에 속해 있는 <i>name</i>과 겹치는 <i>name</i>이 있을 때, 충돌이 발생할 수 있음
        * 특히, 표준 라이브러리는 양이 매우 거대함에 따라 <i>name</i> 충돌 위험이 굉장히 높음
    * `std::`를 직접 붙여 사용하는 것을 권장 

* `namespace`
    ```cpp
    namespace {
        int static_func(void)
        {

            return 3;
        }

        int static_var = 1;
    }

    int main(void)
    {
        static_var=static_func();

        return 0;
    }
    ```
    * `namespace` 키워드 다음에 아무것도 오지 않는다면, 해당 영역은 `static` 영역임
    * 해당 영역은 해당 파일 내에서만 사용 가능한 상태
    
###### [처음으로](#c-tutorial)
###### [뒤로가기](/tutorial/)
---
