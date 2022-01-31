#include <iostream>
#include <string.h>

class My_string {
    char* content_;
    int length_;
    int capacity_;
public:
    My_string(const My_string& m_str);
    My_string(const char* str);
    explicit My_string(int cap);
    ~My_string(void);
};

My_string::My_string(const My_string& m_str)
{
    length_=m_str.length_;
    capacity_=length_;
    content_=new char[length_];

    //strcpy(content_,m_str.content_); not terminated with 'null' character
    for (int i = 0; i<length_; ++i) {
        content_[i]=m_str.content_[i];
    }

    return;
}

My_string::My_string(const char* str) 
{
    length_=strlen(str);
    capacity_=length_;
    content_=new char[length_];
    strcpy(content_,str);

    return;
}

My_string::My_string(int cap) 
{
    length_=0;
    capacity_=cap;
    content_=new char[capacity_];
    std::cout << "Capacity: " << capacity_ << std::endl;

    return;
}

My_string::~My_string(void) {
    delete[] content_;

    return;
}

void do_something_with_string(My_string m_str)
{
    // Do something ...
    return;
}

int main(void)
{
    do_something_with_string(3); // do_something_with_string(My_string(3)); -> Compile Error!
    My_string cap(4);
    My_string s = 5;

    return 0;
}