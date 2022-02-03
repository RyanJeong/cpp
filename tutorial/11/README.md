# C++ Tutorial
## 11 - Type Casting, Default Argument, Iterator 
###### [뒤로가기](/tutorial/#index)
---
### C++ Type Casting
* `static_cast`
  * 일반적인 타입 변환:
    ```cpp
    double d = 3.14;
    int x = static_cast<int>(d);  // int x = (double) d;
    std::cout << x << std::endl;  // 3
    ```

* `const_cast`
  * 객체의 상수성(const)을 제거하는 타입 변환:
    ```cpp
    int func(int* ptr) {
      return *ptr + 5;
    }

    int main() {
      const int val = 10;
      const int* ptr1 = &val;
      // argument of type "const int *" is incompatible with parameter of type
      // "int *"
      // std::cout << func(ptr1);
      int* ptr2 = const_cast<int*>(ptr1);
      std::cout << func(ptr2) << std::endl;  // 15
    }
    ```

* `dynamic_cast`
  * 부모 클래스를 가리키는 포인터를 자식 클래스를 가르키도록 타입 변환(다운 캐스팅)

* `reinterpret_cast`
  * 위험을 감수하고 하는 캐스팅
  * 서로 관련이 없는 포인터들 사이의 캐스팅:
    ```cpp
    int data = 100;
    // now `data` is used as the `address`.
    int* ptr = reinterpret_cast<int*>(data);
    ```

* [WIP] Default Argument

###### [처음으로](#c-tutorial)
###### [뒤로가기](/tutorial/#index)
---
