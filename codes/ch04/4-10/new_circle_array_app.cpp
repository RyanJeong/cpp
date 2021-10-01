#include <iostream>

using namespace std;

class Circle {
    int radius; 
public:
    Circle() : radius(1) { }
    ~Circle() { }
    void setRadius(int r) { radius=r; }
    double getArea(void) { return 3.14*radius*radius; }
}; 

int main(void) 
{
    cout << "생성하고자 하는 원의 개수?";
    int n;
    cin>>n; // 원의 개수 입력
    if (n<=0) {
        
        return 0;
    }

    Circle* pArray = new Circle[n];
    for (int i = 0; i<n; i++) {
        cout << "원" << i+1 << ">>"; // 프롬프트 출력
        int radius;
        cin>>radius; // 반지름 입력
        pArray[i].setRadius(radius); 
    }

    int count = 0; // 카운트 변수
    Circle* p = pArray;
    for(int i = 0; i<n; i++) {
        cout << p->getArea() << ((n-1==i) ? "" : ", ");
        if(p->getArea()>=100 && p->getArea()<=200) { 
            ++count;
        }
        ++p;
    }
    cout << endl 
         << "면적이 100에서 200 사이인 원의 개수는 " << count << endl;

    delete[] pArray; // 객체 배열 소멸

    return 0;
}