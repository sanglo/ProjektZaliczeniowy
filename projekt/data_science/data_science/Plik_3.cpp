#include "Plik_3.h"

Plik_3 Plik_3::FromJson(nlohmann::json json) {
   Plik_3 record{};
   record.country = json.at("country").get<string>();
   record.iso_code = json.at("iso_code").get<string>();
   record.date = json.at("date").get<string>();
   record.total_vaccinations = json.at("total_vaccinations").get<int>();
   record.people_vaccinated = json.at("people_vaccinated").get<int>();
   record.people_fully_vaccinated = json.at("people_fully_vaccinated").get<int>();
   record.new_deaths = json.at("New_deaths").get<int>();
   record.population = json.at("population").get<int>();
   record.ratio = json.at("ratio").get<float>();

   return record;
}