#include "Clinic.h"

Clinic::Clinic(string _name, string _director)
{
  name = _name;
  director = _director;
}

Clinic::Clinic()
{
  name = "N/A";
  director = "N/A";
}

void Clinic::display()
{
  cout << "----Clinic ---- " << endl;
  cout << "Name: " << name << endl;
  cout << "Director: " << director << endl;
}

void Clinic::setDirector(string _director)
{
  director = _director;
}