# C++ Tutorial
## 07 - 소멸자 
###### [뒤로가기](/tutorial/#index)
---
### 소멸자(destructor)
* 인스턴스 소멸 시 자동으로 호출되는 함수
  * 생성자는 인스턴스 생성 시 자동으로 호출되는 함수

* 소멸자는 매개변수를 사용하지 않으며, 오버로딩을 지원하지 않음
* 클래스 이름 앞에 `~`를 붙여 사용    
  ```cpp
  #include <iostream>
  #include <string.h>

  class Test {
  public:
    explicit Test(char* name);
    ~Test();
  private:
    char* name_;
  };

  Test::Test(char* name) {
    name_ = new char[strlen(name) + 1];
    strcpy(name_, name);
    std::cout << name_ << " 생성자 호출" << std::endl;
  }

  Test::~Test() {
    if (name_ != NULL) {
      std::cout << name_ << " 소멸자 호출" << std::endl;
      delete[] name_;
    }
  }

  void foo();

  int main() {
    Test test((char*) "main()");
    foo();

    return 0;
  }

  void foo(void) {
    Test test((char*) "foo()");
  }
  ```

###### [처음으로](#c-tutorial)
###### [뒤로가기](/tutorial/#index)
---
