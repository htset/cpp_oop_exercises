#pragma once
#include <iostream>

using namespace std;

class Measurement
{
public:
  double temp;
  string date;

  Measurement(double _temp, string _date);
  Measurement();
  void print();
};
