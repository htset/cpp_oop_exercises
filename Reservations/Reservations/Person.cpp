#include "Person.h"
Person::Person(int _id, string _name, string _surname, int _birthYear)
{
  id = _id;
  name = _name;
  surname = _surname;
  birthYear = _birthYear;
}

string Person::getName()
{
  return name;
}

string Person::getSurname()
{
  return surname;
}

int Person::getBirthYear()
{
  return birthYear;
}

string Person::toString()
{
  stringstream buf;
  buf << "ID: " << id << endl;
  buf << "Name: " << name<< endl;
  buf << "Surname: " << surname << endl;
  buf << "Birth Year: " << birthYear << endl;
  return buf.str();
}