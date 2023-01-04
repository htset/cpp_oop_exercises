#include "Measurement.h"

Measurement::Measurement(double _temp, string _date)
  : temp(_temp), date(_date) { }

Measurement::Measurement()
  : temp(0), date("N/A") { }

void Measurement::print()
{
  cout << "Date: " << date << ", temperature: " << temp << endl;
}
