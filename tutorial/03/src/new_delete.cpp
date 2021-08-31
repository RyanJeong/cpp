#include <iostream>

int main(void)
{
    int* p = new int;
    *p=16;

    std::cout << *p << std::endl;

    delete p;

    return 0;
}