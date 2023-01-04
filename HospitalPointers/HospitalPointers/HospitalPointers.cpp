#include <iostream>
#include "Patient.h"

int main()
{
  Clinic c1("Surgery", "A. Dobbs");
  Clinic c2("Cardiology", "B. Smith");
  Clinic c3("Orthopedics", "C. Stubbs");

  Patient p[3];
  p[0] = Patient("John", "Doe", 1970, &c1, "303");
  p[1] = Patient("Jane", "Doe", 1985, &c2, "306");
  p[2] = Patient("Jimmy", "Doe", 1956, &c2, "306");

  p[0].insertMeasurement(Measurement(37.5, "01/01/2023 00:00"));
  p[0].insertMeasurement(Measurement(38.1, "01/01/2023 06:00"));
  p[0].insertMeasurement(Measurement(37.9, "01/01/2023 09:00"));

  p[1].insertMeasurement(Measurement(36.5, "01/01/2023 00:00"));
  p[1].insertMeasurement(Measurement(38.0, "01/01/2023 06:00"));

  p[2].insertMeasurement(Measurement(39.5, "01/01/2023 00:00"));
  p[2].insertMeasurement(Measurement(39.1, "01/01/2023 06:00"));

  p[2].setClinic(&c3);
  c1.setDirector("D. Jones");

  for (int i = 0; i < 3; i++)
    p[i].display();
}
