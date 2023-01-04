#include <iostream>
#include <sstream>
#include <vector>
#include "Address.h"
#include "Property.h"
#include "TaxException.h"

using namespace std;

#ifndef _APARTMENT_H_
#define _APARTMENT_H_

class Apartment : public Property
{
private:
  int floor;

public:
  Apartment(int, int, Address, int);
  Apartment();
  string toString();
  string serialize();
  void deserialize(string s);
  double calculateTax();
  void setFloor(int _floor) { floor = _floor; }
  int getFloor() { return floor; }
};

#endif // !_APARTMENT_H_
