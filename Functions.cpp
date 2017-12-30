//
// Created by corupta on 06.12.2017.
//
#include <cmath>
#include "Functions.h"

funcPtr Functions::functions[funcTypeLen];
funcPtr Functions::derivatives[funcTypeLen];
std::map<std::string, FuncType> Functions::funcNames;

// one parameter functions
double Functions::getCos(Variable *a, Variable *b) {
  return cos(a -> getComputedValue());
}

double Functions::getSin(Variable *a, Variable *b) {
  return sin(a -> getComputedValue());
}

double Functions::getTan(Variable *a, Variable *b) {
  return tan(a -> getComputedValue());
}

double Functions::getACos(Variable *a, Variable *b) {
  return acos(a -> getComputedValue());
}

double Functions::getASin(Variable *a, Variable *b) {
  return asin(a -> getComputedValue());
}

double Functions::getATan(Variable *a, Variable *b) {
  return atan(a -> getComputedValue());
}

double Functions::getExp(Variable *a, Variable *b) {
  return exp(a -> getComputedValue());
}

double Functions::getLog(Variable *a, Variable *b) {
  return log(a -> getComputedValue());
}

double Functions::getSqrt(Variable *a, Variable *b) {
  return sqrt(a -> getComputedValue());
}

// one parameter derivative functions
double Functions::deriveCos(Variable *a, Variable *b) {
  return -getSin(a) * (a -> getDerivativeValue());
}

double Functions::deriveSin(Variable *a, Variable *b) {
  return getCos(a) * (a -> getDerivativeValue());
}

double Functions::deriveTan(Variable *a, Variable *b) {
  return 1.0 / pow(getCos(a), 2) * (a -> getDerivativeValue());
}

double Functions::deriveACos(Variable *a, Variable *b) {
  return (-1.0 / sqrt(1.0 - pow(a -> getComputedValue(), 2))) * (a -> getDerivativeValue());
}

double Functions::deriveASin(Variable *a, Variable *b) {
  return (1.0 / sqrt(1.0 - pow(a -> getComputedValue(), 2))) * (a -> getDerivativeValue());
}

double Functions::deriveATan(Variable *a, Variable *b) {
  return (1.0 / (1.0 + pow(a -> getComputedValue(), 2))) * (a -> getDerivativeValue());
}

double Functions::deriveExp(Variable *a, Variable *b) {
  return getExp(a) * (a -> getDerivativeValue());
}

double Functions::deriveLog(Variable *a, Variable *b) {
  return (1.0 / (a -> getComputedValue())) * (a -> getDerivativeValue());
}

double Functions::deriveSqrt(Variable *a, Variable *b) {
  return (1.0 / (2.0 * getSqrt(a))) * (a -> getDerivativeValue());
}

// two parameter functions
double Functions::getMult(Variable *a, Variable *b) {
  return (a -> getComputedValue()) * (b -> getComputedValue());
}

double Functions::getAdd(Variable *a, Variable *b) {
  return (a -> getComputedValue()) + (b -> getComputedValue());
}

double Functions::getSubs(Variable *a, Variable *b) {
  return (a -> getComputedValue()) - (b -> getComputedValue());
}

double Functions::getDivide(Variable *a, Variable *b) {
  return (a -> getComputedValue()) / (b -> getComputedValue());
}

double Functions::getPow(Variable *a, Variable *b) {
  return pow(a -> getComputedValue(), (b -> getComputedValue()));
}

// two parameter derivates
double Functions::deriveMult(Variable *a, Variable *b) {
  return (a -> getDerivativeValue()) * (b -> getComputedValue()) +
         (a -> getComputedValue()) * (b -> getDerivativeValue());
}

double Functions::deriveAdd(Variable *a, Variable *b) {
  return (a -> getDerivativeValue()) + (b -> getDerivativeValue());
}

double Functions::deriveSubs(Variable *a, Variable *b) {
  return (a -> getDerivativeValue()) - (b -> getDerivativeValue());
}

double Functions::deriveDivide(Variable *a, Variable *b) {
  return ((a -> getDerivativeValue()) * (b -> getComputedValue()) -
          (a -> getComputedValue()) * (b -> getDerivativeValue())) /
         pow(b -> getComputedValue(), 2);
}

double Functions::derivePow(Variable *a, Variable *b) {
  // includes cases such as x^x => (a^b)' = e^bloga * (b'loga + ba'/a)
  return exp(b -> getComputedValue() * getLog(a)) * ((b -> getDerivativeValue()) * getLog(a) +
                                                     (b -> getComputedValue()) * (a -> getDerivativeValue()) /
                                                     (a -> getComputedValue()));
}

void Functions::fillFunctionPointers() {
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

void Functions::setFunctionNames() {
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


void Functions::initializeFunctions() {
  fillFunctionPointers();
  setFunctionNames();
}


// returns the enum value of the function, given its name as a string) such as "cos" => COS
FuncType Functions::getFuncType(std::string func) {
  // convert the function name to upper case, so that both cos and Cos and cOS, etc. can be used.
  for (auto &c : func) {
    c = toupper(c);
  }
  return funcNames[func];
}

// returns true if the op is a binary operation and false otherwise. (Not to be called with "CONSTANT")
bool Functions::isOperationBinary(FuncType op) {
  // since the functions are enum, and from COS to SQRT they're unary operations (0-8)
  // and from ADD to POW they're binary operations (9 - 13)
  // a simple comparison check is enough
  return (int) op > (int) SQRT;
  // an alternative implementation would be using a switch case statement for enums.
}