#include <iostream>
#include "Address.h"
#include "Property.h"
#include "TaxException.h"

using namespace std;

#ifndef _STORE_H_
#define _STORE_H_

class Store : public Property
{
private:
  int commerciality;

public:
  Store(int, int, Address, int);
  Store();
  string toString();
  string serialize();
  void deserialize(string s);
  double calculateTax();
  void setCommerciality(int _commerciality) { commerciality = _commerciality; }
  int getCommerciality() { return commerciality; }
};

#endif // !_STORE_H_
