#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "json.h"
#include "Utils.h"

class Plik_3 {
public:
  
   static Plik_3 FromJson(nlohmann::json json);

   string country;

   int new_deaths;
   
};