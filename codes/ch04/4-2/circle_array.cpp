#include <iostream>

using namespace std;

class Circle {
    int radius; 
public:
    Circle() : radius(1) { }
    Circle(int r) : radius(r) { }
    void setRadius(int r);
    double getArea(void); 
}; 

inline void Circle::setRadius(int r)
{
    radius=r;

    return;
}

inline double Circle::getArea(void) 
{

    return 3.14*radius*radius;
}

int main(void) 
{
    Circle circleArray[3];

    circleArray[0].setRadius(10);
    circleArray[1].setRadius(20);
    circleArray[2].setRadius(30);

    for (int i = 0; i<3; i++) { 
        cout << "Circle " << i << "의 면적은 " << circleArray[i].getArea() << endl;
    }

    Circle *p;
    p=circleArray;
    for (int i = 0; i<3; i++) { 
        cout << "Circle " << i << "의 면적은 " << p->getArea() << endl;
        p++; 
    }

    return 0;
}