#pragma once
#include <iostream>

using namespace std;

class Clinic
{
protected:
  string name;
  string director;

public:
  Clinic(string _name, string _director);
  Clinic();
  void setDirector(string _director);
  void display();
};

