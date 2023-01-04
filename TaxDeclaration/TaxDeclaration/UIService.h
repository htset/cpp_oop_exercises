#include "TaxDeclaration.h"
#include "StatisticsService.h"
#include "PersistenceService.h"

#ifndef _UI_SERVICE_H
#define _UI_SERVICE_H

class UIService
{
  PersistenceService* ps;
  StatisticsService* ss;

  void create();
  void remove();
  void search();
  TaxDeclaration enterTaxDeclarationDetails();
  Address enterAddress();
  Property* enterProperty();

public:
  UIService(PersistenceService*, StatisticsService*);
  void menu();
};

#endif 