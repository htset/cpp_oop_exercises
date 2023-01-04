#include "UIService.h"
UIService::UIService(PersistenceService* _ps)
{
  ps = _ps;
}

void UIService::menu()
{
  int option;
  do
  {
    cout << "Options: " << endl;
    cout << "1) Add reservation " << endl;
    cout << "2) Search reservation " << endl;
    cout << "3) View all reservations " << endl;
    cout << "0) Exit " << endl;
    cout << "Enter your selection:";
    cin >> option;
    cin.ignore();

    switch (option)
    {
    case 1:
      addReservation();
      break;
    case 2:
      searchReservation();
      break;
    case 3:
      listReservations();
      break;
    case 0:
      break;
    default:
      cout << "Please enter selection again:";
      break;
    }
  } while (option != 0);
}

void UIService::addReservation()
{
  int option;
  string name, surname, startDateStr;
  int duration, day, month, year;

  cout << "Name: ";
  getline(cin, name);

  cout << "Surname: ";
  getline(cin, surname);

  cout << "Start date: ";
  getline(cin, startDateStr);
  sscanf_s(startDateStr.c_str(), "%2d/%2d/%4d", &day, &month, &year);
  Date startDate(day, month, year);
  
  cout << "Duration: ";
  cin >> duration;
  cin.ignore();

  cout << "Available apartments:" << endl;
  vector<Apartment> apartments = ps->getApartments();
  for (int i = 0; i < apartments.size(); i++)
  {
    cout << "Apartment no." << i + 1 << ":" << endl;
    cout << apartments[i].toString() << endl;
  }
  cout << "Press 0 to cancel:";
  cin >> option;
  cin.ignore();

  if (option > 0 and option <= apartments.size())
  {
    Reservation resv(0, name, surname, startDate, duration, 
      apartments[option-1].getPrice());
    addPersons(&resv);    
    ps->insertReservation(resv);
  }

}

void UIService::addPersons(Reservation *resv)
{
  string name, surname, selection;
  int birthYear;

  cout << "Give the persons:" << endl;
  do
  {
    cout << "Name: ";
    getline(cin, name);
    cout << "Surname: ";
    getline(cin, surname);
    cout << "Birth Year: ";
    cin >> birthYear;
    cin.ignore();

    resv->addPerson(Person(0, name, surname, birthYear));

    cout << "Add another person? (y/n)" << endl;
    getline(cin, selection);
  } while (selection != "n" && selection != "N");
}

void UIService::searchReservation()
{
  string surname;
  cout << "Enter surname (also partial): ";
  getline(cin, surname);
  vector<Reservation> reservations = ps->getReservationsBySurname(surname);

  for (int i = 0; i < reservations.size(); i++)
  {
      cout << reservations[i].toString();
  }
}

void UIService::listReservations()
{
  vector<Reservation> reservations = ps->getAllReservations();
  for (int i = 0; i < reservations.size(); i++)
  {
    cout << reservations[i].toString();
  }
}