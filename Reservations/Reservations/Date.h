#pragma once
#include <iostream>
#include <ctime>
#include <sstream>

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
  string serialize();
  void deserialize(string s);
  friend ostream& operator<<(ostream& output, const Date& s);
  string toString();
  string toMysqlDate();
};

