class Test {
public:
    Test(void) = default;
    Test(char, int, double);
    ~Test(void) = default;
private:
    char c_;
    int i_;
    double d_;
};

/*
Test::Test(char c, int i, double d)
{
    c_=c;
    i_=i;
    d_=d;

    return;
}
*/
Test::Test(char c, int i, double d) : c_{c}, i_{i}, d_{d} {}

int main(void)
{
    Test test('a',2,3.14);

    return 0;
}