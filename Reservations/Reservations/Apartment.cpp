#include "Apartment.h"

Apartment::Apartment()
{
  id = 0;
  address = "N/A";
  capacity = 0;
  price = 0;
}

Apartment::Apartment(int _id, string _address, int _capacity, double _price)
{
  id = _id;
  address = _address;
  capacity = _capacity;
  price = _price;
}

string Apartment::toString()
{
  stringstream buf;
  buf << "--Apartment--" << endl;
  buf << "Address: " << address << endl;
  buf << "Capacity: " << capacity << endl;
  buf << "Price: " << price << endl;
  return buf.str();
}
  
double Apartment::getPrice()
{
  return price;
}