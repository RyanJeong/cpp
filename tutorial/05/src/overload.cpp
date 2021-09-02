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