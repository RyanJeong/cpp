#include <iostream>

using namespace std;

class Box {
    int width, height;
    char fill; // 박스의 내부를 채우는 문자
public:
    Box(int w, int h) { setSize(w,h); fill='*'; }
    void setFill(char f) { fill=f; }
    void setSize(int w, int h) { width=w; height=h; }
    void draw(void); // 박스 그리기
};

void Box::draw(void)
{
    for (int n = 0; n<height; ++n) {
        for (int m = 0; m<width; ++m) {
            cout << fill;
        }
        cout << endl;
    }

    return;
}

int main(void)
{
    Box b(10,2);
    b.draw();

    b.setSize(7,4);
    b.setFill('^');
    b.draw();

    return 0;
}