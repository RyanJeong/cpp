#include <iostream>

using namespace std;

bool average(int a[], int size, double& avg) 
{
    if (size<=0) {

        return false;
    }

    double sum = 0;
    for (int i=0; i<size; i++) {
        sum+=a[i];
    }
    avg=sum/size;

    return true;
}

int main(void) 
{
    int x[] = {0,1,2,3,4,5};
    double avg;

    if (average(x,6,avg)) {
        cout << "평균은 " << avg << endl;
    }
    else {
        cout << "매개 변수 오류" << endl;
    }

    if (average(x,-2,avg)) {
        cout << "평균은 " << avg << endl;
    }
    else {
        cout << "매개 변수 오류 " << endl;
    }

    return 0;
}