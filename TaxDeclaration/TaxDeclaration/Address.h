#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

#ifndef ADDRESS_H
#define ADDRESS_H

class Address
{
private:
  string street;
  string number;
  string zip;
  string city;

public:
  Address(string _street, string _number, string _zip, string _city);
  Address();
  string getStreet() { return street; }
  string getNumber() { return number; }
  string getZip() { return zip; }
  string getCity() { return city; }
  string toString();
  string serialize();
  void deserialize(string s);
};

#endif