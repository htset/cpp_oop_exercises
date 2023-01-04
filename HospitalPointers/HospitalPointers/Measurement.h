#pragma once
#include <iostream>

using namespace std;

class Measurement
{
public:
  double temp;
  char* date;

  Measurement(double _temp, const char* _date);
  Measurement();
  Measurement(const Measurement&);
  Measurement& operator=(const Measurement& m);
    ~Measurement();
  void print();
};
