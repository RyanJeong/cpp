# C++ Tutorial
## 05 - 오버로딩
###### [뒤로가기](/tutorial/#index)
---
### 오버로딩(<i>overloading</i>)
* 이름(<i>name</i>)이 같은 함수라도 함수의 매개변수 형태에 따라 적합한 함수를 호출
    * 같은 이름의 함수를 여러 개 정의해 사용하는 것(한 이름에 과적하는 느낌, overload)
    ```cpp
    #include <iostream>

    void print(int x) { std::cout << "int: " << x << std::endl; }
    void print(char x) { std::cout << "char: " << x << std::endl; }
    void print(double x) { std::cout << "double: " << x << std::endl; }

    int main(void)
    {
        int a = 5;
        char b = 'a';
        double c = 3.14;

        print(a);
        print(b);
        print(c);

        return 0;
    }
    ```

#### [오버로딩 과정(The argument matching sequence)](https://www.learncpp.com/cpp-tutorial/function-overload-resolution-and-ambiguous-matches/):
1. 호출 시 전달인자와 함수의 매개변수가 정확히 일치하는 함수를 찾는다.
2. 1번 단계에서 함수를 찾지 못했다면, 승격(promotion)을 통해 일치하는 함수를 찾는다:
    1. `signed char` or `signed short` can be converted to `int`
    2. `unsigned char` or `unsigned short` can be converted to `int` if it can hold its entire value range, and `unsigned int` otherwise
        * <b>IP16L32</b>에서는 `int`형으로 `unsigned short`를 수용하지 못할 수 있음
    3. `float` can be converted to `double`
    4. an unscoped enumeration type whose underlying type is not fixed can be converted to the <b>first type from the following list able to hold their entire value range</b>: `int`, `unsigned int`, `long`, `unsigned long`, `long long`, or `unsigned long long`, extended integer types with higher conversion rank (in rank order, signed given preference over unsigned) 
3. 승격을 통해서도 함수를 찾지 못했다면, 표준 변환(standard conversion)을 통해 일치하는 함수를 찾는다.
    * 기존의 숫자 형은 다른 숫자 형으로 변환 (ex. `double` -> `char`, `short`, ...)
    * 열거형 또한 다른 숫자 형으로 변환 (ex. `enum` -> `int`, `int` -> `float`, `double`, ...)
    * 0은 포인터 형 및 숫자 형과 일치하도록 변환 (ex. 0 -> `char*` or `float`)
    * 포인터는 `void` 형 포인터와 일치하도록 변환
4. 표준 변환을 통해서도 함수를 찾지 못했다면, 사용자 정의 변환(user-defined conversion)을 통해 일치하는 함수를 찾는다.

* 위 과정을 통해 컴파일러가 적절한 함수를 찾지 못한다면, 오류 발생(ambiguous)
* 오버로딩 예제 1:
    ```cpp
    #include <iostream>

    void print(int x) { std::cout << "int: " << x << std::endl; }
    void print(double x) { std::cout << "double: " << x << std::endl; }

    int main(void)
    {
        int a = 5;
        char b = 'a';
        double c = 3.14;

        print(a); // call print(int x)
        print(b); // call print(int x); char can be converted to int
        print(c); // call print(double x)

        return 0;
    }
    ```

* 오버로딩 예제 2:
    ```cpp
    #include <iostream>

    void print(int x) { std::cout << "int: " << x << std::endl; }
    void print(char x) { std::cout << "char: " << x << std::endl; }

    int main(void)
    {
        int a = 5;
        char b = 'a';
        double c = 3.14;

        print(a); // call print(int x)
        print(b); // call print(char x)
        print(c); // ERROR; ambiguous call to overloaded function

        return 0;
    }
    ```
    * 오버로드된 함수 중 `double` 형을 매개변수로 받는 함수가 없기 때문에 적절한 함수를 결정해야 함
    * 승격을 시도했으나, `double` 형에 대한 승격 내용은 없으므로 표준 변환 단계로 이동
    * 표준 변환을 시도하여 `double`을 다른 숫자 형으로의 변환
        * 오버로딩된 함수의 매개변수 형이 `int`, `char`
        * 표준 변환을 통해 `double`은 `int`가 될 수도, `char`가 될 수도 있음
        * 어떠한 함수를 호출해야 하는지 모호한(ambiguous) 상황이므로 오류 발생

###### [처음으로](#c-tutorial)
###### [뒤로가기](/tutorial/#index)
---
