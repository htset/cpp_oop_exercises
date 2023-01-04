#include <iostream>
#include <ctime>
#define BASE_PACKAGE_COST_FACTOR 5
#define BASE_PACKAGE_DAYS 5
#define BASE_PACKAGE_MAX_WEIGHT 10
#define ADVANCED_PACKAGE_COST_FACTOR 5
#define ADVANCED_PACKAGE_COST_SUPPL 2
#define ADVANCED_PACKAGE_DAYS 2
#define OVERNIGHT_PACKAGE_COST_FACTOR 10
#define OVERNIGHT_PACKAGE_DAYS 1

using namespace std;

class Date
{
  int day;
  int month;
  int year;

public:
  Date();
  Date(int _day, int _month, int _year);
  Date addDays(int days);
  friend ostream& operator<<(ostream& output, const Date& s);
};

Date::Date()
{
  day = 0;
  month = 0;
  year = 0;
}

Date::Date(int _day, int _month, int _year)
{
  day = _day;
  month = _month;
  year = _year;
}

Date Date::addDays(int days)
{
  tm tmp = tm();
  tmp.tm_mday = day;
  tmp.tm_mon = month - 1;
  tmp.tm_year = year - 1900;
  time_t now = mktime(&tmp);

  time_t newSeconds = now + days * (60 * 60 * 24);
  tm newDate;
  localtime_s(&newDate, &newSeconds);

  Date temp;
  temp.day = newDate.tm_mday;
  temp.month = newDate.tm_mon + 1;
  temp.year = newDate.tm_year + 1900;

  return temp;
}

ostream& operator<<(ostream& output, const Date& d)
{
  output << d.day << "/" << d.month << "/" << d.year;
  return output;  // for multiple << operator chaining
}

class Package
{
protected:
  string recipient;
  string address;
  float weight;
  Date shipmentDate;

public:
  Package(string _recipient, string _address, float _weight, Date _shipmentDate)
  {
    recipient = _recipient;
    address = _address;
    weight = _weight;
    shipmentDate = _shipmentDate;
  }

  Package()
  {
    recipient = "";
    address = "";
    weight = 0;
  }

  virtual float calculateCost() = 0;
  virtual Date calculateDeliveryTime() = 0;
};

class BasePackage : public Package
{
public:

  BasePackage(string _recipient, string _address, float _weight, Date _shipmentDate) 
    :Package(_recipient, _address, _weight, _shipmentDate)
  {
  }

  BasePackage() :Package()
  {
  }

  float calculateCost()
  {
    return BASE_PACKAGE_COST_FACTOR * weight;
  }

  Date calculateDeliveryTime()
  {
    if(weight <= BASE_PACKAGE_MAX_WEIGHT)
      return shipmentDate.addDays(BASE_PACKAGE_DAYS);
    else
      return shipmentDate.addDays(BASE_PACKAGE_DAYS + 1);
  }
};

class AdvancedPackage : public Package
{
public:

  AdvancedPackage(string _recipient, string _address, float _weight, Date _shipmentDate) 
    :Package(_recipient, _address, _weight, _shipmentDate)
  {
  }

  float calculateCost()
  {
    return ADVANCED_PACKAGE_COST_FACTOR * weight + ADVANCED_PACKAGE_COST_SUPPL;
  }

  Date calculateDeliveryTime()
  {
    return shipmentDate.addDays(ADVANCED_PACKAGE_DAYS);
  }
};

class OvernightPackage : public Package
{
public:
  OvernightPackage(string _recipient, string _address, float _weight, Date _shipmentDate) 
    :Package(_recipient, _address, _weight, _shipmentDate)
  {
  }

  float calculateCost()
  {
    return OVERNIGHT_PACKAGE_COST_FACTOR * weight;
  }

  Date calculateDeliveryTime()
  {
    return shipmentDate.addDays(OVERNIGHT_PACKAGE_DAYS);
  }
};

int main()
{
  Package* p[4];

  p[0] = new BasePackage("John Doe", "12 Main str.", 15, Date(12, 1, 2023));
  p[1] = new BasePackage("Jane Doe", "1 High str.", 9.5, Date(30, 12, 2022));
  p[2] = new AdvancedPackage("Janet Doe", "3 Square dr.", 15, Date(12, 1, 2023));
  p[3] = new OvernightPackage("James Doe", "12 Infinite loop", 1, Date(31, 1, 2023));

  for (int i = 0; i < 4; i++)
  {
    cout << "Package no." << i + 1 << endl;
    cout << "Type: " << typeid(*p[i]).name() << endl;
    cout << "Delivery date: " << p[i]->calculateDeliveryTime() << endl;
    cout << "Cost: " << p[i]->calculateCost() << endl;
  }
  return 0;
}

