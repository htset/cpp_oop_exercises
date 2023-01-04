#include "Apartment.h"
#include "Reservation.h"
#include "Date.h"
#include "Person.h"
#include "PersistenceService.h"
#include "UIService.h"

int main()
{
	PersistenceService ps;
	UIService ui(&ps);
	ui.menu();
}

