#include <iostream>

using namespace std;

int main(void) 
{
    cout << "주소를 입력하세요>>";
    char address[100]; 
    cin.getline(address,100,'\n'); // 키보드로부터 주소 읽기

    // 컴퓨터시 프로그램구 c++동 스트링 1-1
    cout << "주소는 " << address << "입니다\n"; // 주소 출력

    return 0;
}