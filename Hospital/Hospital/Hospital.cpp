#include "Patient.h"

vector<Patient> patients;

int main()
{
  Clinic c1("Surgery", "A. Dobbs");
  Clinic c2("Cardiology", "B. Smith");
  Clinic c3("Orthopedics", "C. Stubbs");

  Patient p1("John", "Doe", 1970, &c1, "303");
  Patient p2("Jane", "Doe", 1985, &c2, "306");
  Patient p3("Jimmy", "Doe", 1956, &c2, "306");

  p1.insertMeasurement(Measurement(37.5, "01/01/2023 00:00"));
  p1.insertMeasurement(Measurement(38.1, "01/01/2023 06:00"));
  p1.insertMeasurement(Measurement(37.9, "01/01/2023 09:00"));

  p2.insertMeasurement(Measurement(36.5, "01/01/2023 00:00"));
  p2.insertMeasurement(Measurement(38.0, "01/01/2023 06:00"));

  p3.insertMeasurement(Measurement(39.5, "01/01/2023 00:00"));
  p3.insertMeasurement(Measurement(39.1, "01/01/2023 06:00"));

  p3.setClinic(&c3);
  c1.setDirector("D. Jones");

  p1.display();
  p2.display();
  p3.display();
}
