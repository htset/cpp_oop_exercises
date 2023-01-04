#include "Patient.h"
#include "Clinic.h"

Patient::Patient(string _name, string _surname, int _yearOfBirth, Clinic* _clinic, string _room)
{
  name = _name;
  yearOfBirth = _yearOfBirth;
  clinic = _clinic;
  room = _room;
}

Patient::Patient()
{
  name = "N/A";
  surname = "N/A";
  yearOfBirth = 0;
  clinic = NULL;
  room = "N/A";
}

void Patient::setClinic(Clinic* _clinic)
{
  clinic = _clinic;
}

void Patient::insertMeasurement(Measurement m)
{
  pm.push_back(m);
}

void Patient::insertMeasurement(float _temp, string _date)
{
  Measurement m(_temp, _date);
  pm.push_back(m);
}

double Patient::maxTemp()
{
  double maxt = 0.0;
  for (int j = 0; j < pm.size(); j++)
  {
    if (pm[j].temp > maxt)
      maxt = pm[j].temp;
  }

  return maxt;
}

void Patient::display()
{
  cout << "-----Patient info: ------" << endl;
  cout << "Name: " << name << " " << surname << endl;
  cout << "Birth year: " << yearOfBirth << endl;
  cout << "Room: " << room << endl;
  cout << "Measurements: " << endl;

  for (int j = 0; j < pm.size(); j++)
    pm[j].print();

  cout << "Max temp: " << maxTemp() << endl;

  if (clinic != nullptr)
    clinic->display();
  else
    cout << "No clinic! " << endl;

}

int Patient::getAge()
{
  time_t now = time(0);
  tm local_time;
  localtime_s(&local_time, &now);
  int current_year = local_time.tm_year + 1900;
  return current_year - yearOfBirth;
}



