#pragma once
#include <vector>
#include "Date.h"
#include "Person.h"

class Reservation
{
  int id;
  string name;
  string surname;
  Date startDate;
  int duration;
  double cost;
  vector<Person> persons;

public:
  Reservation(int, string, string, Date, int, double);
  Reservation();
  void addPerson(Person p);
  string toString();
  string getName();
  string getSurname();
  string getStartDateMysql();
  int getDuration();
  double getCost();
  vector<Person> getPersons();
};

