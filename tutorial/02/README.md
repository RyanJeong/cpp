# C++ Tutorial
## 02 - 레퍼런스 소개
###### [뒤로가기](/tutorial/#index)
---
### 레퍼런스(reference)
* <i>type</i> 앞에 `&`를 붙이면 해당 <i>type</i>의 레퍼런스를 사용할 수 있음
* 표현식 `int& a = i;`이 주어졌을 때, `a`는 `i`의 레퍼런스
* 레퍼런스는 가리키는 <i>name</i>의 또 다른 이름(일종의 변수)로써 사용 가능
    * 레퍼런스를 대상으로 어떠한 연산을 수행하면, 해당 레퍼런스가 가리키는 대상에 연산을 수행하는 것과 동일한 결과를 수행
* 함수 호출 시 <i>call by value</i> 대신 <i>call by reference</i>를 사용하면 메모리 복사 시 주소만 복사하면 됨에 따라 규모가 큰 구조체 등을 전달인자로 넘겨주는 상황에서 성능상으로 큰 이점을 가져옴

```cpp
#include <iostream>

void swap_ptr(int*, int*);
void swap_ref(int&, int&);

int main(void)
{
    int a = 3;
    int b = 4;
    int x = 3;
    int y = 4;

    // swap via pointer
    std::cout << "Before: " << '\n'
              << "a: " << a << ", b: " << b << '\n'
              << "[main]address of variable 'a': " << &a << '\n'
              << "[main]address of variable 'b': " << &b << '\n';
    swap_ptr(&a,&b);
    std::cout << "After : " << '\n'
              << "a: " << a << ", b: " << b << '\n';

    // swap via reference
    std::cout << "Before: " << '\n'
              << "x: " << x << ", y: " << y << '\n'
              << "[main]address of variable 'x': " << &x << '\n'
              << "[main]address of variable 'y': " << &y << '\n';
    swap_ref(x,y);
    std::cout << "After : " << '\n'
              << "x: " << x << ", y: " << y << '\n';

    return 0;
}

void swap_ptr(int* a, int* b)
{
    int tmp;

    tmp=*a;
    *a=*b;
    *b=tmp;
    std::cout << "[swap]address of variable 'a': " << &a << '\n'
              << "[swap]address of variable 'b': " << &b << '\n';

    return;
}
void swap_ref(int& x, int& y)
{
    int tmp;

    tmp=x;
    x=y;
    y=tmp;
    std::cout << "[swap]address of variable 'x': " << &x << '\n'
              << "[swap]address of variable 'y': " << &y << '\n';

    return;
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
* 어떤 함수의 매개변수가 포인터일 때, 해당 매개변수는 메모리 상에 새로 할당됨
* 어떤 함수의 매개변수가 레퍼런스일 때, 해당 레퍼런스는 메모리에 할당되는 것이 아닌, 레퍼런스의 대상을 바로 가리킴
    * [Reference declaration](https://en.cppreference.com/w/cpp/language/reference)
        > References are not objects; they do not necessarily occupy storage, although the compiler may allocate storage if it is necessary to implement the desired semantics (e.g. a non-static data member of reference type usually increases the size of the class by the amount necessary to store a memory address).
    * 레퍼런스에 연산을 한다면, 레퍼런스의 대상에 연산을 한 것과 동일한 효과를 냄
    * <b>컴파일러는 레퍼런스 자리에 레퍼런스가 가리키는 대상으로 바꾸어 처리</b>

#### 상수와 레퍼런스
* 상수(<i>constant</i>)는 변하지 않는 <b>변수</b>를 의미
* 리터럴(<i>literal</i>)은 메모리 상에 존재하는 변하지 않는 <b>대상(<i>object</i>)</b>을 의미
    `3, "ABC", 'x', 1.414, ...`

* 레퍼런스는 리터럴을 가리킬 수 없음
    ```cpp
    int& ref = 4;
    ref=10; // ERROR!
    ```
    * 위와 같은 코드가 있을 때, `ref=10` 표현식은 `4=10`과 같으며, 리터럴은 메모리 상에 존재하는 변하지 않는 객체이므로 해당 동작은 위법(illegal)임
    * 따라서 일반 레퍼런스는 리터럴을 가리킬 수 없음
        ```text
        error C2440: 'initializing' : cannot convert from 'int' to 'int &'
        ```

* 레퍼런스가 리터럴을 가리키고자 할 때, 아래와 같이 코드를 수정해야 함:
    ```cpp
    const int& ref = 4;
    int a = ref // OK!
    ```
    * 표현식 `int a = ref`는 `a = 4`와 같이 동작함

#### 레퍼런스의 레퍼런스, 레퍼런스의 배열, 레퍼런스의 포인터
```text
There shall be no references to references, no arrays of references, and no pointers to references
```
* 배열 레퍼런스를 <b>굳이</b> 사용하고자 한다면:
    ```cpp
    int a[3] = {1,2,3};
    int (&ref)[3] = a;
    ```
    * `ref`는 레퍼런스이며, `int` 형을 가리키는데 크기가 3인 배열이며, 그 대상이 `a`
    * `ref`는 배열 `a`를 가리키는 레퍼런스

* <i>Dangling reference</i>
    ```cpp
    int& func(void)
    {
        int a = 3;

        return a;
    }

    int main(void)
    {
        int b = func();
        b = 3; // ERROR! segmentation fault

        return 0;
    }
    ```
    * `func()` 함수는 컴파일러에 의해 `int& tmp = a`으로 처리되고, 함수는 `tmp`를 반환
    * `main()`에서의 변수 `b`는 컴파일러에 의해 `int b = tmp`로 처리
    * 함수 `func()`가 종료됨에 따라 지역 변수 `a`는 소멸되며, 결국 반환 변수 `tmp` 또한 소멸됨
    * 따라서, `main()`의 변수 `b`는 가리키는 대상이 <b>모호</b>해짐
    * 모호한 대상(이미 할당이 해제된)에 참조하려고 한다면 이는 오류를 반환

    ```cpp
    int& func(int& a)
    {
        a=5;
        
        return a;
    }

    int main(void)
    {
        int x = 2;
        int y = func(x); // int& y = x
        y=4; // OK!

        return 0;
    }
    ```
    * `func()` 함수는 컴파일러에 의해 `int& tmp = a`로 처리
        * `a`는 `main()`에서의 변수 `x`를 가리키는 레퍼런스이므로 결국 `tmp`는 `main()`의 `x`를 가리키는 레퍼런스
    * `int y = func(x)`는 `int y = tmp`로 처리되며, 이때 `tmp`는 `main()`의 `x`를 가리키는 레퍼런스이므로 결국 `int y = x`와 동치
    * 따라서 <i>dangling reference</i>가 발생하지 않음

    ```cpp
    int func(void)
    {
        int a = 5;

        return a;
    }

    int main(void)
    {
        int& c = func(); // int& c = 5;
                         // c = 4; // ???

        return 0;
    }
    ```
    * `func()`은 반환 값인 `a`, 즉 `a`가 가지고 있는 값인 5로 평가됨(evaluated)
    * `int& c = func()`는 `int& c = 5`와 동치이며, 5는 상수이자 리터럴이므로 <b>일반 레퍼런스가 가리킬 수 없음</b>
        * 레퍼런스를 참조해 해당 객체의 값을 바꿀 수 있기 때문이며, 이러한 행위는 위법(illegal)

    ```cpp
    int func(void)
    {
        int a = 5;

        return a;
    }

    int main(void)
    {
        const int& x = func(); // const int& x = 5;, read-only

        std::cout << "x: " << x << std::endl;

        return 0;
    }
    ```
    * `func()`은 반환 값인 `a`, 즉 `a`가 가지고 있는 값인 5로 평가됨(evaluated)
    * `const int& x = func()`는 `const int& x = 5`와 동치이며, 5는 상수이자 리터럴이므로 <b>상수 레퍼런스가 가리킬 수 있음</b>
        * 레퍼런스 대상을 읽기만 할 수 있으므로 자연스럽게 <b>상수 레퍼런스가 가리키는 객체를 보호할 수 있음</b>

* 정리하면, 임의의 함수 반환형이 레퍼런스일 때, 해당 함수의 지역변수를 가리키는 레퍼런스 반환 시 <b>해당 함수 종료와 동시에 지연변수는 소멸</b>되며, 결국 모호한 곳을 가리키는 상태가 됨에 따라 런타임 오류(seg. fault)가 발생
    * 레퍼런스 형 반환 시 함수 종료에 따른 반환 대상의 소멸 여부를 따져야 함

###### [처음으로](#c-tutorial)
###### [뒤로가기](/tutorial/#index)
---
