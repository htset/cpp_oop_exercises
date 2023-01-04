#include "DBService.h"

DBService::DBService()
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

vector<TaxDeclaration> DBService::getTaxDeclarations(string vat = "", int year = 0)
{
  vector<TaxDeclaration> result;
  try
  {
    string query = "SELECT * from TaxDeclarations";
    if (vat != "")
    {
      if (year != 0)
        query += " WHERE vat = '" + vat + "' and submissionYear=" + to_string(year);
      else
        query += " WHERE vat = '" + vat + "' ";
    }
    else
    {
      if (year != 0)
        query += " WHERE submissionYear=" + to_string(year);
    }

    sql::ResultSet* res = stmt->executeQuery(query);
    sql::Statement* newStmt = conn->createStatement();
    sql::Statement* newStmt2 = conn->createStatement();
    while (res->next())
    {
      TaxDeclaration td(res->getInt("id"), 
        res->getString("name"), 
        res->getString("surname"),
        res->getString("vat"), 
        res->getString("phone"), 
        res->getInt("submissionYear"));

      sql::ResultSet* newRes = newStmt->executeQuery(
        "SELECT * from Apartments where taxDeclarationId="
        + to_string(res->getInt("id")));
      while (newRes->next())
      {
        sql::ResultSet* newRes2 = newStmt2->executeQuery(
          "SELECT * from Addresses where propertyId="
          + to_string(newRes->getInt("id")));

        if (newRes2->next())
        {
          Address a(newRes2->getString("street"), 
            newRes2->getString("number"),
            newRes2->getString("zip"), 
            newRes2->getString("city"));

          Apartment* temp = new Apartment(newRes->getInt("id"), 
            newRes->getInt("surface"),
            a, 
            newRes->getInt("floor"));

          td.addProperty(temp);
        }
        else
        {
          cout << "error";
          exit(0);
        }
      }

      newRes = newStmt->executeQuery(
        "SELECT * from Stores where taxDeclarationId="
        + to_string(res->getInt("id")));
      while (newRes->next())
      {
        sql::ResultSet* newRes2 = newStmt2->executeQuery(
          "SELECT * from Addresses where propertyId="
          + to_string(newRes->getInt("id")));

        if (newRes2->next())
        {
          Address a(newRes2->getString("street"), 
            newRes2->getString("number"),
            newRes2->getString("zip"), 
            newRes2->getString("city"));

          Store* temp = new Store(newRes->getInt("id"), 
            newRes->getInt("surface"),
            a, 
            newRes->getInt("commerciality"));

          td.addProperty(temp);
        }
        else
        {
          cout << "error";
          exit(0);
        }

      }

      newRes = newStmt->executeQuery(
        "SELECT * from Plots where taxDeclarationId="
        + to_string(res->getInt("id")));
      while (newRes->next())
      {
        sql::ResultSet* newRes2 = newStmt2->executeQuery(
          "SELECT * from Addresses where propertyId="
          + to_string(newRes->getInt("id")));

        if (newRes2->next())
        {
          Address a(newRes2->getString("street"), 
            newRes2->getString("number"),
            newRes2->getString("zip"), 
            newRes2->getString("city"));

          Plot* temp = new Plot(newRes->getInt("id"), 
            newRes->getInt("surface"),
            a, 
            newRes->getInt("cultivated"), 
            newRes->getInt("withinCityLimits"));

          td.addProperty(temp);
        }
        else
        {
          cout << "error";
          exit(0);
        }

      }
      result.push_back(td);
    }

    return result;
  }
  catch (sql::SQLException& e)
  {
    cout << "Database error. Exiting.." << endl;
    exit(0);
  }
}

void DBService::insertTaxDeclaration(TaxDeclaration td)
{
  try
  {
    string query =
      "insert into TaxDeclarations(name, surname, vat, phone, submissionYear) values('"
      + td.getName() + "', '" + td.getSurname() + "', '"
      + td.getVat() + "', '" + td.getPhone() + "', " 
      + to_string(td.getSubmissionYear()) + ")";

    stmt->executeUpdate(query);

    stmt->execute("SET @lastInsertId = LAST_INSERT_ID()");

    vector<Property*> properties = (*td.getProperties());
    for (int i = 0; i < properties.size(); i++)
    {
      cout << typeid(properties[i]).name() << endl;
      cout << typeid(*(properties[i])).name() << endl;
      if (strstr(typeid(*(properties[i])).name(), "Apartment") != NULL)
      {
        Apartment* temp = (Apartment*)properties[i];
        query = "insert into Apartments(surface, floor, taxDeclarationId) values("
          + to_string(temp->getSurface()) + ", " + to_string(temp->getFloor())
          + ", @lastInsertId)";

        stmt->executeUpdate(query);

        stmt->execute("SET @lastInsertPropertyId = LAST_INSERT_ID()");

        query =
          "insert into Addresses(street, number, zip, city, propertyId) values('"
          + temp->getAddress().getStreet() + "', '" 
          + temp->getAddress().getNumber() + "', '"
          + temp->getAddress().getZip() + "', '" 
          + temp->getAddress().getCity()
          + "', @lastInsertPropertyId)";

        stmt->executeUpdate(query);
      }
      if (strstr(typeid(*(properties[i])).name(), "Store") != NULL)
      {
        Store* temp = (Store*)properties[i];
        query = "insert into Stores(surface, commerciality, taxDeclarationId) values("
          + to_string(temp->getSurface()) + ", " + to_string(temp->getCommerciality())
          + ", @lastInsertId)";

        stmt->executeUpdate(query);

        stmt->execute("SET @lastInsertPropertyId = LAST_INSERT_ID()");

        query =
          "insert into Addresses(street, number, zip, city, propertyId) values('"
          + temp->getAddress().getStreet() + "', '" 
          + temp->getAddress().getNumber() + "', '"
          + temp->getAddress().getZip() + "', '" 
          + temp->getAddress().getCity()
          + "', @lastInsertPropertyId)";

        stmt->executeUpdate(query);
      }
      if (strstr(typeid(*(properties[i])).name(), "Plot") != NULL)
      {
        Plot* temp = (Plot*)properties[i];
        query = "insert into Plots(surface, cultivated, withinCityLimits, taxDeclarationId) values("
          + to_string(temp->getSurface()) + ", " + to_string(temp->getCultivated()) + ", "
          + to_string(temp->getWithinCityLimits()) + ", @lastInsertId)";

        stmt->executeUpdate(query);

        stmt->execute("SET @lastInsertPropertyId = LAST_INSERT_ID()");

        query =
          "insert into Addresses(street, number, zip, city, propertyId) values('"
          + temp->getAddress().getStreet() + "', '" 
          + temp->getAddress().getNumber() + "', '"
          + temp->getAddress().getZip() + "', '" 
          + temp->getAddress().getCity()
          + "', @lastInsertPropertyId)";

        stmt->executeUpdate(query);
      }
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

void DBService::removeTaxDeclaration(TaxDeclaration td)
{
  try
  {
    string query =
      "delete from Addresses where propertyId in (select id from Apartments where taxDeclarationId = "
      + to_string(td.getId()) + ")";
    stmt->executeUpdate(query);
    query =
      "delete from Apartments where taxDeclarationId = " + to_string(td.getId());
    stmt->executeUpdate(query);

    query =
      "delete from Addresses where propertyId in (select id from Stores where taxDeclarationId = "
      + to_string(td.getId()) + ")";
    stmt->executeUpdate(query);
    query =
      "delete from Stores where taxDeclarationId = " + to_string(td.getId());
    stmt->executeUpdate(query);

    query =
      "delete from Addresses where propertyId in (select id from Plots where taxDeclarationId = "
      + to_string(td.getId()) + ")";
    stmt->executeUpdate(query);
    query =
      "delete from Plots where taxDeclarationId = " + to_string(td.getId());
    stmt->executeUpdate(query);

    query =
      "delete from TaxDeclarations where id = " + to_string(td.getId());
    stmt->executeUpdate(query);
  }
  catch (sql::SQLException& e)
  {
    conn->rollback();

    cout << "Database error. Exiting.." << endl;
    exit(0);
  }
}


