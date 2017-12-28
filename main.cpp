//
// Created by corupta on 06.12.2017.
//
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include "Variable.h"

using namespace std;

map<string, Variable *> variableMap;
vector<string> inputVariables;
string outputVariable;

int inputVariableLen = 0;

Variable *getVariable(string const &variableName) {
  return variableMap[variableName];
}

Variable *createVariable(string const &variableName) {
  Variable *res;
  long double val;
  try {
    val = stold(variableName);
    // is constant
    res = new Variable;
    res -> setComputedValue(val);
    res -> setDerivativeValue(0);
  } catch (...) {
    // not constant
    if (variableMap . find(variableName) == variableMap . end()) {
      // variable is not inserted
      variableMap[variableName] = new Variable();
      // in case the variable is input
      variableMap[variableName] -> setDerivativeValue(0);
    }
    res = variableMap[variableName];
  }
  return res;
}

// main method, takes the file names as args, (input & output)
int main(int argc, char *argv[]) {
  // to read & write faster
  ios_base::sync_with_stdio(false);

  // check argc & argv
  if (argc != 5) {
    cerr
        << "Run the code with the following command: ./project4 [functionDefinitionFile] [inputValuesFile] [outputValuesFile] [derivativeValuesFile]"
        << endl;
    return 1;
  }

  // open filestreams
  ifstream functionDefinitionFile(argv[1]), inputValuesFile(argv[2]);
  ofstream outputValuesFile(argv[3]), derivativeValuesFile(argv[4]);

  // make some initializations about sin/cos/mult/etc. functions.
  initalizeFunctions();

  // read function definitions
  string a, b, c, opString;
  Variable *var1, *var2, *var3;
  while (true) {
    functionDefinitionFile >> a;
    if (!functionDefinitionFile . good()) {
      break;
    }
    functionDefinitionFile >> b;
    if (b[0] == '=') {
      // assignment line
      functionDefinitionFile >> opString >> b;
      // a = (opString) b c => opString is the operation, a/b/c are variables. (b/c can be constant too)
      FuncType op = getFuncType(opString);
      var1 = getVariable(a);
      var1 -> setFuncType(op);
      var2 = createVariable(b);
      if (isOperationBinary(op)) {
        functionDefinitionFile >> c;
        var3 = createVariable(c);
      } else {
        var3 = NULL;
      }
      var1 -> setVariables(var2, var3);
    } else if (a[0] == 'i') {
      // input line
      var1 = createVariable(b);
      ++inputVariableLen;
    } else if (a[0] == 'o') {
      // output line
      var1 = createVariable(b);
      outputVariable = b;
    } else {
      // error in the input
      return 1584;
    }
  }

  // check if there's any cycle

  // read input & solve

  // read the order of the input variables
  for (int i = 0; i < inputVariableLen; ++i) {
    inputValuesFile >> a;
    inputVariables . push_back(a);
  }

  // print the headings of outputs
  outputValuesFile << outputVariable << endl;
  for (int i = 0; i < inputVariableLen; ++i) {
    derivativeValuesFile << "d" << outputVariable << "/d" << inputVariables[i] << " ";
  }
  derivativeValuesFile << endl;

  long double val;
  while (true) {
    for (int i = 0; i < inputVariableLen; ++i) {
      inputValuesFile >> val;
      if (!inputValuesFile . good()) {
        break;
      }
      variableMap[inputVariables[i]] -> setComputedValue(val);
    }
    if (!inputValuesFile . good()) {
      break;
    }
    // INPUT VALUES ARE SET
    // calculate result
    for (auto &&it : variableMap) {
      it . second -> cleanVariable();
    }
    // clean does not work on func type constant (constant/input)
    outputValuesFile << variableMap[outputVariable] -> getComputedValue() << endl;
    // calculate derivatives
    for (int i = 0; i < inputVariableLen; ++i) {
      for (auto &&it : variableMap) {
        it . second -> cleanVariable();
      }
      variableMap[inputVariables[i]] -> setDerivativeValue(1);
      derivativeValuesFile << variableMap[outputVariable] -> getDerivativeValue() << " ";
      variableMap[inputVariables[i]] -> setDerivativeValue(0);
    }
    derivativeValuesFile << endl;
  }

  // close filestreams
  functionDefinitionFile . close();
  inputValuesFile . close();
  outputValuesFile . close();
  derivativeValuesFile . close();
}