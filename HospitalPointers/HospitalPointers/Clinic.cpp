#include "Clinic.h"

Clinic::Clinic(const char* _name, const char* _director)
{
  name = new char[strlen(_name) + 1];
  strcpy_s(name, strlen(_name) + 1, _name);
  director = new char[strlen(_director) + 1];
  strcpy_s(director, strlen(_director) + 1, _director);
}

Clinic::Clinic()
{
  name = new char[1];
  name[0] = '\0';
  director = new char[1];
  director[0] = '\0';
}

Clinic::Clinic(const Clinic& c)
{
  name = new char[strlen(c.name) + 1];
  strcpy_s(name, strlen(c.name) + 1, c.name);
  director = new char[strlen(c.director) + 1];
  strcpy_s(director, strlen(c.director) + 1, c.director);
}

Clinic& Clinic::operator=(const Clinic& c)
{
  name = new char[strlen(c.name) + 1];
  strcpy_s(name, strlen(c.name) + 1, c.name);
  director = new char[strlen(c.director) + 1];
  strcpy_s(director, strlen(c.director) + 1, c.director);

  return *this;
}

Clinic::~Clinic()
{
  delete[] name;
  delete[] director;
}

void Clinic::display()
{
  cout << "----Clinic ---- " << endl;
  cout << "Name: " << name << endl;
  cout << "Director: " << director << endl;
}

void Clinic::setDirector(const char* _director)
{
  if (director != nullptr)
    delete[] director;

  director = new char[strlen(_director) + 1];
  strcpy_s(director, strlen(_director) + 1, _director);
}