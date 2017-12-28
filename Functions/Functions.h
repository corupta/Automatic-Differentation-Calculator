//
// Created by corupta on 06.12.2017.
//

//#include "../Variable.cpp"

#ifndef PROJECT4_FUNCTIONS_H
#define PROJECT4_FUNCTIONS_H

#include "../Variable.h"
#include <string>
#include <map>

#define funcTypeLen 14
enum FuncType { COS, SIN, TAN, ACOS, ASIN, ATAN, EXP, LOG, SQRT, ADD, MULT, SUBS, DIVIDE, POW, CONSTANT };

std::map <string, FuncType> funcNames;

typedef long double (*funcPtr)(Variable*, Variable*);

funcPtr functions[funcTypeLen];

funcPtr derivatives[funcTypeLen];

void initalizeFunctions();

FuncType getFuncType(std::string);

bool isOperationBinary(FuncType);

#endif //PROJECT4_FUNCTIONS_H


