#include "Store.h"

Store::Store(int _id, int _surface, Address _address, int _commerciality)
  :Property(_id, _surface, _address)
{
  if (_commerciality >= 0 && _commerciality <= 5)
    commerciality = _commerciality;
  else
  {
    throw TaxException("commerciality should be between 0 and 5", 1);
  }
}

Store::Store() //Property() default constructor called automatically
{
  commerciality = 0;
}

string Store::toString()
{
  stringstream ss;
  ss << "--Store--" << endl;
  ss << "Surface: " << surface << endl;
  ss << "Address" << address.toString();
  ss << "Commerciality: " << commerciality << endl;
  return ss.str();
}

double Store::calculateTax()
{
  return (2.5 * surface + 20 * commerciality + 100);
}

string Store::serialize()
{
  return "store|" + to_string(surface) + "|" + to_string(commerciality) + "|" + address.serialize();
}

void Store::deserialize(string s)
{
  stringstream ss(s);
  string token;
  vector<string> words;
  while (getline(ss, token, '|'))
    words.push_back(token);

  surface = atoi(words[1].c_str());
  commerciality = atoi(words[2].c_str());
  address = Address(words[4], words[5], words[6], words[7]);
}