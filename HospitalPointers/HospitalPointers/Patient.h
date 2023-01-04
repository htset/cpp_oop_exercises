#pragma once
#include <iostream>
#include <vector>
#include "Measurement.h"
#include "Clinic.h"

using namespace std;

class Patient
{
  char* name;
  char* surname;
  int yearOfBirth;
  Clinic* clinic;
  char* room;
  Measurement pm[10];
  size_t index;

public:
  Patient(const char* _name, const char* _surname, int _yearOfBirth, Clinic* _clinic, const char* _room);
  Patient();
  Patient(const Patient&);
  Patient& operator=(const Patient&);
  ~Patient();
  void setClinic(Clinic* _clinic);
  void insertMeasurement(Measurement m);
  void insertMeasurement(double _temp, const char* _date);
  double maxTemp();
  void display();
  int getAge();
};


