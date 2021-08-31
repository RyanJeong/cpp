#include <iostream>

int main(void)
{
    const int sz_row = 5;
    const int sz_col = 6;

    int** arr = new int*[sz_row];
    for (int i = 0; i<sz_row; ++i) {
        arr[i]=new int[sz_col];
    }

    int cnt = 0;
    for (int i = 0; i<sz_row; ++i) {
        for (int j = 0; j<sz_col; ++j) {
            arr[i][j]=cnt++;
        }
    }
    for (int i = 0; i<sz_row; ++i) {
        for (int j = 0; j<sz_col; ++j) {
            std::cout << arr[i][j] << ' ';
        }
        std::cout << '\n';
    }

    for (int i = 0; i<sz_row; ++i) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}