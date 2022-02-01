# C++ Tutorial
## 03 - `new`, `delete`
### Heap
* 컴파일 시 모든 변수의 주소값이 확정되어야 하는 규칙은 프로그램 작성 시 많은 제약을 일으킴
* 프로그램 실행 시 자유롭게 할당하고 해제할 수 있는 공간이 필요하며, 이러한 행위를 허용하는 공간을 heap 영역으로 정의
* 컴파일러에 의해 관리되는 stack 영역에 비해 사용자에 의해 관리되는 heap 영역은 사용자가 잘 관리해야 함
* `new` 함수와 `delete` 함수는 heap 영역에 메모리를 할당하거나 할당된 메모리를 반환하는 기능 수행:
  ```cpp
  #include <iostream>

  int main() {
    int* p = new int;
    *p = 16;

    std::cout << *p << std::endl;

    delete p;

    return 0;
  }
  ```

### `new`, `delete`
* `new`:
  * `T* ptr = new T;`
  * `T` 크기의 공간을 heap 영역에 동적 할당 후 해당 공간을 가리키는 주소를 `T`형 포인터 `ptr`에 대입

* `delete`:
  * `delete ptr;`
  * 포인터 `ptr`가 가리키는 대상의 공간 해제
  * <b>사용자가 `new`를 사용해 heap 영역에 동적 할당한 대상만 해제 가능</b>
    * Heap 영역이 아닌 다른 영역에 있는 공간을 `delete` 키워드를 사용해 해제하려고 한다면 오류 발생

* `new`를 이용한 배열 할당:
  ```cpp
  #include <iostream>

  int main() {
    const int size = 10;
    int* arr = new int[size];

    // do something ...

    delete[] arr;

    return 0;
  }
  ```
  * `T* ptr = new T[size];`
    * `T` 크기의 메모리를 `size`개 연속적으로 heap 영역에 동적 할당 후 해당 공간을 가리키는 주소를 `T`형 포인터 `ptr`에 대입

  * `delete[] ptr`
    * `new []`로 할당한 대상 해제

* `new`를 이용한 2차원 이상의 배열 할당:
  ```cpp
  #include <iostream>

  int main() {
    const int sz_row = 5;
    const int sz_col = 6;

    int** arr = new int*[sz_row];
    for (int i = 0; i < sz_row; ++i)
      arr[i] = new int[sz_col];

    int cnt = 0;
    for (int i = 0; i < sz_row; ++i)
      for (int j = 0; j < sz_col; ++j)
        arr[i][j] = cnt++;

    for (int i = 0; i < sz_row; ++i) {
      for (int j = 0; j < sz_col; ++j)
        std::cout << arr[i][j] << ' ';
      std::cout << '\n';
    }

    for (int i = 0; i < sz_row; ++i)
      delete[] arr[i];
    delete[] arr;

    return 0;
  }
  ```
  * <b>한 번에 모든 요소를 담을 수 있는 메모리 공간을 할당하는 방법도 있지만, 이는 메모리 단편화로 인해 연속된 메모리 공간이 확보되지 않는다면 할당에 실패할 수 있음</b>

###### [뒤로가기](/tutorial/#index)
---
### SUBTITLE

###### [처음으로](#c-tutorial)
###### [뒤로가기](/tutorial/#index)
---