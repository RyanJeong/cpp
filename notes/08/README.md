# C++ Tutorial
## 08 - `explicit`, `mutable`
###### [뒤로가기](/tutorial/#index)
---
### `explicit`
* C++는 암시적 변환(implicit conversion)을 허용:
  ```cpp
  class MyString {
  public:
    MyString(const MyString& m_str);
    MyString(const char* str);
    MyString(char c);
    MyString(int cap);
    ~MyString(void);
  
    // .... (생략) ....

  };

  int main() {
    MyString str1 = "ABC";  // MyString str1 = MyString("ABC");
    MyString str2 = 'x';    // MyString str2 = MyString('x');
    MyString str3 = 128;    // MyString str3 = MyString(128);

    return 0;
  }
  ```
  * 암시적 변환을 허용하다 보면 가독성을 해칠 수 있음:
    * `MyString str3 = 128;`이 과연 올바른 문장인가? 왜 문자열이 아닌 정수값을 넣는가?

* `explicit` 키워드는 암시적 변환(implicit conversion)을 허용하지 않는 키워드:
  ```cpp
  class MyString {
  public:
    MyString(const MyString& m_str);
    MyString(const char* str);
    MyString(char c);
    explicit MyString(int cap);
    ~MyString(void);
  
    // .... (생략) ....

  };

  int main() {
    MyString str1 = "ABC";   // MyString str1 = MyString("ABC");
    MyString str2 = 'x';     // MyString str2 = MyString('x');
    // MyString str3 = 128;  // 암시적 변환 불허, Error!
    MyString str3(128);      // 이와 같이 생성자를 명시적으로 호출해야 함!

    return 0;
  }

  ```
### `mutable`
* `mutable` 키워드로 선언된 멤버변수는 `const` 멤버함수(상수함수)에서 수정 허용:
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
        // 멤버변수 수정 시도:
        cache.update(user_id, user_data);  // GetUserInfo 함수는 상수함수지만,
                                           // mutable 멤버 변수만 예외적으로 수정 가능
      }

      // 3. 리턴된 정보로 User 객체 생성
      return User(user_data);
    }
  };
  ```

###### [처음으로](#h-tutorial)
###### [뒤로가기](/tutorial/#index)
---