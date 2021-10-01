// copy 4-2
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
    Circle circles[2][3];

    circles[0][0].setRadius(1);
    circles[0][1].setRadius(2);
    circles[0][2].setRadius(3);
    circles[1][0].setRadius(4);
    circles[1][1].setRadius(5);
    circles[1][2].setRadius(6);

    for (int i = 0; i<2; i++) {
        for (int j = 0; j<3; j++) {
            cout << "Circle [" << i << "," << j 	<< "]의 면적은 ";
            cout << circles[i][j].getArea() <<endl;
        }
    }

    return 0;
}