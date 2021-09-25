#ifndef __EXP_H__
#define __EXP_H__

class Exp {
	int exp; // 지수부
	int base; // 베이스
public:
	Exp(int b, int e) : base(b), exp(e) { }
	Exp(int b) : Exp(b,1) { }
	Exp() : Exp(1,1) { }

	int getExp(void) { return exp; }
	int getBase(void) { return base; }
	int getValue(void);
	bool equals(Exp b);
};

#endif

