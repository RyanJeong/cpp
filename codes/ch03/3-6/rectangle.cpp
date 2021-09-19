#include <iostream> 

using namespace std; 

class Rectangle { 
public:
	int width, height; 
	Rectangle();
	Rectangle(int w, int h);
	Rectangle(int length);
	bool isSquare(void);
};

Rectangle::Rectangle() : Rectangle(1) { }

Rectangle::Rectangle(int w, int h) 
{
	width=w; 
	height=h;
}

Rectangle::Rectangle(int length) 
{
	width=height=length;
}

bool Rectangle::isSquare(void) 
{
	if (width==height) {
		
		return true;
	}
	else {
		
		return false;
	}
}

int main(void) 
{
	Rectangle rect1; 
	Rectangle rect2(3,5);
	Rectangle rect3(3);

	if (rect1.isSquare()) {
		cout << "rect1은 정사각형이다." << endl;
	}
	if (rect2.isSquare()) {
		cout << "rect2는 정사각형이다." << endl;
	}
	if (rect3.isSquare()) {
		cout << "rect3는 정사각형이다." << endl;
	}

	return 0;
}