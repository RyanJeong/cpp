# C++ Tutorial
## 06 - 객체지향프로그래밍 3
###### [뒤로가기](/tutorial/#index)
---
### 소멸자(destructor)
* 인스턴스 소멸 시 자동으로 호출되는 함수
* 소멸자는 매개변수를 사용하지 않으며, 오버로딩을 지원하지 않음
* 사용자가 소멸자를 명시하지 않았다면, 컴파일러는 자동으로 아무 동작도 하지 않는 <b>디폴트 소멸자(default destructor)</b> 생성
* 클래스 이름 앞에 `~`를 붙여 사용:
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

  int main() {
    Test test((char*) "main()");
    foo();

    return 0;
  }

  ```

### 복사 생성자(copy constructor)
* 기존에 생성되어 있는 인스턴스 값을 새로 생성할 인스턴스에 복사하는 생성자
* <b>인스턴스 생성 시에만 호출됨에 유의할 것</b>
* 디폴트 생성자와 디폴트 소멸자와 같이, 컴파일러는 디폴트 복사 생성자(default copy constructor)를 지원
* 디폴트 복사 생성자는 멤버 변수들의 값을 새로 생성될 인스턴스로 그대로 복사함 (얕은 복사, shallow copy):
  ```cpp
  class Test {
   public:
    Test();
    Test(const Test& t);
    ~Test();
   private:
    int x_;
  };

  Test::Test(const Test& t) {
    x_ = t.x;
  }
  ```

### 얕은 복사(shallow copy)
* 디폴트 복사 생성자는 아래와 같은 상황에서 오류가 발생하게 됨:
  ```cpp
  class Test {
   public:
    Test(char* name);
    Test(const Test& t);
    ~Test();
   private:
    char* name_;
  };

  Test::Test(char* name) {
    name_ = new char[strlen(name)+1];
    strcpy(name_, name);
    std::cout << name_ << " 생성자 호출" << std::endl;
  }

  // Shallow copy constructor
  Test::Test(const Test& t) {
    std::cout << t.name_ << " 복사생성자 호출" << std::endl;
    name_ = t.name_;
  }

  Test::~Test() {
    if (name_ != NULL) {
      std::cout << name_ << " 소멸자 호출" << std::endl;
      delete[] name_;
    }
  }

  int main() {
    Test test((char*) "main()");
    Test t = test; // Test t{test}와 동치

    return 0;
  }

  ```
  * `Test t = test;` 문장은 `t`에 `test`의 멤버변수 값을 그대로 복사
  * `t`의 멤버변수 `name_`은 `test`의 멤버변수 `name_`의 주소값만을 복사
  * 소멸자를 통해 소멸하는 과정에서 만약 `test`가 먼저 소멸되었다고 가정한다면, `test`의 `name_` 또한 소멸자에 의해 소멸
  * `t`의 소멸자가 `t`의 `name_`을 소멸하기 위해 메모리에 접근했지만, 해당 영역은 이미 `test`가 소멸될 때 소멸됨었으며, 결국 <b>런타임 오류가 발생하게 됨</b>

### 깊은 복사(deep copy)
* 얕은 복사의 문제를 해결하려면 깊은 복사를 사용해야 함:
  ```cpp
  #include <iostream>
  #include <string.h>  // [NOLINT]

  class Test {
  public:
    explicit Test(char* name);
    explicit Test(const Test& t);
    ~Test();
  private:
    char* name_;
  };

  Test::Test(char* name) {
    name_ = new char[strlen(name)+1];
    strcpy(name_, name);  // [NOLINT]
    std::cout << name_ << " 생성자 호출" << std::endl;
  }

  // Deep copy constructor
  Test::Test(const Test& t) {
    std::cout << t.name_ << " 복사생성자 호출" << std::endl;
    name_ = new char[strlen(t.name_)+1];
    strcpy(name_, t.name_);  // [NOLINT]
  }

  Test::~Test() {
    if (name_ != NULL) {
      std::cout << name_ << " 소멸자 호출" << std::endl;
      delete[] name_;
    }
  }

  int main() {
    Test test((char*) "main()");  // [NOLINT]
    Test t(test);
    foo();

    return 0;
  }

  ```
  ```text
  main() 생성자 호출
  main() 복사생성자 호출
  main() 소멸자 호출
  main() 소멸자 호출
  ```

### 암묵적 복사 생성자
* 복사 생성자가 호출되는 경우:
  ```cpp
  #include <iostream>
  #include <cstring>

  class Person {
    char* name;
    int id;

  public:
    Person(int id, const char* name);
    Person(const Person& person);
    ~Person();
    void changeName(const char *name);
    void show() { std::cout << id << ',' << name << std::endl; }
  };

  Person::Person(int id, const char* name) {
    this->id = id;
    int len = strlen(name);
    this->name = new char[len+1];
    strcpy(this->name, name); // [NOLINT]
  }

  Person::Person(const Person& person)
      : Person(person.id, person.name) {
    std::cout << "복사 생성자 실행. 원본 객체의 이름 "
              << this->name << std::endl;
  }

  Person::~Person() {
    if (name) {
      delete [] name;
    }
  }

  void Person::changeName(const char* name) {
    if (strlen(name) <= strlen(this->name)) {
      strcpy(this->name, name); // [NOLINT]
    }
  }

  void f(Person person) { person.changeName("dummy"); }

  Person g() {
    Person mother(2, "Jane");

    return mother;
  }

  int main() {
    Person father(1, "Kitae");
    std::cout << "Person son = father;" << std::endl;
    // 복사 생성자 호출
    Person son = father;
    std::cout << "f(father);" << std::endl;

    // 복사 생성자 호출
    f(father);
    std::cout << "g();" << std::endl;

    // 복사 생성자 호출
    // 레퍼런스가 아닌 값 반환 시 복사 생성자 호출
    // copy elision
    // "-fno-elide-constructors"
    g();

    return 0;
  }

  ```

###### [처음으로](#c-tutorial)
###### [뒤로가기](/tutorial/#index)
---