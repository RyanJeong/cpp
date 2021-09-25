#include <iostream>

using namespace std;

class A {
public:
    int x, y;
    A();
};

/*
    int x, y;
    x=1;
    y=2;
*/
A::A()
{
    x=1;
    y=2;
    cout << "A.x: " << x << ", A.y: " << y << endl;
}

class B {
public:
    int x, y;
    B();
};

/*
    int x = 3;
    int y = 4;
*/
B::B() : x(3), y(4) { cout << "B.x: " << x << ", B.y: " << y << endl; }

class C {
public:
    const int x, y;
    C();
};

/*
C::C()
{
    x=5;
    y=6;
    cout << "C.x: " << x << ", C.y: " << y << endl;
}
*/
C::C() : x(5), y(6) { cout << "C.x: " << x << ", C.y: " << y << endl; }

int main(void)
{
    A a;
    B b;
    C c;

    return 0;
}