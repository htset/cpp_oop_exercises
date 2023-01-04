#include "Address.h"

Address::Address(string _street, string _number, string _zip, string _city)
{
  street = _street;
  number = _number;
  zip = _zip;
  city = _city;
}

Address::Address()
{
  street = "N/A";
  number = "N/A";
  zip = "N/A";
  city = "N/A";
}

string Address::toString()
{
  stringstream buf;
  buf << number << " " << street << ", " << zip << " " << city;
  return buf.str();
}

string Address::serialize()
{
  return "addr|" + street + "|" + number + "|" + zip + "|" + city;
}

void Address::deserialize(string s)
{
  stringstream ss(s);
  string token;
  vector<string> words;
  while (getline(ss, token, '|'))
    words.push_back(token);

  street = words[1];
  number = words[2];
  zip = words[3];
  city = words[4];
}