//
// Created by corupta on 06.12.2017.
//

#ifndef PROJECT4_VARIABLE_H
#define PROJECT4_VARIABLE_H

#include <iostream>
#include "Functions.h"
#include "Value.h"

using namespace std;

class Variable {
  FuncType myType;
  Variable *left, *right;
  Value computedValue;
  Value derivativeValue;
public:

  explicit Variable(FuncType = CONSTANT, Variable *left = NULL, Variable *right = NULL);

  // rest
  long double getComputedValue();

  long double getDerivativeValue();

  void cleanVariable();

  // for input & constant case
  void setComputedValue(long double);

  void setDerivativeValue(long double);

  void setFuncType(FuncType);

  void setVariables(Variable *left, Variable *right = NULL);

};


#endif //PROJECT4_VARIABLE_H
