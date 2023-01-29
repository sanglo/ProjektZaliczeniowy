#include "Plik_2.h"

Plik_2 Plik_2::FromFields(const vector<string>& fields) {

		if (fields.size() != Plik_2::fieldCount) {
			cout<<"[ERROR] Record_1::FromFields(): invalid fields size";
		}

		Plik_2 record{};

		record.fever = SvToInt(fields[0]);
		record.tiredness = SvToInt(fields[1]);
		record.dryCough = SvToInt(fields[2]);
		record.difficultyInBreathing = SvToInt(fields[3]);
		record.soreThroat = SvToInt(fields[4]);
		record.none_sympton = SvToInt(fields[5]);
		record.pains = SvToInt(fields[6]);
		record.nasalCongestion = SvToInt(fields[7]);
		record.runnyNose = SvToInt(fields[8]);
		record.diarrhea = SvToInt(fields[9]);
		record.none_experiencing = SvToInt(fields[10]);
		record.age_0_9 = SvToInt(fields[11]);
		record.age_10_19 = SvToInt(fields[12]);
		record.age_20_24 = SvToInt(fields[13]);
		record.age_25_59 = SvToInt(fields[14]);
		record.age_60plus = SvToInt(fields[15]);
		record.gender_female = SvToInt(fields[16]);
		record.gender_male = SvToInt(fields[17]);
		record.gender_transgender = SvToInt(fields[18]);
		record.severity_mild = SvToInt(fields[19]);
		record.severity_moderate = SvToInt(fields[20]);
		record.severity_none = SvToInt(fields[21]);
		record.severity_severe = SvToInt(fields[22]);
		record.contact_DontKnow = SvToInt(fields[23]);
		record.contact_No = SvToInt(fields[24]);
		record.contact_Yes = SvToInt(fields[25]);
		record.country = fields[26];

		return record;
}