#include <iostream>
#include <string.h>

class My_string{
public:
    My_string(char c);
    My_string(const char* str);
    My_string(const My_string& m_str);
    ~My_string(void);
    int length(void) const;
    void print(void) const;
    void println(void) const;
    My_string& assign(const My_string& m_str);
    My_string& assign(const char* str);
    int capacity(void) const;
    void reserve(int size);
private:
    char* content_;
    int length_;
    int capacity_;
};

My_string::My_string(char c)
{
    length_=1;
    content_=new char[length_];
    *content_=c;

    return;
}

My_string::My_string(const char* str)
{
    length_=strlen(str);
    content_=new char[length_];
    strcpy(content_,str);

    return;
}

My_string::My_string(const My_string& m_str)
{
    length_=m_str.length_;
    content_=new char[length_];
    strcpy(content_,m_str.content_);

    return;
}

My_string::~My_string(void)
{
    delete[] content_;

    return;
}

int My_string::length(void) const
{

    return length_;
}

void My_string::print(void) const
{
    for (int i = 0; i<length_; ++i) {
        std::cout << content_[i];
    }

    return;
}

void My_string::println(void) const
{
    print();
    std::cout << std::endl;

    return;
}

My_string& My_string::assign(const My_string& m_str)
{
    if (m_str.length_>capacity_) {
        delete[] content_;
        content_=new char[m_str.length_];
        capacity_=m_str.length_;
    }
    strcpy(content_,m_str.content_);
    length_=m_str.length_;

    return *this;
}

My_string& My_string::assign(const char* str)
{
    int str_len = strlen(str);
    if (str_len>capacity_) {
        delete[] content_;
        content_=new char[str_len];
        capacity_=str_len;
    }
    strcpy(content_,str);
    length_=str_len;

    return *this;
}

int My_string::capacity(void) const
{

    return capacity_;
}

void My_string::reserve(int size);

int main(void)
{
    My_string str1("Hello, world!");
    My_string str2(str1);

    str1.println();
    str2.println();

    return 0;
}