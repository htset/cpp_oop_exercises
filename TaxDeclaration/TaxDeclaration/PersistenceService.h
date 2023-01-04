#include <iostream>
#include <vector>
#include "TaxDeclaration.h"

using namespace std;

#ifndef _PERSISTENCE_SERVICE_H
#define _PERSISTENCE_SERVICE_H

class PersistenceService
{
public:
  virtual void insertTaxDeclaration(TaxDeclaration td) = 0;
  virtual void removeTaxDeclaration(TaxDeclaration td) = 0;
  virtual vector<TaxDeclaration> getTaxDeclarations(string vat = "", 
    int year = 0) = 0;
};

#endif // !_PERSISTENCE_SERVICE_H
