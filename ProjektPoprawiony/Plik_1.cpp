#include "Plik_1.h"

Plik_1 Plik_1::FromFields(const vector<string>& fields) {
	
	Plik_1 record{};
	record.pneumonia = StrToInt(fields[6]);
	record.age = StrToInt(fields[7]);
	
	return record;
}