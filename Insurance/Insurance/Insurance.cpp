#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Insurance
{
protected:
  string name;
  int age;
  int coverage;
public:
  Insurance(string _name, int _age, int _coverage)
  {
    name = _name;
    age = _age;
    coverage = _coverage;
  }

  Insurance()
  {
    name = "N/A";
    age = 0;
    coverage = 0;
  }

  virtual int calculateCost() = 0;
  virtual string toString() = 0;
};

class LifeInsurance : public Insurance
{
public:
  LifeInsurance(string _name, int _age, int _coverage) :
    Insurance(_name, _age, _coverage)
  {
  }

  LifeInsurance() : Insurance()
  {
  }

  virtual int calculateCost()
  {
    return 10 * age + 0.001 * coverage;
  }

  virtual string toString()
  {
    stringstream buffer;
    buffer << "------Life Insurance policy------" << endl;
    buffer << "Name: " << name << endl;
    buffer << "Age: " << age << endl;
    buffer << "Coverage: " << coverage << endl;
    buffer << "Yearly cost: " << calculateCost() << endl;

    return buffer.str();
  }
};
class AutoInsurance : public Insurance
{
protected:
  int carAge;
public:
  AutoInsurance(string _name, int _age, int _coverage, int _carAge) 
    : Insurance(_name, _age, _coverage)
  {
    carAge = _carAge;
  }

  AutoInsurance() : Insurance()
  {
    carAge = 0;
  }

  int getCarAge()
  {
    return carAge;
  }

  virtual int calculateCost()
  {
    return -age + 0.05 * coverage + 10 * carAge;
  }

  virtual string toString()
  {
    stringstream buffer;
    buffer << "------Auto Insurance policy------" << endl;
    buffer << "Name: " << name << endl;
    buffer << "Age: " << age << endl;
    buffer << "Coverage: " << coverage << endl;
    buffer << "Car age: " << carAge << endl;
    buffer << "Yearly cost: " << calculateCost() << endl;

    return buffer.str();
  }
};

void saveInsurance(Insurance* insurance)
{
  ofstream ofs("insurance.txt", ios::app);
  ofs << insurance->toString();

  //will not compile
  //ofs << insurance->getCarAge();
}

int main()
{
  AutoInsurance i1("John Doe", 30, 15000, 2);
  cout << i1.toString();
  LifeInsurance i2("John Doe", 30, 1000000);
  cout << i2.toString();

  saveInsurance(&i1);
  saveInsurance(&i2);
  return 0;
}