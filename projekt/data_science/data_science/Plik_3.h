#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "json.h"
#include "Utils.h"

class Plik_3 {
public:
   static const int fieldCount = 10;
   static Plik_3 FromJson(nlohmann::json json);

   string country;
   string iso_code;
   Date date;
   int total_vaccinations;
   int people_vaccinated;
   int people_fully_vaccinated;
   int new_deaths;
   int population;
   double ratio;
};