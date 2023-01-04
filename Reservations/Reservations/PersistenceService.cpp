#include "PersistenceService.h"

PersistenceService::PersistenceService()
{
  try
  {
    driver = sql::mysql::get_driver_instance();
    conn = driver->connect(DEFAULT_URI, EXAMPLE_USER, EXAMPLE_PASS);
    conn->setSchema(EXAMPLE_DB);
    stmt = conn->createStatement();
    conn->setAutoCommit(false);
  }
  catch (sql::SQLException& e)
  {
    cout << "Could not connect to database. Exiting.." << endl;
    exit(0);
  }
}

vector<Apartment> PersistenceService::getApartments()
{
  vector<Apartment> result;
  try
  {
    sql::ResultSet *res = stmt->executeQuery("SELECT * from Apartments");

    while (res->next())
    {
      result.push_back(Apartment(res->getInt("id"), 
        res->getString("address"), res->getInt("capacity"), res->getInt("price")));
    }

    return result;
  }
  catch (sql::SQLException& e)
  {
    cout << "Database error. Exiting.." << endl;
    exit(0);
  }
}

vector<Reservation> PersistenceService::getAllReservations()
{
  vector<Reservation> result;
  try
  {
    sql::ResultSet* res = stmt->executeQuery("SELECT * from Reservations");
    sql::Statement* newStmt = conn->createStatement();
    while (res->next())
    {
      int day, month, year;
      string date_str = res->getString("startDate");
      sscanf_s(date_str.c_str(), "%4d-%2d-%2d", &year, &month, &day);

      Reservation resv(res->getInt("id"), res->getString("name"), res->getString("surname"), 
        Date(day, month, year), res->getInt("duration"), res->getDouble("cost"));
      sql::ResultSet* newRes = newStmt->executeQuery(
        "SELECT * from Persons where reservationId=" 
        + to_string(res->getInt("id")));
      while (newRes->next())
      {
        resv.addPerson(Person(newRes->getInt("id"), newRes->getString("name"), 
          newRes->getString("surname"), newRes->getInt("birthYear")));
      }

      result.push_back(resv);
    }

    return result;
  }
  catch (sql::SQLException& e)
  {
    cout << "Database error. Exiting.." << endl;
    exit(0);
  }
}

vector<Reservation> PersistenceService::getReservationsBySurname(string surname)
{
  vector<Reservation> result;
  try
  {
    sql::ResultSet* res = stmt->executeQuery(
      "SELECT * from Reservations where surname like '%" + surname + "%'");

    while (res->next())
    {
      int day, month, year;
      string date_str = res->getString("startDate");
      sscanf_s(date_str.c_str(), "%4d-%2d-%2d", &year, &month, &day);

      result.push_back(Reservation(res->getInt("id"), res->getString("name"), 
        res->getString("surname"), Date(day, month, year), res->getInt("duration"), 
        res->getDouble("cost")));
    }

    return result;
  }
  catch (sql::SQLException& e)
  {
    cout << "Database error. Exiting.." << endl;
    exit(0);
  }
}

void PersistenceService::insertReservation(Reservation& resv)
{
  try
  {
    string query = 
      "insert into Reservations(name, surname, startDate, duration, cost) values('"
      + resv.getName() + "', '" + resv.getSurname() + "', '"
      + resv.getStartDateMysql() + "', " + to_string(resv.getDuration()) + ", "
      + to_string(resv.getCost()) + ")";

    stmt->executeUpdate(query);

    stmt->execute("SET @lastInsertId = LAST_INSERT_ID()");

    vector<Person> persons = resv.getPersons();
    for (int i = 0; i < persons.size(); i++)
    {
      query = "insert into Persons(name, surname, birthYear, reservationId) values('"
        + persons[i].getName() + "', '" + persons[i].getSurname() + "', "
        + to_string(persons[i].getBirthYear()) 
        + ", @lastInsertId )";

      stmt->executeUpdate(query);
    }
    conn->commit();
  }
  catch (sql::SQLException& e)
  {
    conn->rollback();

    cout << "Database error. Exiting.." << endl;
    exit(0);
  }
}