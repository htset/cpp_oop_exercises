#pragma once
#include <iostream>
using namespace std;

class Clinic
{
protected:
  char* name;
  char* director;

public:
  Clinic(const char* _name, const char* _director);
  Clinic();
  Clinic(const Clinic&);
  Clinic& operator=(const Clinic& c);
  ~Clinic();

  void setDirector(const char* _director);
  void display();
};

