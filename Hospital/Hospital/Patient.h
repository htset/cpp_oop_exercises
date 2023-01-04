#pragma once
#include <iostream>
#include <vector>
#include "Measurement.h"
#include "Clinic.h"

using namespace std;

class Patient
{
  string name;
  string surname;
  int yearOfBirth;
  Clinic* clinic;
  string room;
  vector<Measurement> pm;

public:
  Patient(string _name, string _surname, int _yearOfBirth, Clinic* _clinic, string _room);
  Patient();
  Patient(const Patient& copy);
  void setName(string _name);
  void setSurname(string _surname);
  void setYearOfBirth(int _yearOfBirth);
  void setClinic(Clinic* _clinic);
  void setRoom(string _room);
  void insertMeasurement(Measurement m);
  void insertMeasurement(float _temp, string _date);
  double maxTemp();
  void display();
  int getAge();
};


