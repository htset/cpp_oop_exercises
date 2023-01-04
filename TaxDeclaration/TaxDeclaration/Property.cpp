#include "Property.h"

Property::Property(int _id, int _surface, Address _address)
{
  id = _id;
  surface = _surface;
  address = _address;
}

Property::Property()
{
  id = 0;
  surface = 0;
  //the address object is instantiated automatically
  //(the default constructor is called)
}


