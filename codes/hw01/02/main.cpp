#include <iostream>

using namespace std;

class Ram {
    char mem[100*1024]; // 100 KB 메모리.
                        // 한 번지는 한 바이트이므로 char 타입 사용
    int size;
public:
    Ram(); // mem 배열을 0으로 초기화하고, size를 100*1024로 초기화
    ~Ram(); // "메모리 제거됨" 문자열 출력
    char read(int address); // address 주소의 메모리 바이트 반환
    void write(int address, char value); // address 주소에 한 바이트로 value 저장
};

int main(void)
{
    Ram ram;
    ram.write(100,20); // 100 번지에 20 저장
    ram.write(101,30); // 101 번지에 30 저장
    char res = ram.read(100)+ram.read(101); // 20+30=50
    ram.write(102,res); // 102 번지에 50 저장
    
    // 102 번지 값 출력
    cout << "102 번지의 값 = " << (int) ram.read(102) << endl;

    return 0;
}