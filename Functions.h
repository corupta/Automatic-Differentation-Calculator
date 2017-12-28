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
  static std::map <std::string, FuncType> funcNames;


  static void initializeFunctions();

  static FuncType getFuncType(std::string);

  static bool isOperationBinary(FuncType);
};

#endif //PROJECT4_FUNCTIONS_H


