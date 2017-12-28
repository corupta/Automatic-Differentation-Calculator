//
// Created by corupta on 06.12.2017.
//

#include "Variable.h"


Variable::Variable(FuncType myType, Variable *left, Variable *right)
    : myType(myType), left(left), right(right) {}

long double Variable::getComputedValue() {
  if (computedValue . isEmpty()) {
    computedValue . setValue(functions[myType](left, right));
  }
  return computedValue . getValue();
}

long double Variable::getDerivativeValue() {
  if (derivativeValue . isEmpty()) {
    derivativeValue . setValue(functions[myType](left, right));
  }
  return derivativeValue . getValue();
}

void Variable::cleanVariable() {
  if (myType != CONSTANT) {
    computedValue . clean();
    derivativeValue . clean();
  }
}

void Variable::setComputedValue(long double val) {
  computedValue . setValue(val);
}

void Variable::setDerivativeValue(long double val) {
  // val is either 1 or 0
  derivativeValue . setValue(val);
}

void Variable::setFuncType(FuncType newType) {
  myType = newType;
}

void Variable::setVariables(Variable *newLeft, Variable *newRight) {
  left = newLeft;
  right = newRight;
}