#include <iostream>
#include <cstring>

using namespace std;

int main(void) 
{
    cout << "가위 바위 보 게임을 합니다. 가위, 바위, 보 중에서 입력하세요." << endl;
    
    // 입력 받기
    char s[10];
    cout << "로미오>>";
    cin>>s;

    char t[10];
    cout << "줄리엣>>";
    cin>>t;

    // 틀린 입력 골라내기
    if (strcmp(s,"가위")!=0 && strcmp(s,"바위")!=0 && strcmp(s,"보")!=0) {
        cout << "로미오의 입력이 틀렸습니다." << endl;

        return 0;
    }
    if (strcmp(t,"가위")!=0 && strcmp(t,"바위")!=0 && strcmp(t,"보")!=0) {
        cout << "줄리엣의 입력이 틀렸습니다." << endl;

        return 0;
    }

    // 승자 결정
    if (strcmp(s,"가위")==0 && strcmp(t,"보")==0) {
        cout << "로미오가 이겼습니다." << endl;
    }
    else if (strcmp(s,"가위")==0 && strcmp(t,"바위")==0) {
        cout << "줄리엣이 이겼습니다." << endl;
    }
    else if (strcmp(s,"바위")==0 && strcmp(t,"가위")==0) {
        cout << "로미오가 이겼습니다." << endl;
    }
    else if (strcmp(s,"바위")==0 && strcmp(t,"보")==0) {
        cout << "줄리엣이 이겼습니다." << endl;
    }
    else if (strcmp(s,"보")==0 && strcmp(t,"바위")==0) {
        cout << "로미오가 이겼습니다." << endl;
    }
    else if (strcmp(s,"보")==0 && strcmp(t,"가위")==0) {
        cout << "줄리엣이 이겼습니다." << endl;
    }
    else {
        cout << "비겼습니다." << endl;
    }

    return 0;
}