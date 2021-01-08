#ifndef __TOKEN_H__
#define __TOKEN_H__

class Token {
public:
    char   kind_;    
    double value_; 
    string name_;

    // initialize kind with ch
    Token(char k) : kind_{k}, value_{0} { }

    // initialize kind and value
    Token(char k, double v) : kind_{k}, value_{v} { }

    // initialize kind and name
    Token(char k, string n) : kind_{k}, value_{0}, name_{n} { }
};

class TokenStream {
public:
    TokenStream(istream &ii) : is_{ii} { }

    Token Get();          // get a Token
    void  PutBack(Token); // put a token back
    void  Ignore(char);   // discard characters up to and including a c
private:
    bool    full_{false}; // is there a Token in the buffer?
    Token   buffer_{'0'}; // here is where PutBack() stores a Token
    istream &is_;
};

#endif
