#include <iostream>
#include <string>  // string class

using namespace std;

int main(void) 
{
    // string song("Falling in love with you"); // 문자열 song
    // string elvis("Elvis Presley"); // 문자열 elvis
    string song = "Falling in love with you";
    cout << song + "를 부른 가수는"; // + 로 문자열 연결

    string elvis = "Elvis Presley";
    cout << "(힌트 : 첫글자는 " << elvis[0] << ")?";  // [] 연산자 사용

    string singer; // 문자열 singer
    getline(cin,singer); // 문자열 입력
    if (singer==elvis) {  // 문자열 비교
        cout << "맞았습니다.";
    }
    else {
        cout << "틀렸습니다. "+ elvis + "입니다." << endl; // +로 문자열 연결
    } 

    return 0;
}