#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <sstream>
#include "Date.h"
#define BASE_PACKAGE_COST_FACTOR 5
#define BASE_PACKAGE_DAYS 5
#define BASE_PACKAGE_MAX_WEIGHT 10
#define ADVANCED_PACKAGE_COST_FACTOR 5
#define ADVANCED_PACKAGE_COST_SUPPL 2
#define ADVANCED_PACKAGE_DAYS 2
#define OVERNIGHT_PACKAGE_COST_FACTOR 10
#define OVERNIGHT_PACKAGE_DAYS 1
using namespace std;

class Package
{
protected:
  string recipient;
  string address;
  float weight;
  Date shipmentDate;

public:
  Package(string _recipient, string _address, float _weight, Date _shipmentDate);
  Package();
  string getRecipient();
  virtual float calculateCost() = 0;
  virtual Date calculateDeliveryTime() = 0;
  virtual string toString() = 0;
  virtual string serialize() = 0;
  virtual void deserialize(string) = 0;
};

class BasePackage : public Package
{
public:

  BasePackage(string _recipient, string _address, float _weight, Date _shipmentDate);
  BasePackage();
  virtual float calculateCost();
  virtual Date calculateDeliveryTime();
  virtual string toString();
  virtual string serialize();
  virtual void deserialize(string s);
};

class AdvancedPackage : public Package
{
public:

  AdvancedPackage(string _recipient, string _address, float _weight, Date _shipmentDate);
  AdvancedPackage();
  virtual float calculateCost();
  virtual Date calculateDeliveryTime();
  virtual string toString();
  virtual string serialize();
  virtual void deserialize(string s);
};

class OvernightPackage : public Package
{
public:
  OvernightPackage(string _recipient, string _address, float _weight, Date _shipmentDate);
  OvernightPackage();
  virtual float calculateCost();
  virtual Date calculateDeliveryTime();
  virtual string toString();
  virtual string serialize();
  virtual void deserialize(string s);
};

