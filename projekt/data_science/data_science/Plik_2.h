#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "Utils.h"

struct Plik_2{

	static const uint32_t fieldCount = 27;
	static Plik_2 FromFields(const vector<string>& fields);
private:
	Plik_2() = default;
public:
	int fever;
	int tiredness;
	int dryCough;
	int difficultyInBreathing;
	int soreThroat;
	int none_sympton;
	int pains;
	int nasalCongestion;
	int runnyNose;
	int diarrhea;
	int none_experiencing;
	int age_0_9;
	int age_10_19;
	int age_20_24;
	int age_25_59;
	int age_60plus;
	int gender_female;
	int gender_male;
	int gender_transgender;
	int severity_mild;
	int severity_moderate;
	int severity_none;
	int severity_severe;
	int contact_DontKnow;
	int contact_No;
	int contact_Yes;
	string country;
};