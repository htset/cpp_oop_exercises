#pragma once
#include <iostream>
#include <sstream>

using namespace std;

class Person
{
  int id;
  string name;
  string surname;
  int birthYear;

public:
  Person(int, string, string, int);
  string getName();
  string getSurname();
  int getBirthYear();
  string toString();
};

