#include <iostream>

using namespace std;

class Circle {
private:
    int radius; 
public:
    Circle() { radius=1; }
    Circle(int r) { radius=r; }
    double getArea(void) { return 3.14*radius*radius; }
}; 

int main(void) 
{
    Circle donut;
    Circle pizza(30);

    // 객체 이름으로 멤버 접근
    cout << donut.getArea() << endl;
    cout << pizza.getArea() << endl;

    // 객체 포인터로 멤버 접근
    Circle* p;
    p=&donut;
    cout << p->getArea() << endl; 
    cout << (*p).getArea() <<endl;

    p=&pizza; 
    cout << p->getArea() << endl; 
    cout << (*p).getArea() << endl;

    return 0;
}