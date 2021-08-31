# C++ Tutorial
## 03 - `new`와 `delete`
###### [뒤로가기](/tutorial/#index)
---
### Heap 영역으로의 동적 할당과 해제
* C언어에서의 `malloc`은 C++에서 `new`와 대응됨
* C언어에서의 `free`는 C++에서 `delete`와 대응됨

```cpp
#include <iostream>

int main(void)
{
    int* p = new int;
    *p=16;

    std::cout << *p << std::endl;

    delete p;

    return 0;
}
```
* `int* p = new int;`
    * `T* ptr = new T;`
    * `T` 크기의 공간을 동적 할당 후 해당 공간의 주소를 `T`형 포인터 `p`에 대입

* `delete p`
    * 포인터 `p`가 가리키는 대상의 공간 해제
    * 사용자가 `new`를 사용해 동적 할당한 대상만 해제 가능
    * Heap 영역이 아닌 다른 영역에 있는 공간을 `delete` 키워드를 사용해 해제하려고 한다면 오류 발생

### 배열 동적 할당
```cpp
#include <iostream>

int main(void)
{
    const int size = 10;
    int* arr = new int[size];

    // TODO

    delete[] arr;

    return 0;
}
```
* `int* arr = new int[size];`
    * `T* ptr = new T[size];`
    * `T` 크기의 메모리를 `size`개 연속적으로 동적 할당 후, `T`형 포인터 `ptr`에 새로 할당한 공간의 주소 대입

* `delete[] arr`
    * `new []`로 할당한 대상 해제

* `new`를 이용한 2차원 이상의 배열 동적 할당
    > portable ISO C++ is limited to only the first dimension being variable
    * 아래와 같은 방법으로 할당:
        ```cpp
        const int sz_row = 5;
        const int sz_col = 6;

        int** arr = new int*[sz_row];
        for (int i = 0; i<sz_row; ++i) {
            arr[i]=new int[sz_col];
        }

        // TODO

        for (int i = 0; i<sz_row; ++i) {
            delete[] arr[i];
        }
        delete[] arr;
        ```

###### [처음으로](#c-tutorial)
###### [뒤로가기](/tutorial/#index)
---
