#include "Date.h"
Date::Date()
{
  time_t t = time(0);
  tm now;
  localtime_s(&now, &t);
  day = now.tm_mday;
  month = now.tm_mon + 1;
  year = now.tm_year + 1900;
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

string Date::serialize()
{
  stringstream buf;
  buf << day << "/" << month << "/" << year;
  return buf.str();
}

void Date::deserialize(string s)
{
  sscanf_s(s.c_str(), "%2d/%2d/%4d", &day, &month, &year);
}

ostream& operator<<(ostream& output, const Date& d)
{
  output << d.day << "/" << d.month << "/" << d.year;
  return output;  // for multiple << operator chaining
}
