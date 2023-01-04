#include <iostream>
#include <sstream>
#include "Address.h"

using namespace std;

#ifndef _PROPERTY_H_
#define _PROPERTY_H_

class Property
{
protected:
  int id;
  int surface;
  Address address;

public:
  Property(int, int, Address);
  Property();
  virtual string toString() = 0;
  virtual string serialize() = 0;
  virtual double calculateTax() = 0;
  void setSurface(int _surface) { surface = _surface; }
  int getSurface() { return surface; }
  void setAddress(Address _address) { address = _address; }
  Address getAddress() { return address; }
};

#endif // !_PROPERTY_H_
