#pragma once
#include <iostream>
#include <vector>
#include "Date.h"
#include "Reservation.h"
#include "Apartment.h"

#include <mysql/jdbc.h>

#define DEFAULT_URI "tcp://127.0.0.1"
#define EXAMPLE_USER "root"
#define EXAMPLE_PASS "pass"
#define EXAMPLE_DB "test"

class PersistenceService
{
  sql::Driver* driver;
  sql::Connection* conn;
  sql::Statement* stmt;

public:
  PersistenceService();
  void insertReservation(Reservation&);
  vector<Apartment> getApartments();
  vector<Reservation> getAllReservations();
  vector<Reservation> getReservationsBySurname(string);
};

