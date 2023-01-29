#include "Plik_1.h"

Plik_1 Plik_1::FromFields(const vector<string>& fields) {
	if (fields.size() != Plik_1::fieldCount) {
		cout << "ERROR Plik_1::FromFields(): invalid fields size";
	}

	Plik_1 record{};
	record.usmer = SvToInt(fields[0]);
	record.medical_unit = SvToInt(fields[1]);
	record.sex = SvToInt(fields[2]);
	record.patient_type = SvToInt(fields[3]);
	record.date_died = fields[4]; // SvToInt uzyte w Date:Set
	record.intubed = SvToInt(fields[5]);
	record.pneumonia = SvToInt(fields[6]);
	record.age = SvToInt(fields[7]);
	record.pregnant = SvToInt(fields[8]);
	record.diabetes = SvToInt(fields[9]);
	record.copd = SvToInt(fields[10]);
	record.asthma = SvToInt(fields[11]);
	record.inmsupr = SvToInt(fields[12]);
	record.hipertension = SvToInt(fields[13]);
	record.other_disease = SvToInt(fields[14]);
	record.cardiovascular = SvToInt(fields[15]);
	record.obesity = SvToInt(fields[16]);
	record.renal_chronic = SvToInt(fields[17]);
	record.tobacco = SvToInt(fields[18]);
	record.clasiffication_final = SvToInt(fields[19]);
	record.icu = SvToInt(fields[20]);

	return record;
}