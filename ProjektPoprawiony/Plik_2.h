#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "Utils.h"

class Plik_2{

private:
	Plik_2() = default;
public:
	static Plik_2 FromFields(const vector<string>& fields);
	int fever;
	int nasalCongestion;
	int age_10_19;

};