#include <iostream>
#include <string>

using namespace std;

int main(void) 
{
    cout << "7+23+5+100+25와 같이 덧셈 문자열을 입력하세요." << endl;
    string s;
    getline(cin,s,'\n'); // 문자열 입력

    int sum = 0;
    while (true) {
        // int idx = s.find('+'); // s의 처음부터 찾는다.
        int idx = s.find('+',0); // s의 0번째 문자부터 찾는다.
        if (idx==-1) {
            if (!s.empty()) {
                cout << s << endl;
                sum+=stoi(s);
            }
            break;
        }

        int cnt = idx;
        // string tmp = s.substr(idx) // idx부터 문자열 끝까지 
        string tmp = s.substr(0,cnt); // 0부터 cnt개
        cout << tmp << endl;
        sum+=stoi(tmp);
        // s.erase(pos) // pos 문자 삭제
        s.erase(0,cnt+1); // 0부터 cnt+1개
    }
    cout << "숫자들의 합은 " << sum;

    return 0;
}