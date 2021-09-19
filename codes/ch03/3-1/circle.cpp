#include <iostream> 

using namespace std; 

class Circle {
public:
	int radius; 
	double getArea(void); 
}; 

double Circle::getArea(void) 
{

	return 3.14*radius*radius;
}

int main(void) 
{
	Circle donut; 
	donut.radius=1; // donut 객체의 반지름을 1로 설정
	double area = donut.getArea(); // donut 객체의 면적 알아내기
	cout << "donut 면적은 " << area << endl;

	Circle pizza; 
	pizza.radius=30; // pizza 객체의 반지름을 30으로 설정
	area=pizza.getArea(); // pizza 객체의 면적 알아내기
	cout << "pizza 면적은 " << area << endl;

    return 0;
}