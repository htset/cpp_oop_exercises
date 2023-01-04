#include <iostream>
#include "Address.h"
#include "Property.h"
#include "TaxException.h"

using namespace std;

#ifndef _PLOT_H_
#define _PLOT_H_

class Plot : public Property
{
private:
  bool withinCityLimits;
  bool cultivated;

public:
  Plot(int, int, Address, bool, bool);
  Plot();
  string toString();
  string serialize();
  void deserialize(string s);
  double calculateTax();
  void setWithinCityLimits(bool _withinCityLimits) { withinCityLimits = _withinCityLimits; }
  bool getWithinCityLimits() { return withinCityLimits; }
  void setCultivated(bool _cultivated) { cultivated = _cultivated; }
  bool getCultivated() { return cultivated; }
};

#endif // !_PLOT_H_
