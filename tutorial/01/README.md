# C++ Tutorial
## 01 - `namespace`
* 사용하고자 하는 대상의 <b>소속</b>을 구분하기 위해 사용
* 프로그램 규모가 커짐에 따라 중복된 이름을 가진 구현체(함수 등)의 수가 늘어나게 되었고, 이를 효율적으로 구분하여 사용하기 위해 <b>이름 공간(`namespace`)</b> 개념을 도입하게 됨
* `std::cout`은 `std`라는 이름 공간에 속해 있는 `cout`을 사용한다는 의미 

* 이름 공간의 사용 예:
  * 함수 `foo(), bar()`은 서로 이름(name)이 같지만 이름 공간에 의해 서로 구분됨 :
    ```cpp
    // header1.h

    namespace header1 {
    int foo();
    void bar();
    }  // header1
    ```
    ```cpp
    // header2.h

    namespace header2 {
    double foo();
    int bar();
    }  // header2
    ```

  * `header1`의 이름 공간에 `header1::foo()`가 속해있다면, 범위지정 연산(`::`)은 필요하지 않음:
    ```cpp
    #include "header1.h"

    namespace header1 {
    int func() { 
      return foo();  // header1::foo()
    }
    }  // header1
    ```

  * 범위지정 연산(`::`)을 사용해 다른 이름 공간에 속한 이름 사용 가능(e.g. 변수 사용, 함수 호출, etc.):
    ```cpp
    #include "header1.h"
    #include "header2.h"

    namespace header1 {
    int func() {
      header2::bar();
      
      return foo();  // header1::foo()
    }
    }  // header1
    ```

  * 범위지정 연산(`::`)을 사용하면 이름 공간에 속한 이름 직접 지정해 사용 가능:
    ```cpp
    #include "header1.h"
    #include "header2.h"

    int func() { header1::foo(); }
    ```

  * `using` 키워드를 사용해 `header1` 이름 공간에 속한 `foo` 이름을 `foo`로 축약 사용 가능:
    ```cpp
    #include "header1.h"

    using header1::foo;

    int func() {
      return foo();  // header1:foo()
    }
    ```

  * `using namespace` 키워드를 사용해 `header1` 이름 공간에 속한 이름들을 범위지정 연산(`::`) 없이 사용 가능:
    ```cpp
    #include "header1.h"

    using namespace header1;

    int func() {
      bar();  // header1::bar()

      return foo();  // header1:foo()
    }
    ```

* `using namespace std;`
    * <b>Do not use namespace using-directives.  Use using-declarations instead.</b>
    * `std::`를 직접 붙여 사용하는 것을 권장 
    * 작성중인 코드 내에 `std` 이름 공간에 속해 있는 이름과 겹치는 이름이 있을 때, 충돌 발생
        * 표준 라이브러리는 양이 매우 거대함에 따라 `using namespace std` 선언을 할 경우 충돌 위험이 굉장히 높음

* `namespace`
    * `namespace` 키워드만 단독 사용할 경우 해당 영역은 `static`
    * 해당 영역은 <b>해당 파일 내</b>에서만 사용 가능:
      ```cpp
      namespace {
      int static_func() {
        return 3;
      }

      int static_var = 1;
      }  // static

      int main() {
        static_var = static_func();

        return 0;
      }
      ```

###### [뒤로가기](/tutorial/#index)
---
### SUBTITLE

###### [처음으로](#c-tutorial)
###### [뒤로가기](/tutorial/#index)
---