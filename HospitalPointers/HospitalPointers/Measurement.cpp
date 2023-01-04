#include "Measurement.h"

Measurement::Measurement(double _temp, const char* _date)
{
  temp = _temp;
  date = new char[strlen(_date) + 1];
  strcpy_s(date, strlen(_date) + 1, _date);
}

Measurement::Measurement()
{ 
  temp = 0;
  date = new char[1];
  date[0] = '\0';
}

Measurement::Measurement(const Measurement& m)
{
  temp = m.temp;
  date = new char[strlen(m.date) + 1];
  strcpy_s(date, strlen(m.date) + 1, m.date);
}

Measurement& Measurement::operator=(const Measurement& m)
{
  temp = m.temp;
  date = new char[strlen(m.date) + 1];
  strcpy_s(date, strlen(m.date) + 1, m.date);
  return *this;
}

Measurement::~Measurement()
{
  delete[] date;
}

void Measurement::print()
{
  cout << "Date: " << date << ", temperature: " << temp << endl;
}
