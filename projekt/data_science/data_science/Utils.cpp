#include "Utils.h"

#include <ranges>
#include <vector>
#include <charconv>


Date::Date() {
	day = 0;
	month = 0;
	year = 0;
}
Date::Date(const string dateStr) {
	Set(dateStr);
}
Date& Date::operator=(const string dateStr) {
	Set(dateStr);
	return *this;
}
 // sprawdzamy czy zapis daty jest poprawny 2 znaki na dzieñ , 2 na miesiac, 4 na rok i 2 separatory;
void Date::Set(const string dateStr) {
	if (dateStr.size() != 10)
	{
		cout << "ERROR! Invalid date format( "<< dateStr <<") \n";
		day = 0;
		month = 0;
		year = 0;
	}

	//sprawdzamy jaki mamy delimiter do daty i czy trzeba go zmienic 
	char delimiter = '/';
	if (dateStr.find('-') != string::npos) {
		delimiter = '-';
	}
	//dzielimy ciag znaków przy uzyciu separatora i zapisujemy w wektorze 
	auto split = dateStr | views::split(delimiter);
	vector<string> dateElems{};
	for (const auto& elem : split) {
		dateElems.push_back({ elem.begin(), elem.end() });
	}
	if (dateElems.size() != 3) {
		cout << "ERROR! Invalid date format( " << dateStr << ") \n";
		day = 0;
		month = 0;
		year = 0;
	}
	//12/06/2020 txt
	if (delimiter == '/') {
		day = SvToInt(dateElems[0]);
		month = SvToInt(dateElems[1]);
		year = SvToInt(dateElems[2]);
	}
	//2021-05-11 json
	else if (delimiter == '-') {
		day = SvToInt(dateElems[2]);
		month = SvToInt(dateElems[1]);
		year = SvToInt(dateElems[0]);
	}

}
template<typename T>
T SvToT(const string sv) {
	T i{}; //konstruktor domyslny 
	auto resultYear = from_chars(sv.data(), sv.data() + sv.size(), i);
	if (resultYear.ec == errc::invalid_argument) {
		cout << "ERROR! Could not convert ( " << sv << " ) to an int.\n";
	}
	return i;
}

double SvToDouble(const string sv) {
	return SvToT<double>(sv);
}
int SvToInt(const string sv) {
	return SvToT<int>(sv);
}
// rysowanie wykresów za pomoca gnuplot
void PlotData(const vector<int>& data) {
	FILE* pipe = _popen("gnuplot", "w");
	if (pipe == nullptr) {
		cout << "ERROR _popen() returned a nullptr";
	}

	fprintf(pipe, "set term wx\n");
	fprintf(pipe, "plot '-' with lines\n");

	for (const auto& elem : data) {
		fprintf(pipe, "%d\n", elem);
	}

	fprintf(pipe, "%s\n", "e");
	fflush(pipe); // przesy³anie danych do gnuplota 

	// naciœnij klawisz aby kontynuowaæ
	cin.clear();
	cin.get();

	_pclose(pipe);
}