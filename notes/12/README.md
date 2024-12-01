---
marp: true
theme: notes
style: |
    img[alt~="center"] {
      display: block;
      margin: 0 auto;
    }
math: mathjax
---

# 입출력 스트림 (Input / Output Streams)

![center](Figure_16_1.png)

* 프로그램 내 스트림 클래스를 사용해 인스턴스화하여 사용하는 객체
* 프로그램이 메모리로부터 데이터를 읽어오거나 메모리로 데이터를 내보낼 때 사용하는 인터페이스
  * 외부 소스 (external source)
    * 데이터를 생성 또는 제공하는 역할
    * 외부 소스가 데이터를 메모리로 전달하면 프로그램은 입력 스트림을 사용해 이를 읽어옴
  * 외부 싱크 (external sink)
    * 데이터를 소비 또는 처리하는 역할
    * 프로그램이 출력 스트림을 사용해 데이터를 메모리로 전달하면 외부 싱크는 이를 읽어옴
* 소스와 싱크는 크게 세 가지로 구분
  * 임시 소스 또는 싱크 (temporary source or sink) - 키보드 입력과 모니터 (콘솔 화면)
  * 영구 소스 또는 싱크 (permanent source or sink) - 파일
  * 내부 소스 또는 싱크 (internal source or sink) - C++ 문자열

---

## 스트림

![center](Figure_16_2.png)

* 소스, 싱크는 프로그램에 직접 연결할 수 없음
* **중재자 (mediator)를 통해 데이터를 주고받아야 함**
* 입출력 스트림은 소스, 싱크와 프로그램 간 중재자 역할 수행
  * 입력 스트림 (input stream)은 소스와 프로그램 간 중재 역할
  * 출력 스트림 (output stream)은 싱크와 프로그램 간 중재 역할
* 입출력 스트림은 양방향으로 데이터를 주고받을 수 있음
  * e.g., 파일 스트림 (file stream)
* 소스, 싱크와 프로그램 간 데이터 전달은 **컴퓨터 메모리**를 통해 이루어짐
* **메모리에 저장되는 데이터는 이진 (binary) 형태**이므로 바이트 열 형태로 표현

---

## 데이터 표현 (Data Representation)

![center](Figure_16_3.png)

* 소스와 싱크는 **바이트 열 (a sequence of bytes)** 형태로 데이터를 표현
  * 데이터를 **의미 없이** 바이트 단위로 순차적으로 나열한 형태
  * e.g., `0x41810000`
* 프로그램은 형 (type)을 사용해 데이터를 표현
  * 프로그램 내에서 데이터를 **추상적**으로 표현하기 위한 표현 방법
  * 데이터를 의미 있는 형태로 표현
  * e.g., `0x41810000`를 프로그램에서 IEEE 754 단정도 부동 소수점으로 표현하면 `16.125`
* **스트림은 소스, 싱크와 프로그램 간 데이터 흐름을 관리하는 중간 계층**
  * 입력 스트림은 소스가 생성한 데이터를 읽어 프로그램이 이해할 수 있는 형태로 변환 후 읽어옴
  * 출력 스트림은 프로그램이 데이터를 내보낼 때 싱크가 이해할 수 있는 형태로 변환 후 내보냄

---

### 스트림 버퍼 (Buffer of Streams)

![center](Figure_16_4.png)

* 메모리 상에서 관리되는 스트림이 사용하는 중간 저장소
  * 소스는 입력 스트림 버퍼로 데이터를 보내고, 싱크는 출력 스트림 버퍼로부터 데이터를 읽어옴
* 스트림은 메모리로부터 데이터를 읽어오거나 메모리로 데이터를 내보낼 때 **항상 이진 데이터를 사용**
  * 입력 스트림은 스트림 버퍼로부터 이진 데이터를 읽어와 프로그램에서 요구하는 형으로 **변환**
  * 출력 스트림은 프로그램이 내보낼 데이터를 이진 데이터로 **변환** 후 스트림 버퍼로 내보냄
* 스트림은 텍스트 또는 이진 데이터를 처리할 수 있음
* 소스와 싱크는 스트림과 **동일한 데이터 형식을 처리하도록 설정**해야 함
  * 중간 계층인 스트림이 **데이터를 올바르게 변환**하여 가져오거나 내보내도록 하기 위함
  * e.g., 소스가 텍스트 데이터를 사용하면 입력 스트림도 텍스트 데이터를 처리하도록 설정
* 스트림은 텍스트 데이터 처리가 기본값이며, 필요에 따라 이진 데이터를 처리하도록 설정 가능
  * 스트림 클래스로부터 인스턴스화할 때 설정 가능

---

## 스트림 클래스 (Stream Classes)

![center](Figure_16_5.png)

### `std::ios`

* 가상 기반 클래스이며, 모든 입출력 클래스가 상속 받는 데이터 멤버와 멤버 함수가 구현되어 있음
* 추상 클래스이므로, 인스턴스화 불가

---

### `std::istream`, `std::ostream`, `std::iostream`

* 콘솔 스트림 (console streams) 객체를 위한 클래스
* 키보드로부터 입력 받거나 데이터를 모니터 (콘솔 화면)으로 내보내는 데 필요한 스트림
  * 임시 소스와 임시 싱크를 사용

### `std::ifstream`, `std::ofstream`, `std::fstream`

* 파일 스트림 (file streams) 객체를 위한 클래스
* 파일로부터 입력 받거나 데이터를 파일로 내보내는 데 필요한 스트림
  * 영구 소스와 영구 싱크를 사용

### `std::istringstream`, `std::ostringstream`, `std::stringstream`

* 문자열 스트림 (string streams) 객체를 위한 클래스
* 문자열로부터 입력 받거나 데이터를 문자열로 내보내는 데 필요한 스트림
  * 내부 소스와 내부 싱크를 사용

---

## 스트림 사용을 위한 다섯 단계

1. 스트림 객체를 생성한다.
2. 객체 생성 시 연결하고자 하는 대상 (소스, 싱크)와 연결한다.
3. 스트림을 통해 데이터를 읽어오거나 (입력 스트림) 데이터를 내보낸다 (출력 스트림).
4. 더 이상 스트림을 사용하지 않는다면 연결했던 대상 (소스, 싱크)와 연결을 해제한다.
5. 스트림 객체를 소멸한다.

## 스트림 객체의 특성 (Characteristics of Stream Objects)

* **복사 생성자와 대입 연산자가 없음**
  * 스트림 객체는 내부 상태를 갖고 있음 (e.g., 스트림 버퍼, 버퍼를 가리키는 포인터, etc.)
  * 스트림 객체를 복사 또는 대입할 경우 **데이터 불일치** 또는 **리소스 충돌**이 발생할 수 있음
  * 스트림 객체는 함수로의 값 전달 또는 함수의 반환 값으로 사용할 수 없음
* 스트림 객체는 사용할 때마다 내부 상태가 변하므로 `const` 한정자를 같이 사용할 수 없음
  * 데이터를 입력받거나 출력할 때 스트림 버퍼와 이를 가리키는 포인터가 갱신됨
  * 만약 입출력 과정 중에 오류가 발생할 경우 이를 스트림 내부 상태에 기록함

---

## 스트림 상태 (Stream State)

![center](Figure_16_8.png)

* 스트림 객체들은 데이터를 읽어오거나 내보내는 과정 중에 실패할 수 있음
* 이러한 실패를 관리할 수 있도록 스트림 객체 내에 상태들을 보관
  * `std::ios` 클래스 내에 상태 관련 데이터 멤버 및 멤버 함수가 구현되어 있음
  * `std::ios` 클래스를 상속한 스트림 클래스는 상태 관련 데이터 멤버와 멤버 함수 사용 가능

---

### 스트림 상태 데이터 멤버

| Constants          | Input Stream                  | Output Stream              |
|--------------------|-------------------------------|----------------------------|
| `std::ios::eofbit` | No more characters to extract.| Not applicable.            |
| `std::ios::failbit`| An invalid read operation.    | An invalid write operation.|
| `std::ios::badbit` | Stream integrity is lost.     | Stream integrity is lost.  |
| `std::ios::goodbit`| Everything is fine.           | Everything is fine.        |

```cpp
namespace std {
namespace ios_base {
typedef /*implementation defined*/ iostate;

static constexpr iostate goodbit = 0;
static constexpr iostate badbit  = /* implementation defined */
static constexpr iostate failbit = /* implementation defined */
static constexpr iostate eofbit  = /* implementation defined */

// A data member 'state' can be used with bit masking as following:
iostate state = eofbit | failbit;
}  // ios_base
}  // std
```

---

* `std::ios::eofbit`
  * 입력 스트림에만 적용되는 생태 비트
  * 입력 스트림이 소스의 끝 (EOF, end of file)에 도달했을 때 설정됨
  * EOF에서 읽기 작업은 **실패**하므로 `eofbit`와 `failbit` 둘 다 설정됨
    * `failbit`가 설정됐다면 **`eofbit`가 설정됐는지, 다른 이유 때문인지 확인 필요**
* `std::ios::failbit`
  * 작업 수행 시 내부 논리적인 오류가 발생할 경우 설정됨
    * e.g., EOF에서 데이터 읽기, 문자 데이터를 다른 형태 (e.g., 실수형)로 읽기
  * 스트림 무결성 (integrity)에는 문제가 없는 상태이므로, **스트림 복구 후 재사용 가능**
    * 만약 발생한 오류로 인해 스트림 무결성이 깨졌다면 `badbit`가 동시에 설정될 수 있음
    * `badbit`가 설정된 스트림은 재사용 불가
* `std::ios::badbit`
  * 스트림의 무결성이 깨진 경우 설정됨
    * 메모리 부족으로 인하여 스트림 작업이 중단되는 경우
    * 스트림 내부에서 변환 작업 중 오류 발생으로 인하여 실패하는 경우
    * 스트림 사용 도중 예외가 발생한 경우 (e.g., 디스크 오류로 인한 스트림 작업 실패)
  * **스트림은 더 이상 사용할 수 없는 상태**이며, 스트림을 새로 생성해야 함
* `std::ios::goodbit`
  * `eofbit`, `failbit`, `badbit`가 모두 설정되어 있지 않다면 설정됨
  * 스트림을 사용할 수 있는 정상 상태

---

## 콘솔 스트림 (Console Streams)

* `std::istream`, `std::ostream`, `std::iostream` 클래스로부터 실체화된 객체
* `<iostream>` 헤더를 포함하면 콘솔 스트림 객체를 사용할 수 있음
  * 콘솔 스트림 객체는 프로그램 실행 시 전역 객체로 자동 생성됨

  ```cpp
  // iostream.h
  #include <ios>
  #include <streambuf>
  #include <istream>
  #include <ostream>
  
  namespace std {
    extern istream cin;
    extern ostream cout;
    extern ostream cerr;  // unbuffered
    extern ostream clog;  // buffered
  
    extern wistream wcin;
    extern wostream wcout;
    extern wostream wcerr;
    extern wostream wclog;
  }
  ```

---

### `std::cin`

![center](Figure_16_6.png)

* `std::istream`형 객체이며, 프로그램 실행 시 콘솔 입력 (키보드)과 연결됨
* 프로그램 종료 시 런타임 시스템에 의해 키보드와의 연결이 자동으로 끊어진 뒤 소멸됨
* **시스템이 객체 생성, 소스와의 연결, 소스와의 연결 해제, 객체 소멸을 담당함**
  * 사용자는 생성된 스트림 객체를 사용해 데이터를 처리하기만 하면 됨

---

### `std::cout`, `std::cerr`, `std::clog`

![center](Figure_16_7.png)

* `std::ostream`형 객체이며, 프로그램 실행 시 콘솔 출력 (모니터)과 연결됨
* 프로그램 종료 시 런타임 시스템에 의해 모니터와의 연결이 자동으로 끊어진 뒤 소멸됨
* **시스템이 객체 생성, 싱크와의 연결, 싱크와의 연결 해제, 객체 소멸을 담당함**
  * 사용자는 생성된 스트림 객체를 사용해 데이터를 처리하기만 하면 됨

---

### 콘솔 스트림 객체의 특징

* `std::cout` 객체와 `std::cin` 객체는 **동기화되어 있음**
  * `std::cout` 출력 결과는 바로 싱크로 전달되는 것이 아닌 스트림 버퍼에 **임시 보관*됨
  * `std::cin` 입력 시 `std::cout` 버퍼의 모든 데이터를 플러시 (flush)하도록 동작
    * 플러시가 되어야 스트림 버퍼에 있는 데이터가 싱크로 전달되는 구조
  * 동기화되지 않을 경우 아래와 같은 문제가 발생할 수 있음:

  ```cpp
  std::cout << "Enter a number: "; // not displayed on the screen
  std::cin >> number;              // waiting for user input without any guides
  ```

  * 입출력이 빈번한 상황에서 동기화된 콘솔 스트림 객체를 사용하는 것은 **성능 저하**의 원인이 됨
    * 출력 스트림 버퍼를 플러시할 때마다 **비용** 발생
  * `std::cin` 객체를 다음과 같이 설정하면 `std::cout` 객체과의 동기화를 끊을 수 있음:
  
  ```cpp
  std::cin.tie(nullptr);
  ```

* 출력 콘솔 스트림 객체의 출력 재정의
  * `std::cout` 객체는 운영 체제의 표준 출력 스트림 (`stdout`)에 연결됨
    * 출력 재정의 가능
  * `std::cerr`, `std::clog` 객체는 운영 체제의 표준 오류 스트림 (`stderr`)에 연결됨
    * 출력 재정의 불가
    * 오류 메세지 또는 로깅 메세지가 표준 출력과 혼재될 가능성을 배제하기 위함

---

* `std::cerr`과 `std::clog`의 차이
  * `std::cerr` 객체는 프로그램 상 발생한 오류 메세지를 즉시 출력하는 용도로 사용
    * 스트림 버퍼에 데이터를 보관하지 않고 즉시 싱크로 내보냄
  * `std::clog` 객체는 프로그램의 디버깅 또는 로깅 메세지를 출력하는 용도로 사용
    * 스트림 버퍼에 데이터를 보관한 뒤, 버퍼가 플래시되는 조건을 만족하면 싱크로 내보냄

* 출력 버퍼 플래시 조건
  * 명시적으로 플러시를 사용한 경우

  ```cpp
  std::clog << "A log message";
  std::clog.flush(); // flust the buffer explicitly
  ```

  * 스트림이 닫힐 때

  ```cpp
  #include <iostream>

  int main() {
    std::clog << "A log message"; // buffered
    return 0;  // the std::clog will be destroyed and the buffer will flush 
  }
  ```

  * 출력 스트림 버퍼가 가득 찬 경우

---
