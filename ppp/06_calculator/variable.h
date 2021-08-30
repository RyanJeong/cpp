#ifndef __VARIABLE_H__
#define __VARIABLE_H__

class Variable {
public:
    string name_;
    double value_;
    bool   constant_;

    Variable(string n, double v, bool c = false)
        : name_{n}, value_{v}, constant_{c} { }
};

class SymbolTable {
public:
    bool   isDeclared(string);
    double getValue(string);
    double setValue(string, double);
    double defineName(string, double, bool con = false);
private:
    vector<Variable> var_table_;
};

#endif
