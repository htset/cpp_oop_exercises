#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <sstream>
#include "Package.h"
#include "Date.h"
using namespace std;

class UIService
{
  vector<Package*>* packages;

public:
  UIService(vector<Package*>* _packages);
  void menu();
  void addPackage();
  void searchPackage();
  void deletePackage();
  void listPackages();
  void saveToFile();
  void loadFromFile();
};


