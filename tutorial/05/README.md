# C++ Tutorial
## 05 - 오버로딩
###### [뒤로가기](/tutorial/#index)
---
### 오버로딩(<i>overloading</i>)
* 이름(<i>name</i>)이 같은 함수라도 함수의 매개변수 형태에 따라 적합한 함수를 호출
    * 같은 이름의 함수를 여러 개 정의해 사용하는 것(과적, overload)
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

#### 오버로딩 과정:
* [Implicit Conversion](https://en.cppreference.com/w/cpp/language/implicit_conversion)
1. 호출 시 전달인자와 함수의 매개변수가 정확히 일치하는 함수를 찾는다.
2. 1번 단계에서 함수를 찾지 못했다면, 승격(promotion)을 통해 일치하는 함수를 찾는다:
    1. `signed char` or `signed short` can be converted to `int`
    2. `unsigned char` or `unsigned short` can be converted to `int` if it can hold its entire value range, and `unsigned int` otherwise
        * <b>IP16L32</b>에서는 `int`형으로 `unsigned short`를 수용하지 못할 수 있음
    3. `float` can be converted to `double`
    4. an unscoped enumeration type whose underlying type is not fixed can be converted to the <b>first type from the following list able to hold their entire value range</b>: `int`, `unsigned int`, `long`, `unsigned long`, `long long`, or `unsigned long long`, extended integer types with higher conversion rank (in rank order, signed given preference over unsigned) 
3. 승격을 통해서도 함수를 찾지 못했다면, 표준 변환(conversion)을 통해 일치하는 함수를 찾는다.
4. 변환을 통해서도 함수를 찾지 못했다면, 사용


###### [처음으로](#c-tutorial)
###### [뒤로가기](/tutorial/#index)
---
