#include <iostream>
#include <string.h>

class Test {
public:
    Test(char* name);
    ~Test(void);
private:
    char* name_;
};

Test::Test(char* name)
{
    name_ = new char[strlen(name)+1];
    strcpy(name_,name);
    std::cout << name_ << " 생성자 호출" << std::endl;

    return;
}

Test::~Test(void)
{
    if (name_!=NULL) {
        std::cout << name_ << " 소멸자 호출" << std::endl;
        delete[] name_;
    }

    return;
}

void foo(void);

int main(void)
{
    Test test((char*) "main()");
    foo();

    return 0;
}

void foo(void)
{
    Test test((char*) "foo()");

    return;
}