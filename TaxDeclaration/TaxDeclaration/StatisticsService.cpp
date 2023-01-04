#include "StatisticsService.h"

StatisticsService::StatisticsService(PersistenceService* _ps)
{
  ps = _ps;
}

double StatisticsService::getTotalTax()
{
  double totalTax = 0;
  for (auto td : ps->getTaxDeclarations())
  {
    totalTax += td.calculateTax();
  }
  return totalTax;
}

TaxDeclaration StatisticsService::getHighestDeclaration()
{
  vector<TaxDeclaration> declarations = ps->getTaxDeclarations();

  if (declarations.size() > 0)
  {
    TaxDeclaration max = declarations.at(0);
    double highestTax = 0;
    for (auto td : declarations)
    {
      if (td.calculateTax() > highestTax)
      {
        max = td;
        highestTax = td.calculateTax();
      }
    }
    return max;
  }
  else
    throw std::exception("No declarations available");
}
