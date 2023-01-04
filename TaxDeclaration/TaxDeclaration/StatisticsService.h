#include "TaxDeclaration.h"
#include "PersistenceService.h"

#ifndef _STATISTICS_SERVICE_H
#define _STATISTICS_SERVICE_H

class StatisticsService
{
private:
  PersistenceService* ps;

public:
  StatisticsService(PersistenceService* ps);
  double getTotalTax();
  TaxDeclaration getHighestDeclaration();
};
#endif 