# C++ Tutorial
## 11 - `explicit`과 `mutable`
###### [뒤로가기](/tutorial/#index)
---
### `explicit`
* 암묵적 변환을 막는 키워드
```cpp
#include <iostream>
#include <string.h>

class My_string {
    char* content_;
    int length_;
    int capacity_;
public:
    My_string(const My_string& m_str);
    My_string(const char* str);
    My_string(int cap);
    ~My_string(void);
};

My_string::My_string(const My_string& m_str)
{
    length_=m_str.length_;
    capacity_=length_;
    content_=new char[length_];

    //strcpy(content_,m_str.content_); not terminated with 'null' character
    for (int i = 0; i<length_; ++i) {
        content_[i]=m_str.content_[i];
    }

    return;
}

My_string::My_string(const char* str) 
{
    length_=strlen(str);
    capacity_=length_;
    content_=new char[length_];
    strcpy(content_,str);

    return;
}

My_string::My_string(int cap) 
{
    length_=0;
    capacity_=cap;
    content_=new char[capacity_];
    std::cout << "Capacity: " << capacity_ << std::endl;

    return;
}

My_string::~My_string(void) {
    delete[] content_;

    return;
}

void do_something_with_string(My_string m_str)
{
    // Do something ...
    return;
}

int main(void)
{
    do_something_with_string(3); // ?? -> (implicit) My_string(int cap);

    return 0;
}
```

* 위 코드는 컴파일러에 의해 암묵적 변환(implicit conversion) 발생
    ```cpp
    do_something_with_string(3); // do_something_with_string(My_string(3));
    ```

* `My_string::My_string(int cap)` 선언 앞에 `explicit` 키워드를 사용하면 컴파일러에 의해 암시적으로 변환되는 걸 막을 수 있음:
    ```cpp
    explicit My_string(int cap);
    ```

#### `explicit` 키워드 사용 예
* 복사 생성자(`T a = b`; or `T a(b)`;, where `b` is of type `T`;) 사용 시 가독성을 높일 수 있음:
    ```cpp
    My_string s = "abc";  // My_string s("abc")
    My_string s = 5;      // My_string s(5)
    ```
    * 첫 번째 문장은 우리가 직관적으로 이해할 수 있지만, 두 번째 문장은 고개가 갸웃거릴 수 있음
    * 문자열에 왜 숫자 5를 넣는가..?
    * `explicit` 키워드를 사용하면 위 문제를 해결할 수 있음:

    ```cpp
    explicit My_string(int cap);
    
    ...

    My_string s = "abc";  // My_string s("abc")
    My_string s = 5;      // Compile Error!
    ```

### `mutable`
* `const` 멤버 함수는 멤버 변수들의 값을 변경할 수 없음
* 멤버 변수 중 `mutable` 변수들은 `const` 멤버 함수 내에서도 값 변경 가능
  ```cpp
  class Server {
  // .... (생략) ....

    mutable Cache cache; // 캐쉬!

    // 이 함수는 데이터베이스에서 user_id 에 해당하는 유저 정보를 읽어서 반환한다.
    User GetUserInfo(const int user_id) const {
      // 1. 캐쉬에서 user_id 를 검색
      Data user_data = cache.find(user_id);

      // 2. 하지만 캐쉬에 데이터가 없다면 데이터베이스에 요청
      if (!user_data) {
        user_data = Database.find(user_id);

        // 그 후 캐쉬에 user_data 등록
        // const 멤버 함수지만, 멤버 변수 cache는 mutable로 선언되었음
        // 따라서 cache의 값 변경 가능!
        cache.update(user_id, user_data);
      }

      // 3. 리턴된 정보로 User 객체 생성
      return User(user_data);
    }
  };
  ```

###### [처음으로](#c-tutorial)
###### [뒤로가기](/tutorial/#index)
---