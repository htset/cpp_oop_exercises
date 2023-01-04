#include "Reservation.h"

Reservation::Reservation(int _id, string _name, string _surname, Date _startDate, int _duration, double _cost)
{
  id = _id;
  name = _name;
  surname = _surname;
  startDate = _startDate;
  duration = _duration;
  cost = _cost;
}

Reservation::Reservation()
{
  id = 0;
  name = "";
  surname = "";
  duration = 0;
  cost = 0;
}

void Reservation::addPerson(Person p)
{
  persons.push_back(p);
}

string Reservation::toString()
{
  stringstream buf;
  buf << "--Reservation--" << endl;
  buf << "ID: " << id << endl;
  buf << "Name: " << name << endl;
  buf << "Surname: " << surname << endl;
  buf << "Start Date: " << startDate.toString() << endl;
  buf << "Duration: " << duration << endl;
  buf << "Cost: " << cost << endl;
  buf << "Persons:" << endl;
  for (int i = 0; i < persons.size(); i++)
    buf << persons[i].toString() << endl;

  return buf.str();
}

string Reservation::getName()
{
  return name;
}

string Reservation::getSurname()
{
  return surname;
}

string Reservation::getStartDateMysql()
{
  return startDate.toMysqlDate();
}

int Reservation::getDuration()
{
  return duration;
}

double Reservation::getCost()
{
  return cost;
}

vector<Person> Reservation::getPersons()
{
  return persons;
}
