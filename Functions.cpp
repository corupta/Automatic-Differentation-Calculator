//
// Created by corupta on 06.12.2017.
//
#include <cmath>
#include "Functions.h"

// one parameter functions
long double getCos(Variable *a, Variable *b = NULL) {
  return cos(a -> getComputedValue());
}

long double getSin(Variable *a, Variable *b = NULL) {
  return sin(a -> getComputedValue());
}

long double getTan(Variable *a, Variable *b = NULL) {
  return tan(a -> getComputedValue());
}

long double getACos(Variable *a, Variable *b = NULL) {
  return cos(a -> getComputedValue());
}

long double getASin(Variable *a, Variable *b = NULL) {
  return sin(a -> getComputedValue());
}

long double getATan(Variable *a, Variable *b = NULL) {
  return tan(a -> getComputedValue());
}

long double getExp(Variable *a, Variable *b = NULL) {
  return exp(a -> getComputedValue());
}

long double getLog(Variable *a, Variable *b = NULL) {
  return log(a -> getComputedValue());
}

long double getSqrt(Variable *a, Variable *b = NULL) {
  return sqrt(a -> getComputedValue());
}

// one parameter derivative functions
long double deriveCos(Variable *a, Variable *b = NULL) {
  return -getSin(a) * a -> getDerivativeValue();
}

long double deriveSin(Variable *a, Variable *b = NULL) {
  return getCos(a) * a -> getDerivativeValue();
}

long double deriveTan(Variable *a, Variable *b = NULL) {
  return 1.0L / pow(getCos(a), 2) * a -> getDerivativeValue();
}

long double deriveACos(Variable *a, Variable *b = NULL) {
  return (-1.0L / sqrt(1.0L - pow(a -> getComputedValue(), 2))) * a -> getDerivativeValue();
}

long double deriveASin(Variable *a, Variable *b = NULL) {
  return (1.0L / sqrt(1.0L - pow(a -> getComputedValue(), 2))) * a -> getDerivativeValue();
}

long double deriveATan(Variable *a, Variable *b = NULL) {
  return (1.0L / (1.0L + pow(a -> getComputedValue(), 2))) * a -> getDerivativeValue();
}

long double deriveExp(Variable *a, Variable *b = NULL) {
  return getExp(a) * b -> getDerivativeValue();
}

long double deriveLog(Variable *a, Variable *b = NULL) {
  return (1.0L / a -> getComputedValue()) * a -> getDerivativeValue();
}

long double deriveSqrt(Variable *a, Variable *b = NULL) {
  return (1.0L / (2.0L * getSqrt(a))) * a -> getDerivativeValue();
}

// two parameter functions
long double getMult(Variable *a, Variable *b) {
  return a -> getComputedValue() * b -> getComputedValue();
}

long double getAdd(Variable *a, Variable *b) {
  return a -> getComputedValue() + b -> getComputedValue();
}

long double getSubs(Variable *a, Variable *b) {
  return a -> getComputedValue() - b -> getComputedValue();
}

long double getDivide(Variable *a, Variable *b) {
  return a -> getComputedValue() / b -> getComputedValue();
}

long double getPow(Variable *a, Variable *b) {
  return pow(a -> getComputedValue(), b -> getComputedValue());
}

// two parameter derivates
long double deriveMult(Variable *a, Variable *b) {
  return a -> getDerivativeValue() * b -> getComputedValue() + a -> getComputedValue() * b -> getDerivativeValue();
}

long double deriveAdd(Variable *a, Variable *b) {
  return a -> getDerivativeValue() + b -> getDerivativeValue();
}

long double deriveSubs(Variable *a, Variable *b) {
  return a -> getDerivativeValue() - b -> getDerivativeValue();
}

long double deriveDivide(Variable *a, Variable *b) {
  return (a -> getDerivativeValue() * b -> getComputedValue() - a -> getComputedValue() * b -> getDerivativeValue()) /
         pow(b -> getComputedValue(), 2);
}

long double derivePow(Variable *a, Variable *b) {
  // includes cases such as x^x => (a^b)' = e^bloga * (b'loga + ba'/a)
  return exp(b -> getComputedValue() * getLog(a)) * (b -> getDerivativeValue() * getLog(a) +
                                                     b -> getComputedValue() * a -> getDerivativeValue() /
                                                     a -> getComputedValue());
}

void fillFunctionPointers() {
  functions[COS] = getCos;
  functions[SIN] = getSin;
  functions[TAN] = getTan;
  functions[ACOS] = getACos;
  functions[ASIN] = getASin;
  functions[ATAN] = getATan;
  functions[EXP] = getExp;
  functions[LOG] = getLog;
  functions[SQRT] = getSqrt;
  functions[MULT] = getMult;
  functions[ADD] = getAdd;
  functions[SUBS] = getSubs;
  functions[DIVIDE] = getDivide;
  functions[POW] = getPow;

  derivatives[COS] = deriveCos;
  derivatives[SIN] = deriveSin;
  derivatives[TAN] = deriveTan;
  derivatives[ACOS] = deriveACos;
  derivatives[ASIN] = deriveASin;
  derivatives[ATAN] = deriveATan;
  derivatives[EXP] = deriveExp;
  derivatives[LOG] = deriveLog;
  derivatives[SQRT] = deriveSqrt;
  derivatives[MULT] = deriveMult;
  derivatives[ADD] = deriveAdd;
  derivatives[SUBS] = deriveSubs;
  derivatives[DIVIDE] = deriveDivide;
  derivatives[POW] = derivePow;
}

void setFunctionNames() {
  funcNames["COS"] = COS;
  funcNames["SIN"] = SIN;
  funcNames["TAN"] = TAN;
  funcNames["ACOS"] = ACOS;
  funcNames["ASIN"] = ASIN;
  funcNames["ATAN"] = ATAN;
  funcNames["EXP"] = EXP;
  funcNames["LOG"] = LOG;
  funcNames["SQRT"] = SQRT;
  funcNames["ADD"] = ADD;
  funcNames["MULT"] = MULT;
  funcNames["SUBS"] = SUBS;
  funcNames["DIVIDE"] = DIVIDE;
  funcNames["POW"] = POW;
  funcNames["CONSTANT"] = CONSTANT;
}


void initializeFunctions() {
  fillFunctionPointers();
  setFunctionNames();
}


// returns the enum value of the function, given its name as a string) such as "cos" => COS
FuncType getFuncType(std::string func) {
  // convert the function name to upper case, so that both cos and Cos and cOS, etc. can be used.
  for (auto &c : func) {
    c = toupper(c);
  }
  return funcNames[func];
}

// returns true if the op is a binary operation and false otherwise. (Not to be called with "CONSTANT")
bool isOperationBinary(FuncType op) {
  // since the functions are enum, and from COS to SQRT they're unary operations (0-8)
  // and from ADD to POW they're binary operations (9 - 13)
  // a simple comparison check is enough
  return (int)op > (int)SQRT;
  // an alternative implementation would be using a switch case statement for enums.
}