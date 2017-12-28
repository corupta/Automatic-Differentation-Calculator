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
  Value();
  explicit Value(long double);
  void setValue(long double);
  void clean();
  bool isEmpty();
  long double getValue();
};


#endif //PROJECT4_VALUE_H
