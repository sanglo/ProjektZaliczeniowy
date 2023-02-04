#include "Plik_2.h"

Plik_2 Plik_2::FromFields(const vector<string>& fields) {


		Plik_2 record{};

		record.fever = StrToInt(fields[0]);
		record.nasalCongestion = StrToInt(fields[7]);
		record.age_10_19 = StrToInt(fields[12]);
		

		return record;
}