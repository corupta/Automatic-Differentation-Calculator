//
// Created by corupta on 27.12.2017.
//

#include "Value.h"

Value::Value() : empty(true) {}

Value::Value(double val) : val(val), empty(false) {}

void Value::setValue(double val) {
  empty = false;
  this -> val = val;
}

void Value::clean() {
  empty = true;
}

bool Value::isEmpty() {
  return empty;
}

double Value::getValue() {
  return val;
}