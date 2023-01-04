#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <sstream>
#include "Reservation.h"
#include "Date.h"
#include "Apartment.h"
#include "Person.h"
#include "PersistenceService.h"
using namespace std;

class UIService
{
  PersistenceService* ps;
  void addPersons(Reservation*);

public:
  UIService(PersistenceService*);
  void menu();
  void addReservation();
  void searchReservation();
  void listReservations();
};


