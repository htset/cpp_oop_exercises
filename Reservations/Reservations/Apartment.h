#pragma once
#include <iostream>
#include <sstream>

using namespace std;

class Apartment
{
  int id;
  string address;
  int capacity;
  double price;

public:
  Apartment();
  Apartment(int, string, int, double);
  string toString();
  double getPrice();
};

