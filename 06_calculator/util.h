#ifndef __UTIL_H__
#define __UTIL_H__

double CalcSqrt(TokenStream &);
double CalcPow(TokenStream &);
double CalcSin(TokenStream &);
double CalcCos(TokenStream &);
double handleVariable(TokenStream &, Token &);
double Primary(TokenStream &);
double Secondary(TokenStream &);
double Term(TokenStream &);
double Expression(TokenStream &); 
double Declaration(TokenStream &);
double Statement(TokenStream &);
void   PrintHelp();
void   CleanUpMess(TokenStream &);
void   Calculate(TokenStream &);

#endif
