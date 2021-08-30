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