# C++ Tutorial
## 02 - `reference`
* 표현식 `int& a = i;`이 주어졌을 때, `a`는 `i`의 레퍼런스
  * `a`는 `i`의 또 다른 이름으로써 사용할 것임을 컴파일러에 알림
  * 레퍼런스를 대상으로 어떠한 연산을 수행하면, 해당 레퍼런스가 가리키는 대상에 연산을 수행하는 것과 동일한 결과를 수행
* 포인터와 상당히 유사하나, 몇 가지 차이를 보임:
  * 레퍼런스는 반드시 대상이 될 이름이 있어야 함:
    ```c++
    int& ref;  // error!
    int* ptr;  // OK!
    ```
  
  * 레퍼런스는 한 번 가리키는 대상을 변경하지 못 함:
    ```c++
    int a = 10;
    int& ref = a;   // Now `ref` is references to `a`
    int* ptr = &a;  // Now `ptr` is points to `a` 

    int b = 20;
    ref = b;   // It is equal to `a` = `b`;
    ptr = &b;  // Now `ptr` is points to `b` 
    ```
  
  * 레퍼런스는 메모리에 존재하지 않을 수 있음:
    ```c++
    int a = 100;
    int* ptr = &a;  // take up 4 or 8 bytes of memory
    int& ref = a;   // do not take up memory; replace 'ref' with 'a'
    ```

  * 어떤 함수의 매개변수가 포인터라면 이는 메모리 상에 할당되지만, 어떤 함수의 매개변수가 레퍼런스라면 이는 메모리에 할당되지 않고 레퍼런스의 대상으로 치환됨:
    ```cpp
    #include <iostream>

    void swap_ptr(int*, int*);
    void swap_ref(int&, int&);

    int main() {
      int a = 3;
      int b = 4;
      int x = 3;
      int y = 4;

      // swap via pointer
      std::cout << "Before: " << '\n'
                << "a: " << a << ", b: " << b << '\n'
                << "[main]address of variable 'a': " << &a << '\n'
                << "[main]address of variable 'b': " << &b << '\n';
      swap_ptr(&a, &b);
      std::cout << "After : " << '\n'
                << "a: " << a << ", b: " << b << '\n';

      // swap via reference
      std::cout << "Before: " << '\n'
                << "x: " << x << ", y: " << y << '\n'
                << "[main]address of variable 'x': " << &x << '\n'
                << "[main]address of variable 'y': " << &y << '\n';
      swap_ref(x, y);
      std::cout << "After : " << '\n'
                << "x: " << x << ", y: " << y << '\n';

      return 0;
    }

    void swap_ptr(int* a, int* b) {
      int tmp;

      tmp = *a;
      *a = *b;
      *b = tmp;
      std::cout << "[swap]address of variable 'a': " << &a << '\n'
                << "[swap]address of variable 'b': " << &b << '\n';
    }

    void swap_ref(int& x, int& y) {
      int tmp;

      tmp = x;
      x = y;
      y = tmp;
      std::cout << "[swap]address of variable 'x': " << &x << '\n'
                << "[swap]address of variable 'y': " << &y << '\n';
    }
    ```
    ```text
    Before: 
    a: 3, b: 4
    [main]address of variable 'a': 0x7ffe82301838
    [main]address of variable 'b': 0x7ffe8230183c
    [swap]address of variable 'a': 0x7ffe82301808
    [swap]address of variable 'b': 0x7ffe82301800
    After : 
    a: 4, b: 3
    Before: 
    x: 3, y: 4
    [main]address of variable 'x': 0x7ffe82301840
    [main]address of variable 'y': 0x7ffe82301844
    [swap]address of variable 'x': 0x7ffe82301840
    [swap]address of variable 'y': 0x7ffe82301844
    After : 
    x: 4, y: 3
    ```

* 포인터 대신 레퍼런스를 사용하면 더욱 간결하게 코드를 작성할 수 있음

### 상수 레퍼런스
* 상수(<i>constant</i>)는 <b>변하지 않는 변수</b>
* 리터럴(<i>literal</i>)은 <b>메모리 상에 존재하는 변하지 않는 대상(<i>object</i>)</b>
  * `3`
  * `ABC`
  * `x`
  * `1.414`
  * `...`

* 레퍼런스는 리터럴을 가리킬 수 없음:
  ```cpp
  int& ref = 4;
  ref = 10;  // ERROR!
  ```
  ```text
  error C2440: 'initializing' : cannot convert from 'int' to 'int &'
  ```
  * `ref = 10` 표현식은 `4 = 10`과 같으며, 리터럴은 메모리 상에 존재하는 변하지 않는 객체이므로 해당 동작은 위법(illegal)임
  * 따라서 일반 레퍼런스는 리터럴을 가리킬 수 없음

* 레퍼런스를 사용해 리터럴을 가리키고자 할 때, 아래와 같이 코드를 수정해야 함:
  ```cpp
  const int& ref = 4;
  int a = ref // OK!
  ```
  * 표현식 `int a = ref`는 `a = 4`와 동일

### 레퍼런스의 배열과 배열의 레퍼런스
* 레퍼런스의 배열은 <b>위법(illegal)</b>:
  ```c++
  int a = 3;
  int b = 4;
  int& arr[2] = { a , b };
  ```
  ```text
  error C2234: 'arr' : arrays of references are illegal
  ```
  > In CPP Standard 8.3.2/4:
  There shall be no references to references, no arrays of references, and no pointers to references

  * 배열 이름은 배열 시작 주소를 가리키며, 배열 이름을 사용해 첨자 연산, 또는 포인터 연산을 통해 각 요소에 접근할 수 있음
  *  레퍼런스의 배열은 각 요소들의 주소가 선형(linear)하다는 보장이 없으며, 따라서 위 연산들을 사용할 수 없음

* 배열의 레퍼런스는 사용 가능:
  ```cpp
  int a[3] = { 1, 2, 3 };
  int (&ref1)[3] = a;
  int b[3][2] = { 6, 5, 8, 7, 2, 1 };
  int (&ref2)[3][2] = b;
  ```
  * `ref1`는 `a`를 가리키는 레퍼런스
  * 포인터와는 다르게 레퍼런스는 <b>크기</b>가 같이 명시되어야 함 (Is it linear?)



###### [뒤로가기](/tutorial/#index)
---
### SUBTITLE

###### [처음으로](#c-tutorial)
###### [뒤로가기](/tutorial/#index)
---