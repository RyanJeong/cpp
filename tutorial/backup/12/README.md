# C++ Tutorial
## 12 - 연산자 오버로딩[WIP]
###### [뒤로가기](/tutorial/#index)
---
### 연산자 오버로딩(overloading)
* 사용자가 기본 연산자들을 직접 정의해 사용하는 것 
* 연산자 오버로딩 형태는 아래와 같음:
  ```text
  (리턴 타입) operator(연산자)(연산자가 받는 인자)
  ```

* 간단한 예:
  ```cpp
  bool operator==(const MyString& str);

  ...

  bool MyString::operator==(const MyString& str) {
    return !compare(str);  // str 과 같으면 compare 에서 0 을 리턴한다.
  }
  ```
  * `str1 == str2` 문장을 처리할 때 해당 문장은 `str1.operator==(str2)`으로 변환되어 처리

### 사칙연산 연산자 오버로딩
* 사칙연산을 수행하는 연산자를 오버로딩하고자 할 때, <b>반환형은 값이어야 함</b>
  * 예를 들어, 문장 `Complex a = b + c + b;`가 주어졌을 때, 사용자가 기대하는 연산은 `a = 2 * b + c`
  * 만약 `+` 연산의 반환형에 참조형을 사용할 경우, 아래와 같은 문제 발생:
    ```cpp
    Complex& operator+(const Complex& c) {
      real += c.real;
      img += c.img;

      return *this;
    }
    ```
    1. `a = b + c + b` 문장은 컴파일러에 의해 `a = (b.operator+(c)).operator+(b)`로 변환됨
    2. 참조형을 반환할 경우, `b.operator+(c)` 연산 결과 `b`의 값은 `b + c`로 갱신
    3. 결국 `b + c + b`는 `(b + c) + (b + c)`가 되어 사용자가 기대한 값과 다른 결과 계산
  
  * 올바른 연산자 오버로딩의 구현은 아래와 같음:
    ```cpp
    Complex Complex::operator+(const Complex& c) const {
      Complex temp(real + c.real, img + c.img);

      return temp;
    }
    ```
### 대입 연산자 오버로딩
* 


###### [처음으로](#c-tutorial)
###### [뒤로가기](/tutorial/#index)
---