# C++ Tutorial
## 01 - 문자열 클래스 설계
###### [뒤로가기](/tutorial/#index)
---

```cpp
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
    My_string& erase(int pos, int num);
    int find(int from, My_string& m_str) const;
    int find(int from, const char* str) const;
    int find(int from, char c) const;
    int compare(const My_string& m_str) const;
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

        return (char) NULL;
    }
    else {

        return content_[i];
    }
}

My_string& My_string::insert(int pos, const My_string& m_str)
{
    if (pos<0 || pos>length_) {

        return *this;
    }

    if (length_+m_str.length_>capacity_) {
        if (capacity_*2>length_+m_str.length_) {
            capacity_*=2;
        }
        else {
            capacity_=length_+m_str.length_;
        }
        char* prev = content_;
        content_=new char[capacity_];

        // 1. 0 ~ pos-1
        for (int i = 0; i<pos; ++i) {
            content_[i]=prev[i];
        }
        // 2. insert a new string
        for (int i = 0; i<m_str.length_; ++i) {
            content_[pos+i]=m_str.content_[i];
        }
        // 3. add the rest of the string
        for (int i = pos; i<length_; ++i) {
            content_[m_str.length_+i]=prev[i];
        }

        delete[] prev;
    }
    else {
        for (int i = length_-1; i>=pos; --i) {
            content_[i+m_str.length_]=content_[i];
        }
        for (int i = 0; i<m_str.length_; ++i) {
            content_[pos+i]=m_str.content_[i];
        }
    }
    length_+=m_str.length_;

    return *this;
}

My_string& My_string::insert(int pos, const char* str)
{
    My_string temp{str};

    return insert(pos,temp);
}

My_string& My_string::insert(int pos, char c)
{
    My_string temp{c};

    return insert(pos,temp);
}

My_string& My_string::erase(int pos, int num)
{
    do {
        if (num<0) {
            break;
        }
        if (pos<0 || pos>length_) {
            break;
        }

        // abcd, pos: 0, num: 5 => NULL
        if (num>length_) {
            num=length_;
            break;
        }
        // abcd, pos: 3, num: 3 => abc
        if (num+pos>length_) {
            num=length_-pos;
            break;
        }    
        // abcd, pos: 1, num: 2 => ad
        for (int i = pos+num; i<length_; ++i) {
            content_[i-num]=content_[i]; 
        }
    } while (0);
    length_-=num;

    return *this;
}

int My_string::find(int from, My_string& m_str) const
{
    do {
        if (m_str.length_==0 || length_<m_str.length_) {
            break;
        }
        if (from<0 || from+m_str.length_>length_) {
            break;
        }

        // s: abcde(5), p: bcd(3)
        for (int i = from; i<=length_-m_str.length_; ++i) {
            int j = 0;
            while (j<m_str.length_) {
                if (content_[i+j]!=m_str.content_[j]) {
                    break;
                }
                ++j;
            }
            if (j==m_str.length_) {

                return i;
            }
        }
    } while (0);

    return -1;
}

int My_string::find(int from, const char* str) const
{
    My_string temp{str};

    return find(from,temp);
}

int My_string::find(int from, char c) const
{
    My_string temp{c};

    return find(from,temp);
}

int My_string::compare(const My_string& m_str) const
{
    if (length_!=m_str.length_) {

        return length_>m_str.length_ ? 1 : -1;
    }
    else { // length_==m_str.length_
        for (int i = 0; i<length_; ++i) {
            if (content_[i]!=m_str.content_[i]) {

                return content_[i]>m_str.content_[i] ? 1 : -1;
            }
        }
    }

    return 0;
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

    str1.insert(7,"C++ ");
    str1.println();

    str1.erase(10,10);
    str1.println();
    str1.erase(6,1);
    str1.println();
    str1.erase(0,100);
    str1.println();

    str2.println();
    std::cout << str2.find(0,"Hello, world!") << std::endl;
    std::cout << str2.find(7,"world") << std::endl;
    std::cout << str2.find(8,"world") << std::endl;

    std::cout << str2.compare("Hello") << std::endl;
    std::cout << str2.compare("Hello, world!!") << std::endl;
    std::cout << str2.compare("Hello, world!") << std::endl;

    return 0;
}
```

###### [처음으로](#c-tutorial)
###### [뒤로가기](/tutorial/#index)
---