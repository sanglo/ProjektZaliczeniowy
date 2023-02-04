#include "Plik_3.h"
//biblioteka nlohmann::json
Plik_3 Plik_3::FromJson(nlohmann::json json) {
   Plik_3 record{};
   record.country = json.at("country").get<string>();
  
   record.new_deaths = json.at("New_deaths").get<int>();

   return record;
}