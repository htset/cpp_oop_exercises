#include <iostream>
#include <vector>
#include "PersistenceService.h"
#include "TaxDeclaration.h"
#include "Apartment.h"
#include "Store.h"
#include "Plot.h"
#include <mysql/jdbc.h>

#define DEFAULT_URI "tcp://127.0.0.1"
#define EXAMPLE_USER "root"
#define EXAMPLE_PASS "pass"
#define EXAMPLE_DB "tax"

using namespace std;

#ifndef _DB_SERVICE_H
#define _DB_SERVICE_H

class DBService : public PersistenceService
{
  sql::Driver* driver;
  sql::Connection* conn;
  sql::Statement* stmt;

public:
  DBService();
  vector<TaxDeclaration> getTaxDeclarations(string vat, int year);
  void insertTaxDeclaration(TaxDeclaration td);
  void removeTaxDeclaration(TaxDeclaration td);
};

#endif // !_DB_SERVICE_H
