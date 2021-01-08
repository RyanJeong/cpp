#include "../std_lib_facilities.h"
#include "const.h"
#include "token.h"
#include "variable.h"
#include "util.h"

extern SymbolTable st;

double CalcSqrt(TokenStream &ts)
{
    Token t{ts.Get()};

    if (t.kind_ != '(') {
        error("'(' expected");
    }

    double d{Expression(ts)};

    if (d < 0) {
        error("sqrt negative value is imaginary");
    }
    t = ts.Get();
    if (t.kind_ != ')') {
        error("')' expected");
    }

    return sqrt(d);
}

double CalcPow(TokenStream &ts)
{
    Token t{ts.Get()};

    if (t.kind_ != '(') {
        error("'(' expected");
    }

    double base{Expression(ts)};

    t = ts.Get();
    if (t.kind_ != ',') { 
        error("',' expected");
    }

    int power{int(Expression(ts))};

    t = ts.Get();
    if (t.kind_ != ')') {
        error("')' expected");
    }

    return pow(base, power);
}

double CalcSin(TokenStream &ts)
{
    Token t{ts.Get()};

    if (t.kind_ != '(') {
        error("'(' expected");
    }

    double d{Expression(ts)};

    t = ts.Get();
    if (t.kind_ != ')') {
        error("')' expected");
    }
    if (d == 0 || d == 180) {

        return 0;       // return 0
    }

    return sin(d*kPi/180);
}

double CalcCos(TokenStream &ts)
{
    Token t{ts.Get()};

    if (t.kind_ != '(') {
        error("'(' expected");
    }

    double d{Expression(ts)};

    t = ts.Get();
    if (t.kind_ != ')') {
        error("')' expected");
    }
    if (d == 90 || d == 270) {

        return 0;      // return 0 instead of 8.766e-11
    }

    return cos(d*kPi/180);
}

double handleVariable(TokenStream &ts, Token &t)
{
    Token t2{ts.Get()};

    if (t2.kind_ == '=') {

        return st.setValue(t.name_, Expression(ts));
    } else {
        ts.PutBack(t2);

        return st.getValue(t.name_);       // missing in text!
    }
}

double Primary(TokenStream &ts)        
{
    Token t{ts.Get()};

    switch (t.kind_) {
        case '(':
        {
            double d{Expression(ts)};

            t = ts.Get();
            if (t.kind_ != ')') {
                error("')' expected");
            }

            return d;
        }
        case '{':
        {
            double d{Expression(ts)};

            t = ts.Get();
            if (t.kind_ != '}') {
                error("'}' expected");
            }

            return d;
        }
        case kNumber: 

            return t.value_;
        case kName:

            return handleVariable(ts, t);
        case '-':

            return -Primary(ts);
        case '+':

            return Primary(ts);
        case kSquareRoot:

            return CalcSqrt(ts);
        case kExponent:

            return CalcPow(ts);
        case kSin:

            return CalcSin(ts);
        case kCos:

            return CalcCos(ts);
        default:
            error("Primary expected");
    }
}

double Secondary(TokenStream &ts)          
{
    double left{Primary(ts)};
    Token  t{ts.Get()};

    while (true) {
        switch (t.kind_) {
            case '!':
                if (left == 0) {
                    return 1;
                }
                for (int i = left-1; i > 0; --i) {
                    left *= i;
                }
                t = ts.Get();
                break;
            default:
                ts.PutBack(t);

                return left;
        }
    }
}

double Term(TokenStream &ts)      
{
    double left{Secondary(ts)};
    Token  t{ts.Get()};             // get next token from TokenStream

    while (true) {
        switch (t.kind_) {
            case '*':
                left *= Secondary(ts);
                t    = ts.Get();
                break;
            case '/':
            {
                double d{Secondary(ts)};

                if (d == 0) {
                    error("divide by zero");
                }
                left /= d;
                t = ts.Get();
                break;
            }
            case '%':
            {
                double d{Secondary(ts)};

                if (d == 0) {
                    error("%: divide by zero");
                }
                left = fmod(left, d);
                t = ts.Get();
                break;
            }
            default:
                ts.PutBack(t); // put t back into the TokenStream

                return left;
        }
    }
}

double Expression(TokenStream &ts) 
{
    double left{Term(ts)}; // read and evaluate a Term
    Token  t{ts.Get()};    // get next token from TokenStream

    while (true) {
        switch (t.kind_) {
            case '+':
                left += Term(ts); // evaluate Term and add
                t    = ts.Get();
                break;
            case '-':
                left -= Term(ts); // evaluate Term and subtract
                t    = ts.Get();
                break;
            default:
                ts.PutBack(t);    // put t back into the token stream

                return left;
        }
    }
}

// assume we have seen "let"
// handle: name = Expression
// declare a variable called "name" with the initial value "Expression"
double Declaration(TokenStream &ts)
{
    Token t{ts.Get()};

    if (t.kind_ != kName) {
        error("name expected in declaration");
    }
    string var_name{t.name_};
    Token  t2{ts.Get()};

    if (t2.kind_ != '=') {
        error("= missing in declaration of ", var_name);
    }

    double d{Expression(ts)};

    st.defineName(var_name, d);

    return d;
}

double Statement(TokenStream &ts)
{
    Token t{ts.Get()};
    
    if (t.kind_ == kLet) {

        return Declaration(ts);
    } else {
        ts.PutBack(t);

        return Expression(ts);
    }
}

void PrintHelp()
{
    cout << "Simple Calculator Manual\n"
         << "========================\n"
         << "This calculator program supports +, -, *, and / operations\n"
         << "Enter any form of compound Statement followed by ';' for result\n"
         << "- ex: 4 + 1; (5-2)/{6*(8+14)}\n"
         << "The modulo operator % may be used on all numbers\n"
         << "An '!' placed after a value will calculate the factorial of it\n"
         << "- ex: 4! = 4 * 3 * 2 * 1\n"
         << "Square root and exponentiation are provided by 'sqrt' and 'pow'\n"
         << "- ex: sqrt(25) = 5, pow(5,2) = 25\n"
         << "Variable assignment is provided using the 'let' keyword:\n"
         << "- ex: let x = 37; x * 2 = 74; x = 4; x * 2 = 8\n\n";

    return;
}

void CleanUpMess(TokenStream &ts)
{
    ts.Ignore(kPrint);

    return;
}

void Calculate(TokenStream &ts)                   
{
    while (cin) {
        try {
            cout << kPrompt;
            Token t{ts.Get()};

            // discard extra 'prints'
            while (t.kind_ == kPrint) {
                t = ts.Get(); 
            }
            if (t.kind_ == kHelp) {
                PrintHelp();
            } else if (t.kind_ == kQuit) {

                return;
            } else {
                ts.PutBack(t);
                cout << kResult << Statement(ts) << '\n';
            }
        } catch (exception &e) {
            cerr << e.what() << '\n'; // write error message to user
            CleanUpMess(ts);
        }
    }

    return;
}
