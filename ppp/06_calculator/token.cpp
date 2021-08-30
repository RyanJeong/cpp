#include "../std_lib_facilities.h"
#include "const.h"
#include "token.h"

// c represents the kind of Token
void TokenStream::Ignore(char c)
{
    // first look in buffer
    if (full_ && c == buffer_.kind_) {
        full_ = false;

        return;
    }

    full_ = false;

    // now search for input
    for (char ch{0}; is_ >> ch; ) {
        if (ch == c) {
            
            return;
        }
    }

    return;
}

void TokenStream::PutBack(Token t)
{
    buffer_ = t;    // copy t to buffer
    full_   = true; // buffer is now full

    return;
}

Token TokenStream::Get()
{
    if (full_) {       // do we already have a Token?
        full_ = false; // remove Token from buffer

        return buffer_;
    }

    char ch;
    while (is_.get(ch)) {
        if (!isspace(ch) || ch == '\n') {
            break;
        }
    }
    switch (ch) {
    case '\n':

        return Token{kPrint};
    case kPrint:
    case kQuit:
    case kHelp:
    case '(': case ')': case '{': case '}':
    case '+': case '-': case '*': case '/':
    case '!': case '%': case '=': case ',':

        return Token{ch}; // let each character represent itself
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
    {
        is_.putback(ch); // put digit back into input stream

        double val;
        is_ >> val; // read floating-point number

        return Token{kNumber, val};  
    }
    default:
        if (isalpha(ch)) {
            string s;
            s += ch;
            while (is_.get(ch) &&
                ((isalpha(ch) || isdigit(ch) || ch == '_'))) {
                s += ch;
            }
            is_.putback(ch);
            if (s == kDeclKey) {

                return Token{kLet};
            } else if (s == kSqrtKey) {

                return Token{kSquareRoot};
            } else if (s == kExpKey) {

                return Token{kExponent};
            } else if (s == kSinKey) {

                return Token{kSin};
            } else if (s == kCosKey) {

                return Token{kCos};
            } else if (s == kQuitKey) {

                return Token{kQuit};
            } else if (s == kHelpKey) {

                return Token{kHelp};
            } else {

                return Token{kName, s};
            }
        } else {
            error("Bad token");
        }
    }
}
