#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "TaxDeclaration.h"
#include "PersistenceService.h"
#include "Apartment.h"
#include "Store.h"
#include "Plot.h"

using namespace std;

#ifndef _FILE_SERVICE_H
#define _FILE_SERVICE_H

class FileService : public PersistenceService
{
  string filename;
  vector<TaxDeclaration> declarations;
  void loadFromFile();
  void saveToFile();

public:
  FileService(string filename);
  vector<TaxDeclaration> getTaxDeclarations(string vat, int year);
  void insertTaxDeclaration(TaxDeclaration td);
  void removeTaxDeclaration(TaxDeclaration td);
};

#endif // !_FILE_SERVICE_H

