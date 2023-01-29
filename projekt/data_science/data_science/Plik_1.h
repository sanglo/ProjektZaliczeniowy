#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "Utils.h"
using namespace std;

class Plik_1 {
private:
	Plik_1() = default;
public:
	static const int fieldCount = 21;
	static Plik_1 FromFields(const vector<string>& fields);


	int usmer;
	int medical_unit;
	int sex;
	int patient_type;
	Date date_died;
	int intubed;
	int pneumonia;
	int age;
	int pregnant;
	int diabetes;
	int copd;
	int asthma;
	int inmsupr;
	int hipertension;
	int other_disease;
	int cardiovascular;
	int obesity;
	int renal_chronic;
	int tobacco;
	int clasiffication_final;
	int icu;
};