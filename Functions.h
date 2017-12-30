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

typedef double (*funcPtr)(Variable*, Variable*);

class Functions {
private:
  // unary functions
  static double getCos(Variable*a, Variable*b=NULL);
  static double getSin(Variable*a, Variable*b=NULL);
  static double getTan(Variable*a, Variable*b=NULL);
  static double getACos(Variable*a, Variable*b=NULL);
  static double getASin(Variable*a, Variable*b=NULL);
  static double getATan(Variable*a, Variable*b=NULL);
  static double getExp(Variable*a, Variable*b=NULL);
  static double getLog(Variable*a, Variable*b=NULL);
  static double getSqrt(Variable*a, Variable*b=NULL);

  // binary functions
  static double getAdd(Variable*a, Variable*b);
  static double getMult(Variable*a, Variable*b);
  static double getSubs(Variable*a, Variable*b);
  static double getDivide(Variable*a, Variable*b);
  static double getPow(Variable*a, Variable*b);

  // unary function derivations
  static double deriveCos(Variable*a, Variable*b=NULL);
  static double deriveSin(Variable*a, Variable*b=NULL);
  static double deriveTan(Variable*a, Variable*b=NULL);
  static double deriveACos(Variable*a, Variable*b=NULL);
  static double deriveASin(Variable*a, Variable*b=NULL);
  static double deriveATan(Variable*a, Variable*b=NULL);
  static double deriveExp(Variable*a, Variable*b=NULL);
  static double deriveLog(Variable*a, Variable*b=NULL);
  static double deriveSqrt(Variable*a, Variable*b=NULL);

  // binary function derivations
  static double deriveAdd(Variable*a, Variable*b);
  static double deriveMult(Variable*a, Variable*b);
  static double deriveSubs(Variable*a, Variable*b);
  static double deriveDivide(Variable*a, Variable*b);
  static double derivePow(Variable*a, Variable*b);
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


