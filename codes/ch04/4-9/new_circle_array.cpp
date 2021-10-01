// copy 4-7
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
    Circle *pArray = new Circle[3];

    pArray[0].setRadius(10);
    pArray[1].setRadius(20);
    pArray[2].setRadius(30);

    cout << "인덱스:" << endl;
    for (int i = 0; i<3; i++) {
        cout << pArray[i].getArea() << endl;
    }

    Circle *p = pArray;
    cout << "포인터:" << endl;
    for(int i = 0; i<3; i++) {
        cout << p->getArea() << endl;
        ++p;
    }
    delete[] pArray;

    return 0;
}