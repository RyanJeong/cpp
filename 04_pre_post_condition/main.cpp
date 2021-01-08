#include "../std_lib_facilities.h"

// calculate area of a rectangle
// pre-conditions: length and width are positive
// post-condition: returns a positive value that is area
int area(int length, int width)
{
    if (length <= 0 || width <= 0) {
        error("area() pre-condition");
    }
    int a{length * width};

    // Check overflow
    if (a <= 0) {
        error("area() post-condition");
    }

    return a;
}

int main(void)
{
    try {
        // This is an example of the area function with pre & post conditionals
        for (int x, y; cin >> x >> y; ) {
            cout << "Area: " << area(x, y) << '\n';
        }

        return 0;
    } catch (exception& e) {
        cerr << "error: " << e.what() << '\n';

        return 1;
    } catch (...) {
        cerr << "Oops: unknown exception!\n";

        return 2;
    }
}
