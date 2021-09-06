#include <iostream>
#include <string.h>

class My_string{
public:
    My_string(const My_string& m_str);
    My_string(const char* str);
    My_string(char c);
    ~My_string(void);
    int length(void) const;
    void print(void) const;
    void println(void) const;
    My_string& assign(const My_string& m_str);
    My_string& assign(const char* str);
    int capacity(void) const;
    void reserve(int size);
    char at(int i) const;
    My_string& insert(int pos, const My_string& m_str);
    My_string& insert(int pos, const char* str);
    My_string& insert(int pos, char c);
private:
    char* content_;
    int length_;
    int capacity_;
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

My_string::My_string(char c)
{
    length_=1;
    capacity_=length_;
    content_=new char[length_];
    *content_=c;

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
    length_=m_str.length_;
    //strcpy(content_,m_str.content_);
    for (int i = 0; i<length_; ++i) {
        content_[i]=m_str.content_[i];
    }

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
    length_=str_len;
    strcpy(content_,str);

    return *this;
}

int My_string::capacity(void) const
{

    return capacity_;
}

void My_string::reserve(int size)
{
    if (size>capacity_) {
        char* prev = content_;
        content_=new char[size];
        capacity_=size;
        for (int i = 0; i<length_; ++i) {
            content_[i]=prev[i];
        }
        delete[] prev;
    }

    return;
}

char My_string::at(int i) const
{
    if (i<0 || i>=length_) {

        return NULL;
    }
    else {

        return content_[i];
    }
}

int main(void)
{
    My_string str1{"Hello, world!"};
    My_string str2{str1};

    str1.println();
    str2.println();

    My_string str3{"Strings are objects that represent sequences of characters."};
    str3.reserve(64);
    std::cout << "Cap.: " << str3.capacity() << std::endl;
    std::cout << "Len.: " << str3.length() << std::endl;
    str3.println();


    return 0;
}