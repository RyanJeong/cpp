* A **constexpr** symbolic constant must be given a value that is known at compile time. For example:
```C++
constexpr int max = 100;
void use(int n)
{
    constexpr int c1 = max+7; // OK: c1 is 107
    constexpr int c2 = n+7;   // error: we don’t know the value of c2

    // …
}
```

* To handle cases where the value of a “variable” that is initialized with a value that is not known at compile time but never changes after initialization, C++ offers a second form of constant (a **const**):
```C++
constexpr int max = 100;

void use(int n)
{
    constexpr int c1 = max+7; // OK: c1 is 107
    const int     c2 = n+7;   // OK, but don’t try to change the value of c2

    // …

    c2 = 7; // error: c2 is a const
}
```

* Such “**const** variables” are very common for two reasons:
    * C++98 did not have **constexpr**, so people used **const**.
    * “Variables” that are not constant expressions (their value is not known at compile time) but do not change values after initialization are in themselves widely useful.
