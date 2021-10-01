#include <iostream>

using namespace std;

class Circle {
    int radius; 
public:
    Circle(); 
    Circle(int r);
    ~Circle();
    void setRadius(int r) { radius=r; }
    double getArea(void) { return 3.14*radius*radius; }
}; 

inline Circle::Circle() 
{
    radius=1;
    cout << "생성자 실행, radius = " << radius << endl;
}

inline Circle::Circle(int r) 
{
    radius=r;
    cout << "생성자 실행, radius = " << radius << endl;
}

inline Circle::~Circle() 
{
    cout << "소멸자 실행, radius = " << radius << endl;
}

int main(void) 
{
    Circle *p, *q;
    p = new Circle;
    q = new Circle(30);

    cout << p->getArea() << endl 
         << q->getArea() << endl;

    delete p; 
    delete q;

    return 0;
}