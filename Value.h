//
// Created by corupta on 27.12.2017.
//

#ifndef PROJECT4_VALUE_H
#define PROJECT4_VALUE_H


class Value {
private:
  long double val;
  bool empty;
public:
  // creates an empty value class
  Value();

  // sets the current value (creates a non empty value class)
  explicit Value(long double);

  // sets the current value, and updates empty flag (to false)
  void setValue(long double);

  // sets empty flag to true
  void clean();

  // returns empty flag
  bool isEmpty();

  // returns the current value
  long double getValue();
};


#endif //PROJECT4_VALUE_H
