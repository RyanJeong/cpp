#include <iostream> 

using namespace std; 

class Rectangle { // Rectangle 클래스 선언
public:
	int width; 
	int height; 
	int getArea(void); // 면적을 계산하여 리턴하는 함수
};

int Rectangle::getArea(void) 
{

	return width*height;
}

int main(void) 
{
	Rectangle rect;
	rect.width=3;
	rect.height=5;
	cout << "사각형의 면적은 " << rect.getArea() << endl;

	return 0;
}
