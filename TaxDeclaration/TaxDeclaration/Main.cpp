#include "StatisticsService.h"
#include "PersistenceService.h"
#include "FileService.h"
#include "DBService.h"
#include "UIService.h"

PersistenceService* ps = new DBService();
//PersistenceService* ps = new FileService("td.txt");
StatisticsService ss(ps);
UIService ui(ps, &ss);

int main()
{
  ui.menu();
  return 0;
}

