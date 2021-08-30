```C++
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
```
