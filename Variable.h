//
// Created by corupta on 06.12.2017.
//

#ifndef PROJECT4_VARIABLE_H
#define PROJECT4_VARIABLE_H

#include <iostream>
#include "defs.h"
#include "Value.h"

using namespace std;

class Variable {
  FuncType myType;
  // the function type ord constant for constant values and inputs
  Variable *left, *right;
  // the parameters of the function (*right is null if only it's a unary function)
  Value computedValue;
  Value derivativeValue;
  int cycleState;
  // 0 not visited, 1 visited, 2 finished
public:

  explicit Variable(FuncType myType = CONSTANT, Variable *left = NULL, Variable *right = NULL);

  // gets computed value of the current variable if it's not computed yet
  double getComputedValue();

  // gets computed derivative value of the current variable if it's not computed yet
  double getDerivativeValue();

  // removes the flags for computed & derivative so that those would be recalculated with neew input.
  void cleanVariable();

  // for input & constant case
  void setComputedValue(double);

  // for input & constant case => all of them are 0 except the input that's been derived is 1
  void setDerivativeValue(double);

  // sets the function type such as cos, sin, acos, etc.
  void setFuncType(FuncType);

  // sets the parameters of the function of the current variable
  void setVariables(Variable *left, Variable *right = NULL);

  // returns true if there's a cycle in the subtree
  // does something like topological sort, but only uses visited & finished flags, not times.
  bool cycleCheck();
};


#endif //PROJECT4_VARIABLE_H
