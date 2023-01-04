#include "Apartment.h"

Apartment::Apartment(int _id, int _surface, Address _address, int _floor)
  :Property(_id, _surface, _address)
{
  if (_floor >= 0)
    floor = _floor;
  else
  {
    throw TaxException("Floor cannot be negative", 1);
  }
}

Apartment::Apartment() //Property() default constructor called automatically
{
  floor = 0;
}

string Apartment::toString()
{
  stringstream ss;
  ss << "--Apartment--" << endl;
  ss << "Surface: " << surface << endl;
  ss << "Address" << address.toString();
  ss << "Floor: " << floor << endl;
  return ss.str();
}

double Apartment::calculateTax()
{
  return (1.3 * surface + 10 * floor + 150);
}

string Apartment::serialize()
{
  return "apartment|" + to_string(surface) + "|" + to_string(floor) + "|" + address.serialize();
}

void Apartment::deserialize(string s)
{
  stringstream ss(s);
  string token;
  vector<string> words;
  while (getline(ss, token, '|'))
    words.push_back(token);

  surface = atoi(words[1].c_str());
  floor = atoi(words[2].c_str());
  address = Address(words[4], words[5], words[6], words[7]);
}