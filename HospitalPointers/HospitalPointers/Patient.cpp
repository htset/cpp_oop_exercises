#include "Patient.h"
#include "Clinic.h"

Patient::Patient(const char* _name, const char* _surname, int _yearOfBirth, Clinic* _clinic, const char* _room)
{
  name = new char[strlen(_name) + 1];
  strcpy_s(name, strlen(_name) + 1, _name);
  surname = new char[strlen(_surname) + 1];
  strcpy_s(surname, strlen(_surname) + 1, _surname);
  yearOfBirth = _yearOfBirth;
  clinic = _clinic;
  room = new char[strlen(_room) + 1];
  strcpy_s(room, strlen(_room) + 1, _room);
  index = 0;
}

Patient::Patient()
{
  name = new char[1];
  name[0] = '\0';
  surname = new char[1];
  surname[0] = '\0';
  yearOfBirth = 0;
  clinic = nullptr;
  room = new char[1];
  room[0] = '\0';
  index = 0;
}

Patient::Patient(const Patient& p)
{
  name = new char[strlen(p.name) + 1];
  strcpy_s(name, strlen(p.name) + 1, p.name);
  surname = new char[strlen(p.surname) + 1];
  strcpy_s(surname, strlen(p.surname) + 1, p.surname);
  yearOfBirth = p.yearOfBirth;
  clinic = p.clinic;
  room = new char[strlen(p.room) + 1];
  strcpy_s(room, strlen(p.room) + 1, p.room);

  for (int i = 0; i < p.index; i++)
    pm[i] = p.pm[i];

  index = p.index;
}

Patient& Patient::operator=(const Patient& p)
{
  name = new char[strlen(p.name) + 1];
  strcpy_s(name, strlen(p.name) + 1, p.name);
  surname = new char[strlen(p.surname) + 1];
  strcpy_s(surname, strlen(p.surname) + 1, p.surname);
  yearOfBirth = p.yearOfBirth;
  clinic = p.clinic;
  room = new char[strlen(p.room) + 1];
  strcpy_s(room, strlen(p.room) + 1, p.room);

  for (int i = 0; i < p.index; i++)
    pm[i] = p.pm[i];

  index = p.index;

  return *this;
}

Patient::~Patient()
{
  delete[] name;
  delete[] surname;
  delete[] room;

  //do not delete clinic!!
}

void Patient::setClinic(Clinic* _clinic)
{
  clinic = _clinic;
}

void Patient::insertMeasurement(Measurement m)
{
  if (index < 10)
    pm[index++] = m;
  else
    cout << "measurement array full" << endl;
}

void Patient::insertMeasurement(double _temp, const char* _date)
{
  Measurement m(_temp, _date);
  if (index < 10)
    pm[index++] = m;
  else
    cout << "measurement array full" << endl;
}

double Patient::maxTemp()
{
  double maxt = 0.0;
  for (int j = 0; j < index; j++)
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

  for (int j = 0; j < index; j++)
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



