#include <iostream>
#include "Package.h"
using namespace std;

Package::Package(string _recipient, string _address, float _weight, Date _shipmentDate)
{
  recipient = _recipient;
  address = _address;
  weight = _weight;
  shipmentDate = _shipmentDate;
}

Package::Package()
{
  recipient = "";
  address = "";
  weight = 0;
}

string Package::getRecipient()
{
  return recipient;
}

BasePackage::BasePackage(string _recipient, string _address, float _weight, Date _shipmentDate)
  :Package(_recipient, _address, _weight, _shipmentDate)
{
}

BasePackage::BasePackage() :Package()
{
}

float BasePackage::calculateCost()
{
  return BASE_PACKAGE_COST_FACTOR * weight;
}

Date BasePackage::calculateDeliveryTime()
{
  if (weight <= BASE_PACKAGE_MAX_WEIGHT)
    return shipmentDate.addDays(BASE_PACKAGE_DAYS);
  else
    return shipmentDate.addDays(BASE_PACKAGE_DAYS + 1);
}

string BasePackage::toString()
{
  stringstream buf;
  buf << endl << "--Base Package--" << endl;
  buf << "Recipient: " << recipient << endl;
  buf << "Address: " << address << endl;
  buf << "Weight: " << weight << endl;
  buf << "Shipment date:" << shipmentDate << endl;
  buf << "Expected delivery date:" << calculateDeliveryTime() << endl;
  buf << "Cost:" << calculateCost() << endl;
  buf << "---------------------" << endl;
  return buf.str();
}

string BasePackage::serialize()
{
  stringstream buf;
  buf << "Base Package" << endl;
  buf << recipient << endl;
  buf << address << endl;
  buf << weight << endl;
  buf << shipmentDate << endl;
  buf << "--" << endl;
  return buf.str();
}

void BasePackage::deserialize(string s)
{
  string package_type;
  stringstream buf(s);
  getline(buf, package_type);
  getline(buf, recipient);
  getline(buf, address);
  buf >> weight;
  buf.ignore();

  string temp_date;
  getline(buf, temp_date);
  shipmentDate.deserialize(temp_date);
}

AdvancedPackage::AdvancedPackage(string _recipient, string _address, float _weight, Date _shipmentDate)
  :Package(_recipient, _address, _weight, _shipmentDate)
{
}

AdvancedPackage::AdvancedPackage() :Package()
{
}

float AdvancedPackage::calculateCost()
{
  return ADVANCED_PACKAGE_COST_FACTOR * weight + ADVANCED_PACKAGE_COST_SUPPL;
}

Date AdvancedPackage::calculateDeliveryTime()
{
  return shipmentDate.addDays(ADVANCED_PACKAGE_DAYS);
}

string AdvancedPackage::toString()
{
  stringstream buf;
  buf << endl << "--Advanced Package--" << endl;
  buf << "Recipient: " << recipient << endl;
  buf << "Address: " << address << endl;
  buf << "Weight: " << weight << endl;
  buf << "Shipment date:" << shipmentDate << endl;
  buf << "Expected delivery date:" << calculateDeliveryTime() << endl;
  buf << "Cost:" << calculateCost() << endl;
  buf << "---------------------" << endl;
  return buf.str();
}

string AdvancedPackage::serialize()
{
  stringstream buf;
  buf << "Advanced Package" << endl;
  buf << recipient << endl;
  buf << address << endl;
  buf << weight << endl;
  buf << shipmentDate << endl;
  buf << "--" << endl;
  return buf.str();
}

void AdvancedPackage::deserialize(string s)
{
  string package_type;
  stringstream buf(s);
  getline(buf, package_type);
  getline(buf, recipient);
  getline(buf, address);
  buf >> weight;
  buf.ignore();

  string temp_date;
  getline(buf, temp_date);
  shipmentDate.deserialize(temp_date);
}

OvernightPackage::OvernightPackage(string _recipient, string _address, float _weight, Date _shipmentDate)
  :Package(_recipient, _address, _weight, _shipmentDate)
{
}

OvernightPackage::OvernightPackage() :Package()
{
}

float OvernightPackage::calculateCost()
{
  return OVERNIGHT_PACKAGE_COST_FACTOR * weight;
}

Date OvernightPackage::calculateDeliveryTime()
{
  return shipmentDate.addDays(OVERNIGHT_PACKAGE_DAYS);
}

string OvernightPackage::toString()
{
  stringstream buf;
  buf << endl << "--Overnight Package--" << endl;
  buf << "Recipient: " << recipient << endl;
  buf << "Address: " << address << endl;
  buf << "Weight: " << weight << endl;
  buf << "Shipment date:" << shipmentDate << endl;
  buf << "Expected delivery date:" << calculateDeliveryTime() << endl;
  buf << "Cost:" << calculateCost() << endl;
  buf << "---------------------" << endl;
  return buf.str();
}

string OvernightPackage::serialize()
{
  stringstream buf;
  buf << "Overnight Package" << endl;
  buf << recipient << endl;
  buf << address << endl;
  buf << weight << endl;
  buf << shipmentDate << endl;
  buf << "--" << endl;
  return buf.str();
}

void OvernightPackage::deserialize(string s)
{
  string package_type;
  stringstream buf(s);
  getline(buf, package_type);
  getline(buf, recipient);
  getline(buf, address);
  buf >> weight;
  buf.ignore();

  string temp_date;
  getline(buf, temp_date);
  shipmentDate.deserialize(temp_date);
}