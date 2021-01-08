#include "../std_lib_facilities.h"
#include "const.h"
#include "variable.h"

SymbolTable st; // allows Variable storage and retrieval

// is var already in var_table_?
bool SymbolTable::isDeclared(string var)
{
    for (const Variable &v : var_table_) {
        if (v.name_ == var) {

            return true;
        }
    }

    return false;
}

// return the value of the Variable named s
double SymbolTable::getValue(string s)
{
    for (const Variable &v : var_table_) {
        if (v.name_ == s) {

            return v.value_;
        }
    }
    error("get: undefined variable ", s);
}

// set the Variable named s to d
double SymbolTable::setValue(string s, double d)
{
    for (Variable &v : var_table_) {
        if (v.name_ == s) {
            if (v.constant_) {
                error("Can't overwrite constant variable");
            }
            v.value_ = d;

            return d;
        }
    }
    error("set: undefined variable ", s);
}

// add {var,val,con} to var_table_
double SymbolTable::defineName(string var, double val, bool con)
{
    if (isDeclared(var)) {
        error(var, " declared twice");
    }
    var_table_.push_back(Variable{var, val, con});

    return val;
}
