//
// Created by corupta on 06.12.2017.
//

//#include "../Variable.cpp"

#ifndef PROJECT4_FUNCTIONS_H
#define PROJECT4_FUNCTIONS_H

#include "defs.h"
#include "Variable.h"
#include <string>
#include <map>

// used function pointers and a static class so that each function can be accessed as Functions::functions[FuncType and Functions::derivatives[FuncType]
// FuncType is an enum of sin/cos/atan/mult, etc.

typedef long double (*funcPtr)(Variable*, Variable*);

class Functions {
private:
  // unary functions
  static long double getCos(Variable*a, Variable*b=NULL);
  static long double getSin(Variable*a, Variable*b=NULL);
  static long double getTan(Variable*a, Variable*b=NULL);
  static long double getACos(Variable*a, Variable*b=NULL);
  static long double getASin(Variable*a, Variable*b=NULL);
  static long double getATan(Variable*a, Variable*b=NULL);
  static long double getExp(Variable*a, Variable*b=NULL);
  static long double getLog(Variable*a, Variable*b=NULL);
  static long double getSqrt(Variable*a, Variable*b=NULL);

  // binary functions
  static long double getAdd(Variable*a, Variable*b);
  static long double getMult(Variable*a, Variable*b);
  static long double getSubs(Variable*a, Variable*b);
  static long double getDivide(Variable*a, Variable*b);
  static long double getPow(Variable*a, Variable*b);

  // unary function derivations
  static long double deriveCos(Variable*a, Variable*b=NULL);
  static long double deriveSin(Variable*a, Variable*b=NULL);
  static long double deriveTan(Variable*a, Variable*b=NULL);
  static long double deriveACos(Variable*a, Variable*b=NULL);
  static long double deriveASin(Variable*a, Variable*b=NULL);
  static long double deriveATan(Variable*a, Variable*b=NULL);
  static long double deriveExp(Variable*a, Variable*b=NULL);
  static long double deriveLog(Variable*a, Variable*b=NULL);
  static long double deriveSqrt(Variable*a, Variable*b=NULL);

  // binary function derivations
  static long double deriveAdd(Variable*a, Variable*b);
  static long double deriveMult(Variable*a, Variable*b);
  static long double deriveSubs(Variable*a, Variable*b);
  static long double deriveDivide(Variable*a, Variable*b);
  static long double derivePow(Variable*a, Variable*b);
  static void fillFunctionPointers();
  static void setFunctionNames();

public:
  static funcPtr functions[funcTypeLen];
  static funcPtr derivatives[funcTypeLen];
  // a map to get enum value of each function name
  static std::map <std::string, FuncType> funcNames;

  // initialize functions, derivatives array (set function pointers)
  static void initializeFunctions();

  // returnns the FuncType equivalent of a given function name as a string
  static FuncType getFuncType(std::string);

  // returns true if the given function takes two parameters
  static bool isOperationBinary(FuncType);
};

#endif //PROJECT4_FUNCTIONS_H


